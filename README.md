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
<img width="992" height="1226" alt="Screenshot 2026-06-20 at 6 42 23 pm" src="https://github.com/user-attachments/assets/775d8cd5-e370-4427-8854-f3a2328bec93" />
<img width="941" height="1160" alt="Screenshot 2026-06-20 at 6 43 25 pm" src="https://github.com/user-attachments/assets/13bb5763-25d0-42aa-bde6-300d23c9eaa3" />

## Schematic
<img width="1531" height="1049" alt="Screenshot 2026-06-19 at 8 36 59 pm" src="https://github.com/user-attachments/assets/c319da14-c750-45f8-966b-430dcc960938" />

# Casing
[Onshape Link](https://cad.onshape.com/documents/55ba759bd32af63245a8fd64/w/ad6807c79dc1dfbda1b36efa/e/c03fca18856a8a03d68f317d?renderMode=0&uiState=6a353a8e2eaad570a6abcbcb)
## Full
<img width="1105" height="765" alt="Screenshot 2026-06-20 at 7 03 44 pm" src="https://github.com/user-attachments/assets/ddc17138-f293-49e2-90bf-794101717508" />

## Top
<img width="1082" height="741" alt="Screenshot 2026-06-20 at 7 29 19 pm" src="https://github.com/user-attachments/assets/42675b54-4750-4153-82db-e5c5054b360d" />
<img width="1032" height="1239" alt="Screenshot 2026-06-20 at 7 29 53 pm" src="https://github.com/user-attachments/assets/8920b4bd-a82e-46c4-91f8-6d4112d9dfdb" />

## Bottom
Highlighted or Orange are the Spacers and Battery Lid
<img width="1059" height="668" alt="Screenshot 2026-06-20 at 7 28 45 pm" src="https://github.com/user-attachments/assets/f2d2a13f-2694-471b-8e28-c6a6e22783a7" />
<img width="957" height="1228" alt="Screenshot 2026-06-20 at 7 28 08 pm" src="https://github.com/user-attachments/assets/2110b6fb-1b31-4e26-af6d-18c35700c7a9" />

# BOM
| No. | Item | Description | LCSC/JLCPCB Supplier Number | Qty | Unit Price | Total Price | Running Total | Link |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | 3D Printer | Bambu X1C AVAILABLE AT SCHOOL | - | 1 | $1,099.00 | $1,099.00 | $1,099.00 | [Mobile Citi Link](https://www.mobileciti.com.au/bambu-lab-x1-carbon-3d-printer-with-ams-refur-excellent) |
| 2 | Screws | M3x30mm | - | 10 | $0.13 | $1.33 | $1,100.33 | [Makerstore Link](https://www.makerstore.com.au/product/m3-button-head-screws-10-pack/) |
| 3 | Nuts | M3 | - | 4 | $0.14 | $0.56 | $1,100.89 | [Makerstore Link](https://www.makerstore.com.au/product/hard-m3nut-1/) |
| 4 | Battery | LiPo Rechargeable 1100mAh | - | 1 | $5.39 | $5.39 | $1,106.28 | [Aliexpress](https://www.aliexpress.com/item/1005004824764461.html) |
| 5 | PCB (with assembly) | Main board that connects components and holds main chip | - | 1 | $23.59 | $23.59 | $1,129.87 | [JLCPCB Link](https://jlcpcb.com/) |
| 5.1 | Buzzer | BUZ-TH_BD12.5-P6.50-D1.4 | C49246964 | 1 | $0.01 | $0.01 | $1,129.87 | [JLCPCB Link](https://jlcpcb.com/partdetail/XHXDZ-1207_P65MM/C49246964) |
| 5.2 | 10kΩ Resistor | RES-TH_BD2.7-L6.2-P10.20-D0.4 | C2903232 | 1 | $0.01 | $0.01 | $1,129.87 | [JLCPCB Link](https://jlcpcb.com/partdetail/VO-MF1_4W_10K_1_ST52/C2903232) |
| 5.3 | Push Buttons | SW-TH_4P-L4.5-W4.5-P3.00-LS4.8 | C2888493 | 4 | $0.01 | $0.04 | $1,129.87 | [JLCPCB Link](https://jlcpcb.com/partdetail/BZCN-TSC016A04518A/C2888493) |
| 5.4 | Latching Button | SW-TH_TK-6580A-1 | C528770 | 1 | $0.23 | $0.23 | $1,129.87 | [JLCPCB Link](https://jlcpcb.com/partdetail/Yuandi-TK_6580A1/C528770) |
| 5.5 | OLED Screen | OLED-TH_L27.8-W27.2-P2.54_C9900033791 | C5248080 | 1 | $2.27 | $2.27 | $1,129.87 | [JLCPCB Link](https://jlcpcb.com/partdetail/HS-HS96L03W2C03/C5248080) |
| 5.6 | Microcontroller | XIAO-ESP32-C3-DIP-SMD | - | 1 | $6.55 | $6.55 | $1,129.87 | [Seeed Studio Link](https://www.seeedstudio.com/Seeed-XIAO-ESP32C3-p-5431.html) |
| 5.7 | Additionals | - | - | - | - | $14.49 | $1,129.87 | - |

# Additional Notes!
This was a Guided Project through Hack Club's Fallout's Docs. I really loved making it, and I really learnt a lot, just like with the USB Hub. If you are a beginner, I would suggest starting with a smaller project, but this project is INCREDIBLE as a second one! If you've got some experience programming, you'll definitely find this manageable to create.

Sanity Checked by Kade Harrison
