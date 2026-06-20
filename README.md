# Overview
## Context
A small digital pet as a physical device remake! It features four buttons and a buzzer. It also has an OLED display and can be recharged! The coding is made so that it can show it's emotions based on how it's treated. Whether it's not played with, It was created as an entry to contribute to the Fallout Hackathon in Shenzhen run by Hack Club! It was quite involved, requiring the research of components, importing the EasyEda JLCPCB library of components library into Kicad, and properly understanding how to make a schematic and routing a PCB. It can also be used with both smaller LiPo batteries and medium sized ones too!

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
  - Print the Casing, spacers and battery holder lid with the 3D Files provided on a 3D Printer
    OR
  - Buy the Casing printed from a printing service

3. Put it together
  - Put a bought or owned LiPo Battery and connect it to the bottom of the pcb, and place it into the allocated space in the casing
  - Use M3 Screws (buy or use owned ones) to screw the casing and PCB together

5. Program the PCB.
  - Connect to the Tamagotchi's USB-C connector through a computer and apply the CircuitPython program provided

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
<img width="957" height="995" alt="Screenshot 2026-06-19 at 8 17 03 pm" src="https://github.com/user-attachments/assets/0db4530b-7fc7-4370-b897-0cdf6ea0c191" />

## Top
<img width="1112" height="1198" alt="Screenshot 2026-06-19 at 8 54 00 pm" src="https://github.com/user-attachments/assets/fb5eaeba-8fed-4cf2-b923-1efe1139b76b" />
<img width="923" height="1214" alt="Screenshot 2026-06-19 at 8 54 18 pm" src="https://github.com/user-attachments/assets/87f51dff-354d-47f3-b447-c3477faf9039" />

## Bottom
Highlighted are the Spacers and Battery Lid
<img width="1264" height="1160" alt="Screenshot 2026-06-19 at 8 47 18 pm" src="https://github.com/user-attachments/assets/79c287a8-be6f-4163-905e-394254ccc065" />
<img width="941" height="1222" alt="Screenshot 2026-06-19 at 8 48 20 pm" src="https://github.com/user-attachments/assets/6727740d-09f6-40ca-9e7e-35a89f005d89" />

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
This was a Guided Project through Hack Club's Fallout's Docs. I really loved making it, and I really learnt a lot, just like with the USB Hub. If you are a beginner, I would suggest starting with a smaller project, but this project is INCREDIBLE as a second one!

Sanity Checked by Kade Harrison
