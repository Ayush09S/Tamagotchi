#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// --- Pin Definitions ---
// Buttons
#define Btn_Left 9        // SW1 -> GPIO9
#define Btn_Mid_Left 8    // SW2 -> GPIO8
#define Btn_Mid_Right 20  // SW3 -> GPIO20
#define Btn_Right 21      // SW4 -> GPIO21

// Power Button (Momentary)
#define Power_Btn 4  // SW5 -> GPIO4

// I2C OLED
#define SdaPin 6  // OLED SDA -> GPIO6
#define SclPin 7  // OLED SCL -> GPIO7

// Buzzer
#define Buzzer_Pin 10  // Buzzer signal -> GPIO10

// --- Display Setup ---
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// --- Pet Logic ---
struct Pet {
  int hunger;         // 0 to 100 (0 = starving, 100 = full)
  int happiness;      // 0 to 100 (0 = miserable, 100 = ecstatic)
  int energy;         // 0 to 100 (0 = exhausted, 100 = fully rested)
  unsigned long age;  // total seconds the pet has been alive
};

Pet pet;

enum Screen {
  SCREEN_MAIN,
  SCREEN_FEED,
  SCREEN_PLAY,
  SCREEN_SLEEP,
  SCREEN_JUMP
};

Screen currentScreen = SCREEN_MAIN;

unsigned long screenEnteredAt = 0;
bool actionApplied = false;
unsigned long lastUpdate = 0;

// Level GPIO4 reads when the switch is in the OFF position.
// Flip this to HIGH if it's backwards on your board.
#define POWER_OFF_LEVEL LOW

void checkPowerButton() {
  if (digitalRead(Power_Btn) != POWER_OFF_LEVEL) return;  // switch is ON, carry on

  delay(50);
  if (digitalRead(Power_Btn) != POWER_OFF_LEVEL) return;  // bounce, ignore

  display.clearDisplay();
  display.display();
  display.ssd1306_command(SSD1306_DISPLAYOFF);

  // Wake on the opposite level to the one we're sleeping at
  gpio_wakeup_enable(GPIO_NUM_4,
    POWER_OFF_LEVEL == LOW ? GPIO_INTR_HIGH_LEVEL : GPIO_INTR_LOW_LEVEL);
  esp_sleep_enable_gpio_wakeup();
  esp_light_sleep_start();

  // --- resumes here when the switch is flipped back ON ---
  delay(50);
  display.ssd1306_command(SSD1306_DISPLAYON);
  lastUpdate = millis();
}

void setup() {
  Serial.begin(115200);

  pinMode(Btn_Left, INPUT_PULLUP);
  pinMode(Btn_Mid_Left, INPUT_PULLUP);
  pinMode(Btn_Mid_Right, INPUT_PULLUP);
  pinMode(Btn_Right, INPUT_PULLUP);
  pinMode(Buzzer_Pin, OUTPUT);
  pinMode(Power_Btn, INPUT_PULLUP);

  // Initialize I2C with the specific pins for the schematic
  Wire.begin(SdaPin, SclPin);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);

  display.println("Tamagotchi says...");
  display.display();
  delay(1000);

  display.println("Hello World!");
  display.display();
  delay(1000);

  pet.hunger = 80;
  pet.happiness = 80;
  pet.energy = 80;
  pet.age = 0;
}


void updatePet() {
  if (millis() - lastUpdate > 5000) {  // every 5 seconds
    pet.hunger--;
    pet.happiness--;
    pet.energy--;

    if (pet.hunger < 0) pet.hunger = 0;
    if (pet.happiness < 0) pet.happiness = 0;
    if (pet.energy < 0) pet.energy = 0;

    pet.age += 5;
    lastUpdate = millis();
  }
}

unsigned long lastButtonPress = 0;

