#include <stdio.h>
#include <iostream>

using namespace std;

int main (void)
{
  cout << "**  SmartEcoPlantSystem - Realtime Embedded Programming  **\n" ;
  cout << "**  Testing Moisture Sensor Using MCP3008 **\n" ;
  
  while (1)
  {
	  
	  cout << ADC_analogRead(0);
	  cout << "\n";
	  delay(1000);
  }
  
  return 0;
}

int ADC_analogRead(int channel)
{
	
    int dataADC = 0;
    int handlerSpi = 0;
    char buffer[3]; //bytes to read and send from/to ADC

    if (channel > 7 || channel < 0)
        return -1;

    handlerSpi = spiOpen(0, 100000, 0); // opens SPI channel 0 at 100 kbps, in mode 0

    /* MCU Transmitted Data - page 21 figure 6-1 from datasheet */
    buffer[0] = 1;           // Start bit
    buffer[1] = (8 + channel)<<4; // SGL/Diff + Channel to read
    buffer[2] = 0;           // Don't care
    cout << "buffer[1]: " << (unsigned int)buffer[1] << "\n"; 
    spiXfer(handlerSpi, buffer, buffer, 3); // This function sends 3 bytes to ADC from variable buffer and after sending, it read 3 bytes to buffer variable

    dataADC = (((buffer[1] & 3) << 8) | buffer[2]); // binary math to read 10 bits ADC data

    spiClose(handlerSpi);
    return dataADC;
}
