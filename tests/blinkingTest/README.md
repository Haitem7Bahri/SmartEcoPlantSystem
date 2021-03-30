## Responsiveness Test using variable-frequency blinking LED

This simple code is used to test the responsiveness of the Rasp Pi when trying different power supplies.
When a weak power supply is used, (example: USB port from a computer), there will be some stuttering behaviour when blinking at high frequencies.

### Installation

One LED is connected to port GPIO 17 on the Raspberry Pi with a suitable resistor.

### Running the test

The test can be run using the following command:
```
./blinkingTest
```