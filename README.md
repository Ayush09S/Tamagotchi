# Overview
A small digital pet as a physical device remake! It features four buttons and a buzzer. It also has an OLED display and can be recharged! The coding is made so that it can show it's emotions based on how it's treated. Whether it's not played with, not given sleep, it'll react. Make sure to keep it entertained! It also can be powered off into deep sleep in case you are busy and need to temporarily turn it off.

## Context
It was created as an entry to contribute to the Fallout Hackathon in Shenzhen run by Hack Club! It was quite involved, requiring the research of components, importing the EasyEda JLCPCB library of components library into Kicad, and properly understanding how to make a schematic and routing a PCB. I really liked the idea of a small, hand-held device that you can carry with you, and the idea of a tamagotchi is pretty sweet! It can also be used with both smaller LiPo batteries and medium sized ones too! It took 40+ hours to complete. I was really glad the coding was not crazy complicated!

## Zine
<img width="539" height="827" alt="Tamagotchi-Zine" src="https://github.com/user-attachments/assets/7f9bd80a-40f5-43cd-979c-a7b3817831a9" />

# Specs
- 4 Push Buttons
- Latching Power Switch
- OLED screen

# How To Create
1. Create the PCB
  - Cut the PCB (with the Gerber file) through JLCPCB or a CNC machine and solder bought components needed (found in the BOM)
  - Use the provided files to solder header pins and components in the right places (Onshape link is a good one)

2. Print the models
  - Print the Casing, spacers and battery holder lid with the 3D Files provided on a 3D Printer (Note, the casing top, casing bottom, spacers and battery holder lid should all be printed seperately)
    OR
  - Buy the Casing printed from a printing service

3. Put it together
  - Put a bought or owned LiPo Battery and connect it to the bottom of the pcb, and place it into the allocated space in the casing
  - Use M3 Screws and nuts (buy or use owned ones) to screw the casing and PCB together

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

  - Upload the code!

6. Done! Use the Tamagotchi as much as your heart desires!

# Full Design
<img width="797" height="997" alt="Screenshot 2026-06-22 at 4 22 56 pm" src="https://github.com/user-attachments/assets/e80ab6e9-9c46-4725-8dba-c91a67097b30" />
<img width="1368" height="815" alt="Screenshot 2026-06-22 at 4 29 29 pm" src="https://github.com/user-attachments/assets/cd8ccaa6-319c-4b8b-9a7d-f8631b12904b" />
<img width="956" height="988" alt="Screenshot 2026-06-22 at 4 30 03 pm" src="https://github.com/user-attachments/assets/16452ad7-d4a6-4510-b026-165490db6326" />
<img width="1210" height="1125" alt="Screenshot 2026-06-22 at 4 30 32 pm" src="https://github.com/user-attachments/assets/2f0b1a24-b9e2-40ba-b730-4949e6b02f63" />

# PCB
## Board
<img width="948" height="1146" alt="Screenshot 2026-06-22 at 5 34 54 am" src="https://github.com/user-attachments/assets/3b98b6c3-095e-400b-8093-48e99dd624e3" />
<img width="1125" height="1281" alt="Screenshot 2026-06-22 at 5 36 25 am" src="https://github.com/user-attachments/assets/0554ccc6-8fd5-49fe-a2b2-79fb80542644" />

## Schematic
<img width="1523" height="1046" alt="Screenshot 2026-06-22 at 5 36 53 am" src="https://github.com/user-attachments/assets/51373373-ee5f-4509-b84b-8f4f3d6e3525" />

# Casing
Onshape Link (Do not click, copy and paste it): https://cad.onshape.com/documents/55ba759bd32af63245a8fd64/w/0539768004f2bf5a541f17f4/e/c03fca18856a8a03d68f317d?renderMode=0&uiState=6a38532017fe1dd1d0fb8e74
## Full
<img width="1226" height="892" alt="Screenshot 2026-06-22 at 6 36 05 am" src="https://github.com/user-attachments/assets/6ef150cb-13d6-4fd8-9544-53d81032cee6" />

## Top
<img width="1141" height="760" alt="Screenshot 2026-06-22 at 6 36 43 am" src="https://github.com/user-attachments/assets/26690f14-068f-4b1d-b647-fa734ad51567" />
<img width="986" height="1219" alt="Screenshot 2026-06-22 at 6 37 21 am" src="https://github.com/user-attachments/assets/aa66d517-8494-4610-9012-31d1ae37da91" />

## Bottom
<img width="1267" height="791" alt="Screenshot 2026-06-22 at 6 38 14 am" src="https://github.com/user-attachments/assets/2311200f-1ae8-41cd-bfc1-3e3b898cf1ad" />
<img width="975" height="1213" alt="Screenshot 2026-06-22 at 6 38 38 am" src="https://github.com/user-attachments/assets/75257ca2-1481-414a-9a9d-e3b584d77b77" />

