# CAP-VMAT-Sync-System
Open-source, low-cost (~₹10,000) control framework to synchronize Cold Atmospheric Plasma (CAP) delivery with VMAT radiotherapy gantry rotation.

## How it works
A 600 PPR rotary encoder simulates gantry angle. Arduino Uno code switches an opto-isolated relay (standing in for the plasma generator) ON only between 0° and 90°.

## Status
- Done: control logic (software), simulated gantry angle, stakeholder interviews (10)
- Planned: physical plasma generator integration, latency measurement, preclinical testing

## License
MIT
## Setup & Hardware Configuration
1. **Hardware Setup:** Connect the 600 PPR Rotary Encoder (CLK to Pin D2, DT to Pin D3, VCC to 5V, GND to GND).
2. **Relay Setup:** Connect the Opto-isolated Relay IN pin to Arduino Pin D7.
3. **Environment:** Install the Arduino IDE (Version 2.0+). No external libraries are required.
4. **Execution:** Open `CAP_VMAT_Control.ino` in the Arduino IDE, select your COM port, and upload the code. Open the Serial Monitor at 9600 baud to view the simulated gantry angle.