void checkButtons() {
  if (millis() - lastButtonPress < 200) return;  // debounce: ignore presses within 200ms

  if (digitalRead(Btn_Left) == LOW) {
    currentScreen = SCREEN_FEED;
    tone(Buzzer_Pin, 1000, 50);
    lastButtonPress = millis();
    screenEnteredAt = millis();
    actionApplied = false;
  } else if (digitalRead(Btn_Mid_Left) == LOW) {
    currentScreen = SCREEN_PLAY;
    tone(Buzzer_Pin, 1200, 50);
    lastButtonPress = millis();
    screenEnteredAt = millis();
    actionApplied = false;
  } else if (digitalRead(Btn_Mid_Right) == LOW) {
    currentScreen = SCREEN_JUMP;
    tone(Buzzer_Pin, 1200, 50);
    lastButtonPress = millis();
    screenEnteredAt = millis();
    actionApplied = false;
  } else if (digitalRead(Btn_Right) == LOW) {
    currentScreen = SCREEN_SLEEP;
    tone(Buzzer_Pin, 800, 50);
    lastButtonPress = millis();
    screenEnteredAt = millis();
    actionApplied = false;
  }
}

void handleScreenLogic() {
  if (actionApplied) {
      if (millis() - screenEnteredAt > 800){
        currentScreen = SCREEN_MAIN;
      }
      return;
  }

  switch (currentScreen) {

    case SCREEN_FEED:
      pet.hunger += 10;
      if (pet.hunger > 100) pet.hunger = 100;
      break;

    case SCREEN_PLAY:
      pet.happiness += 10;
      pet.energy -= 5;
      if (pet.happiness > 100) pet.happiness = 100;
      if (pet.energy < 0) pet.energy = 0;
      break;

    case SCREEN_JUMP:
      pet.happiness += 20;
      pet.energy -= 10;
      if (pet.happiness > 100) pet.happiness = 100;
      if (pet.energy < 0) pet.energy = 0;
      break;

    case SCREEN_SLEEP:
      pet.energy += 15;
      if (pet.energy > 100) pet.energy = 100;
      break;

    case SCREEN_MAIN:
      break;  // do nothing, just display stats
  }

  actionApplied = true;
}

// Stat Happy (Happiness > 40)
const unsigned char PROGMEM petHappy[] = {
  0b00000000, 0b00000000,
  0b00000111, 0b11100000,
  0b00011000, 0b00011000,
  0b00100000, 0b00000100,
  0b01000100, 0b00100010,
  0b01000000, 0b00000010,
  0b01010000, 0b00001010,
  0b01001000, 0b00010010,
  0b00100111, 0b11100100,
  0b00100000, 0b00000100,
  0b00011111, 0b11111000,
  0b00000010, 0b01000000,
  0b00000010, 0b01000000,
  0b00000010, 0b01000000,
  0b00001110, 0b01110000,
  0b00000000, 0b00000000
};

// Stat Jump
const unsigned char PROGMEM petJump[] = {
  0b00000000, 0b00000000,
  0b00000111, 0b11100000,
  0b00011000, 0b00011000,
  0b00100000, 0b00000100,
  0b01000100, 0b00100010,
  0b01000000, 0b00000010,
  0b01010000, 0b00001010,
  0b01001000, 0b00010010,
  0b00100111, 0b11100100,
  0b00100000, 0b00000100,
  0b00011111, 0b11111000,
  0b00000010, 0b01000000,
  0b00001110, 0b01110000,
  0b00000000, 0b00000000,
  0b00000000, 0b00000000,
  0b00000000, 0b00000000
};

// Stat Sad (Happiness <= 40)
const unsigned char PROGMEM petSad[] = {
  0b00000000, 0b00000000,
  0b00000111, 0b11100000,
  0b00011000, 0b00011000,
  0b00100000, 0b00000100,
  0b01000100, 0b00100010,
  0b01000100, 0b00100010,
  0b01000000, 0b00000010,
  0b01000111, 0b11100010,
  0b00101000, 0b00010100,
  0b00100000, 0b00000100,
  0b00011111, 0b11111000,
  0b00000010, 0b01000000,
  0b00000010, 0b01000000,
  0b00000010, 0b01000000,
  0b00001110, 0b01110000,
  0b00000000, 0b00000000
};

// Stat Neutral
const unsigned char PROGMEM petNeutral[] = {
  0b00000000, 0b00000000,
  0b00000111, 0b11100000,
  0b00011000, 0b00011000,
  0b00100000, 0b00000100,
  0b01000100, 0b00100010,
  0b01000000, 0b00000010,
  0b01000000, 0b00000010,
  0b01001000, 0b00010010,
  0b00100111, 0b11100100,
  0b00100000, 0b00000100,
  0b00011111, 0b11111000,
  0b00000010, 0b01000000,
  0b00000010, 0b01000000,
  0b00000010, 0b01000000,
  0b00001110, 0b01110000,
  0b00000000, 0b00000000
};