# BOM (AUD)
| No. | Item | Description | LCSC Supplier Number | Qty Req | Qty Must Buy | Unit Price | Total Price | Running Total | Link |
|:---|:---|:---|:---|:---|:---|:---|:---|:---|:---|
| 1 | 3D Print Filament | Elegoo PLA 1kg | | 1 | 1 | $19.95 | $19.95 | $19.95 | [Jaycar Link](https://www.jaycar.com.au/elegoo-pla-filament-brown-1-75mm-1kg/p/TL6415?srsltid=AfmBOorWonBfeYknAu3rB8aZ4PWmGkUiC_A2ZqcdQLrUnSMhugl3tplenB0) |
| | *Shipping* | Jaycar | | | | | $9.95 | $29.90 | |
| 2 | Screws | M3x30mm | | 4 | 10 | $0.13 | $1.33 | $31.23 | [Makerstore Link](https://www.makerstore.com.au/product/m3-button-head-screws-10-pack/?attribute_pa_length=30mm) |
| 3 | Nuts | M3 | | 4 | 4 | $0.14 | $0.56 | $31.79 | [Makerstore Link](https://www.makerstore.com.au/product/hard-m3nut-1/) |
| | *Shipping* | Makerstore | | | | | $7.50 | $39.29 | |
| 4 | Battery | LiPo Rechargeable 1100mAh | | 1 | 1 | $5.39 | $5.39 | $44.68 | [AliExpress Link](https://www.aliexpress.com/item/1005004824764461.html) |
| | *Shipping* | Aliexpress | | | | | $6.30 | $50.98 | |
| 5 | 7 Pin Headers | Male - 2.54mm Pitch | C6332200 | 2 | 20 | $0.04 | $0.72 | $51.70 | [LCSC Link](https://www.lcsc.com/product-detail/C6332200.html) |
| | 4 Pin Header | Male - 2.54mm Pitch | C5116483 | 1 | 20 | $0.03 | $0.64 | $52.34 | [LCSC Link](https://www.lcsc.com/product-detail/Pin-Headers_ZHOURI-2-54-1-4_C5116483.html) |
| 6 | Buzzer | BUZ-TH_BD12.5-P6.50-D1.4 | C49246964 | 1 | 10 | $0.08 | $0.82 | $53.16 | [LCSC Link](https://www.lcsc.com/product-detail/C49246964.html) |
| 7 | Push Buttons | SW-TH_4P-L4.5-W4.5-P3.00-LS4.8 | C2888493 | 4 | 50 | $0.02 | $0.75 | $53.91 | [LCSC Link](https://www.lcsc.com/product-image/C2888493.html) |
| 8 | Latching Button | SW-TH_TK-6580A-1 | C528770 | 1 | 1 | $0.31 | $0.31 | $54.22 | [LCSC Link](https://www.lcsc.com/product-detail/C528770.html) |
| 9 | OLED Screen | OLED-TH_L27.8-W27.2-P2.54_C9900033791 | C5248080 | 1 | 1 | $3.20 | $3.20 | $57.42 | [LCSC Link](https://www.lcsc.com/product-detail/C5248080.html) |
| | *Shipping* | LCSC | | | | | $9.10 | $66.52 | |
| | *Handling* | LCSC | | | | | $4.28 | $70.80 | |
| 10 | Microcontroller | XIAO-ESP32-C3-DIP-SMD | | 1 | 1 | $6.55 | $6.55 | $77.35 | [Seeed Studio Link](https://www.seeedstudio.com/Seeed-XIAO-ESP32C3-p-5431.html) |
| | *Shipping* | Seeed Studio | | | | | $7.05 | $84.40 | |
| 11 | PCB (without assembly) | Main board (Lead-Free Finish). Components to be soldered. | | 1 | 5 | $1.51 | $7.56 | $91.96 | [JLCPCB Link](https://jlcpcb.com/) |
| 11.2 | Additionals + Shipping | JLCPCB | | | | | $2.14 | $94.10 | |
| **-** | **Grand Total** | | | | | | | **$94.10** | |
# Additional Notes!
This was a Guided Project through Hack Club's Fallout's Docs. The github page of the tutorial is here https://github.com/TaniWanKenobi/tamagotchi. I really loved making it, and I really learnt a lot, just like with the USB Hub. If you are a beginner, I would suggest starting with a smaller project, but this project is INCREDIBLE as a second one! If you've got some experience programming, you'll definitely find this manageable to create.

WARNING - PRODUCTION FILES
The gerber is provided for the JLCPCB or any PCB cutting, but the BOM and CPL may not work properly when ordered, since the pins will not be assembled. This project is designed to have been soldered yourself, if you wish to alter it so that it can be ordered, you may do that but this project does not work in that way. YOU HAVE BEEN WARNED.

Sanity Checked by Kade Harrison and Revant Pandey
