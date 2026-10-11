## Duskpad
Duskpad is a 16-key quad-layer macro pad with an OLED display and underglow RGB using WS2812B leds running QMK and Via. it was built for Hackclub Stardance with the Hackpad misson.

## Features:
- 128x32 OLED Display
- 20 WS2812B RGB LEDs. 16 for per key lighting, and 4 layer indicators
- 16 Keys
- VIA support
  
## CAD Model:
Everything fits together using 6 M3 Bolts and heatset inserts.
It has 3 separate printed pieces. The base, the middle to clamp down on the PCB, and the top cover.
<img width="1141" height="932" alt="Screenshot 2026-10-11 124523" src="https://github.com/user-attachments/assets/779bd9b7-c3f1-4326-aee6-ffd6c17e17f3" />

Made in onshape
## PCB
Here's my PCB! It was made in KiCad.
<img width="668" height="810" alt="Screenshot 2026-07-02 135041" src="https://github.com/user-attachments/assets/f492c94b-a467-4649-8737-5d9484319d03" />
Schematic
<img width="1487" height="1127" alt="Screenshot 2026-07-02 135057" src="https://github.com/user-attachments/assets/4d0cdab1-51a4-43a1-ad68-2058d12abdc0" />


## Firmware Overview
This hackpad uses [QMK](https://qmk.fm/) firmware for everything. 

- The 16 keys currently act as macros I dynamically change in VIA.
- 4 preset layers(setting,numpad, and idk what to do with the other 2)
- the top-left key runs a custom key code where, if you tap it, it sends the assigned code for that layer but if you hold it, it'll cycle to the next layer up


## BOM:
Here should be everything you need to make this hackpad

- 16x Cherry MX Switches
- 16x DSA Keycaps
- 6x M3x5x4 Heatset inserts
- 6x M3x16mm SHCS Bolts
- 16x 1N4148 DO-35 Diodes.
- 20x WS2812B LEDs
- 1x 0.91" 128x32 OLED Display
- 1x XIAO RP2040
- 1x Case (3 printed parts)

