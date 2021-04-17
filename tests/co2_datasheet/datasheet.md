Baud Rate: 9600
Data Length: 8
Parity Bit: None

Active Mode: Transmit Current Concentration in 1Hz, no data needs to be transmitted in TX

RX Format:

Blank Blank Number1 Number2 Number3 Number4 Blank P P M /r /n

e.g. output 1235ppm(in hex)

Blank Blank 1 	 2    3    5 	Blank P    P    M    /r   /n
0x20  0x20  0x31 0x32 0x33 0x35 0x20  0x70 0x70 0x6D 0x0D 0x0A


PWM Out
Period: 1004ms +- 5%
Forward PW: PPM/5 + 2ms