# Overview
A small digital pet as a physical device remake! It features four buttons and a buzzer. It also has an OLED display and can be recharged! The coding is made so that it can show it's emotions based on how it's treated. Whether it's not played with, not given sleep, it'll react. Make sure to keep it entertained! It also can be powered off into deep sleep in case you are busy and need to temporarily turn it off.

## Context
It was created as an entry to contribute to the Fallout Hackathon in Shenzhen run by Hack Club! It was quite involved, requiring the research of components, importing the EasyEda JLCPCB library of components library into Kicad, and properly understanding how to make a schematic and routing a PCB. It can also be used with both smaller LiPo batteries and medium sized ones too! It took 35+ hours to complete. I was really glad the coding was not crazy complicated!

## Zine
<img width="539" height="827" alt="Tamagotchi Zine" src="https://github.com/user-attachments/assets/9c71413b-636d-4bb1-a0b6-0be46c33ab1f" />

# Specs
- 4 Push Buttons
- Latching Power Switch
- OLED screen

# How To Create
1. Create the PCB
  - Either cut the PCB (with the Gerber file) and solder bought components needed (found in the BOM)
    OR
  - Buy the PCB from JLCPCB

2. Print the models
  - Print the Casing, spacers and battery holder lid with the 3D Files provided on a 3D Printer (Note, the casing top, casing bottom, spacers and battery holder lid should all be printed seperately)
    OR
  - Buy the Casing printed from a printing service

3. Put it together
  - Put a bought or owned LiPo Battery and connect it to the bottom of the pcb, and place it into the allocated space in the casing
  - Use M3 Screws (buy or use owned ones) to screw the casing and PCB together

