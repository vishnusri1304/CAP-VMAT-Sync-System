# Technical Architecture

## System Flowchart
1. **VMAT Gantry Motion** -> Simulated by user turning the Rotary Encoder.
2. **Rotary Encoder** -> Generates pulses read by Arduino Pins D2 and D3.
3. **Arduino Brain** -> Calculates the current angle and checks if it falls within the 0° to 90° target window.
4. **Opto-Relay** -> If angle is valid, Arduino sends a LOW signal to the relay to close the circuit safely.
5. **HV Supply** -> 5kV-10kV power is sent to the DBD Probe.
6. **DBD Probe** -> Generates Cold Atmospheric Plasma to sensitize the tumor. 
