# Sample Test Cases & Expected Results

| Test Case | Input (Simulated Angle) | Expected Output | Status |
| :--- | :--- | :--- | :--- |
| TC-01 | Rotate encoder to -10° | Plasma OFF (Relay High) | PASS |
| TC-02 | Rotate encoder to 0° | Plasma ON (Relay Low) | PASS |
| TC-03 | Rotate encoder to 45° | Plasma ON (Relay Low) | PASS |
| TC-04 | Rotate encoder to 90° | Plasma ON (Relay Low) | PASS |
| TC-05 | Rotate encoder to 91° | Plasma OFF (Relay High) | PASS |
| TC-06 | Rapidly spin past 90° | Fast switch to OFF, latency <10ms | PASS |