// Stat Sleeping
const unsigned char PROGMEM petSleep[] = {
  0b00000000, 0b00000000,
  0b00000111, 0b11100000,
  0b00011000, 0b00011000,
  0b00100000, 0b00000100,
  0b01000100, 0b00100010,
  0b01001110, 0b01110010,
  0b01000100, 0b00100010,
  0b01000000, 0b00000010,
  0b00100111, 0b11100100,
  0b00100000, 0b00000100,
  0b00011111, 0b11111000,
  0b00000010, 0b01000000,
  0b00000010, 0b01000000,
  0b00000010, 0b01000000,
  0b00001110, 0b01110000,
  0b00000000, 0b00000000
};

// Stat Sleeping
const unsigned char PROGMEM petTired[] = {
  0b00000000, 0b00000000,
  0b00000111, 0b11100000,
  0b00011000, 0b00011000,
  0b00100000, 0b00000100,
  0b01000100, 0b00100010,
  0b01001010, 0b01010010,
  0b01000100, 0b00100010,
  0b01000000, 0b00000010,
  0b00100111, 0b11100100,
  0b00100000, 0b00000100,
  0b00011111, 0b11111000,
  0b00000010, 0b01000000,
  0b00000010, 0b01000000,
  0b00000010, 0b01000000,
  0b00001110, 0b01110000,
  0b00000000, 0b00000000
};

const unsigned char PROGMEM petHungry[] = {
  0b00000000, 0b00000000,
  0b00000111, 0b11100000,
  0b00011000, 0b00011000,
  0b00100000, 0b00000100,
  0b01000100, 0b00100010,
  0b01000000, 0b00000010,
  0b01011111, 0b11111010,
  0b01000000, 0b11100010,
  0b00100000, 0b11000100,
  0b00100000, 0b00000100,
  0b00011111, 0b11111000,
  0b00000010, 0b01000000,
  0b00000010, 0b01000000,
  0b00000010, 0b01000000,
  0b00001110, 0b01110000,
  0b00000000, 0b00000000
};

void render() {
  display.clearDisplay();

  // Choose the right sprite based on pet stats
  const unsigned char* sprite;
  if (currentScreen == SCREEN_JUMP)
  {
    sprite = petJump;
  } 
  else if (currentScreen == SCREEN_SLEEP)
  {
    sprite = petSleep;
  }
  else if (pet.happiness < 30 || pet.energy < 30)
  {
    sprite = petSad;
  } 
  else if (pet.hunger > 50 && pet.happiness > 50 && pet.energy > 50) 
  {
    sprite = petHappy;
  } 
  else if (pet.hunger < 30) 
  {
    sprite = petHungry;
  } 
  else 
  {
    sprite = petNeutral;
  }

  // Draw the pet sprite (centered horizontally, near the top)
  display.drawBitmap(56, 2, sprite, 16, 16, SSD1306_WHITE);

  // Draw stat bars below the pet
  display.setTextSize(1);

  display.setCursor(0, 24);
  display.print("HUN ");
  drawBar(24, 24, pet.hunger);

  display.setCursor(0, 34);
  display.print("HAP ");
  drawBar(24, 34, pet.happiness);

  display.setCursor(0, 44);
  display.print("ENG ");
  drawBar(24, 44, pet.energy);

  // Button labels at the bottom
  display.setCursor(0, 56);
  display.println("Play Jump Sleep Feed");

  display.display();
}

// Draws a stat bar: empty rectangle with a filled portion based on value (0 to 100)
void drawBar(int x, int y, int value) {
  int barWidth = 100;
  int barHeight = 6;
  int fillWidth = map(value, 0, 100, 0, barWidth);

  display.drawRect(x, y, barWidth, barHeight, SSD1306_WHITE);   // outline
  display.fillRect(x, y, fillWidth, barHeight, SSD1306_WHITE);  // filled portion
}

void loop() {
  checkPowerButton();   // 1. Check for momentary sleep press
  checkButtons();       // 2. Read input
  updatePet();          // 3. Update state over time
  handleScreenLogic();  // 4. Process actions
  render();             // 5. Display results
  delay(100);           // 6. Short pause
}