5. Program the PCB. (Sourced from [Tamagotchi Firmware Tutorial](https://fallout.hackclub.com/docs/guided-projects/tamagotchi-firmware#step-1-install-the-esp32-board-package))
  - Connect to the Tamagotchi's USB-C connector through a computer and apply the program provided through the Arduino IDE.
  - Make sure to downlooad to follow the steps below to get the correct libraries.
    
  - Open the Arduino IDE.
  - Go to File > Preferences (or Arduino IDE > Settings on macOS).
  - In the "Additional Boards Manager URLs" field, add the following URL: https://espressif.github.io/arduino-esp32/package_esp32_index.json > Note: If you already have URLs here, separate entries with commas.
  - Click OK to save the preferences.
  - Wait for the board index to download.

  - Open the Boards Manager by navigating to Tools > Board > Boards Manager.
  - In the search bar, type esp32.
  - Locate the entry for "esp32 by Espressif Systems".
  - Click the Install button. > Important: Ensure you are using version 3.0.0 or later, which supports the C6.
  - Wait for the installation to finish.

  - After installation, go to Tools > Board > esp32.
  - Select your board model: XIAO ESP32C6.

  - In Sketch > Include Library > Manage Libraries, install:
  -   Adafruit SSD1306 (by Adafruit)
  -   Adafruit GFX Library (by Adafruit), which will be prompted as a dependency.

6. Done! Use the Tamagotchi as much as your heart desires!

# PCB
## Board
<img width="948" height="1146" alt="Screenshot 2026-06-22 at 5 34 54 am" src="https://github.com/user-attachments/assets/3b98b6c3-095e-400b-8093-48e99dd624e3" />
<img width="1125" height="1281" alt="Screenshot 2026-06-22 at 5 36 25 am" src="https://github.com/user-attachments/assets/0554ccc6-8fd5-49fe-a2b2-79fb80542644" />

## Schematic
<img width="1523" height="1046" alt="Screenshot 2026-06-22 at 5 36 53 am" src="https://github.com/user-attachments/assets/51373373-ee5f-4509-b84b-8f4f3d6e3525" />

# Casing
Onshape Link (Do not click, copy and paste it): https://cad.onshape.com/documents/55ba759bd32af63245a8fd64/w/0539768004f2bf5a541f17f4/e/c03fca18856a8a03d68f317d?renderMode=0&uiState=6a3838eea6672b7ea1a096e4
## Full
<img width="909" height="1130" alt="Screenshot 2026-06-22 at 5 52 57 am" src="https://github.com/user-attachments/assets/43629c10-62b1-4305-9e82-56be6c0b073a" />

## Top
<img width="1082" height="741" alt="Screenshot 2026-06-20 at 7 29 19 pm" src="https://github.com/user-attachments/assets/42675b54-4750-4153-82db-e5c5054b360d" />
<img width="1032" height="1239" alt="Screenshot 2026-06-20 at 7 29 53 pm" src="https://github.com/user-attachments/assets/8920b4bd-a82e-46c4-91f8-6d4112d9dfdb" />

## Bottom
Highlighted or Orange are the Spacers and Battery Lid
<img width="1059" height="668" alt="Screenshot 2026-06-20 at 7 28 45 pm" src="https://github.com/user-attachments/assets/f2d2a13f-2694-471b-8e28-c6a6e22783a7" />
<img width="957" height="1228" alt="Screenshot 2026-06-20 at 7 28 08 pm" src="https://github.com/user-attachments/assets/2110b6fb-1b31-4e26-af6d-18c35700c7a9" />

# BOM (AUD)
| No. | Item | Description | LCSC/JLCPCB Supplier Number (if applicable) | Qty | Unit Price | Total Price | Running Total | Link |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | 3D Print Filament | Elegoo PLA 1kg | | 1 | $19.95 | $19.95 | $19.95 | [Jaycar Link](https://www.jaycar.com.au/elegoo-pla-filament-brown-1-75mm-1kg/p/TL6415?srsltid=AfmBOorWonBfeYknAu3rB8aZ4PWmGkUiC_A2ZqcdQLrUnSMhugl3tplenB0) |
| 2 | Screws | M3x30mm | | 10 | $0.13 | $1.33 | $21.28 | [Makerstore Link](https://www.makerstore.com.au/product/m3-button-head-screws-10-pack/?attribute_pa_length=30mm&gad_source=1&gad_campaignid=17182175902&gbraid=0AAAAADlKCoO41i4UW2q_vBL5fa-YCVeUE&gclid=CjwKCAjw0dPRBhAPEiwAE5vTTq34nfkNcCYdwuQxhlO7KVYuQOjBWP2bP-eB9npmySPHkssN7rTvphoChtkQAvD_BwE) |
| 3 | Nuts | M3 | | 4 | $0.14 | $0.56 | $21.84 | [Makerstore Link](https://www.makerstore.com.au/product/hard-m3nut-1/?gad_source=1&gad_campaignid=17182175902&gbraid=0AAAAADlKCoO41i4UW2q_vBL5fa-YCVeUE&gclid=CjwKCAjw0dPRBhAPEiwAE5vTTrelUUspWVwynp_Yrg5-H1qjSB5JMoOdUoEGIBlk2bIIMUZF2I_HQxoCLH4QAvD_BwE) |
| 4 | Battery | LiPo Rechargeable 1100mAh | | 1 | $5.39 | $5.39 | $27.23 | [Aliexpress Link](https://www.aliexpress.com/item/1005004824764461.html?src=google&src=google&albch=shopping&acnt=742-864-1166&isdl=y&slnk=&plac=&mtctp=&albbt=Google_7_shopping&aff_platform=google&aff_short_key=UneMJZVf&gclsrc=aw.ds&albagn=888888&ds_e_adid=&ds_e_matchtype=&ds_e_device=c&ds_e_network=x&ds_e_product_group_id=&ds_e_product_id=en1005004824764461&ds_e_product_merchant_id=101188790&ds_e_product_country=AU&ds_e_product_language=en&ds_e_product_channel=online&ds_e_product_store_id=&ds_url_v=2&albcp=21819463808&albag=&isSmbAutoCall=false&needSmbHouyi=false&gad_source=1&gad_campaignid=21819486122&gbraid=0AAAAA99aYpemWq6wRYbZ4iRr7fSZWOlsi&gclid=CjwKCAjw0dPRBhAPEiwAE5vTTuU6XAWeZ3Sbwx140fsltYGE2tlytzKPM_RCD3M4D4ZwK8VsdYguBhoC5kYQAvD_BwE) |
| 5 | PCB (with assembly) | Main board that connects components and holds main chip | | 1 | $23.77 | $23.77 | $51.00 | [JLCPCB Link](https://jlcpcb.com/) |
| 5.1 | Buzzer | BUZ-TH_BD12.5-P6.50-D1.4 | C49246964 | 1 | $0.01 | $0.01 | $51.00 | [JLCPCB Link](https://jlcpcb.com/partdetail/XHXDZ-1207_P65MM/C49246964) |
| 5.2 | Push Buttons | SW-TH_4P-L4.5-W4.5-P3.00-LS4.8 | C2888493 | 4 | $0.01 | $0.04 | $51.00 | [JLCPCB Link](https://jlcpcb.com/partdetail/BZCN-TSC016A04518A/C2888493) |
| 5.3 | Latching Button | SW-TH_TK-6580A-1 | C528770 | 1 | $0.23 | $0.23 | $51.00 | [JLCPCB Link](https://jlcpcb.com/partdetail/Yuandi-TK_6580A1/C528770) |
| 5.4 | OLED Screen | OLED-TH_L27.8-W27.2-P2.54_C9900033791 | C5248080 | 1 | $2.27 | $2.27 | $51.00 | [JLCPCB Link](https://jlcpcb.com/partdetail/HS-HS96L03W2C03/C5248080) |
| 5.5 | Microcontroller | XIAO-ESP32-C3-DIP-SMD | | 1 | $6.55 | $6.55 | $51.00 | [Seeed Studio Link](https://www.seeedstudio.com/Seeed-XIAO-ESP32C3-p-5431.html) |
| 5.6 | Additionals | | | | | $14.67 | $51.00 | |

# Additional Notes!
This was a Guided Project through Hack Club's Fallout's Docs. I really loved making it, and I really learnt a lot, just like with the USB Hub. If you are a beginner, I would suggest starting with a smaller project, but this project is INCREDIBLE as a second one! If you've got some experience programming, you'll definitely find this manageable to create.

Sanity Checked by Kade Harrison
