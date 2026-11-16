# CAP-VMAT-Sync-System
Open-source, low-cost (~₹10,000) control framework to synchronize Cold Atmospheric Plasma (CAP) delivery with VMAT radiotherapy gantry rotation.

## How it works
A 600 PPR rotary encoder simulates gantry angle. Arduino Uno code switches an opto-isolated relay (standing in for the plasma generator) ON only between 0° and 90°.

## Status
- Done: control logic (software), simulated gantry angle, stakeholder interviews (10)
- Planned: physical plasma generator integration, latency measurement, preclinical testing

## License
MIT
