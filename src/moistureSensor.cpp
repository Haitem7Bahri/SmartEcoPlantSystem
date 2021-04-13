#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <pthread.h>
#include <wiringPi.h>
#include <thread>
#include "mcp3008Spi.h"
#include "moistureSensor.h"


int moistureSensor::read()
{
	mcp3008Spi a2d("/dev/spidev0.0", SPI_MODE_0, 1000000, 8);
    int i = 200;
    int a2dVal = 0;
    int a2dChannel = 0;
    unsigned char data[3];
 
 
    
        data[0] = 1;  
        data[1] = 0b10000000 |( ((a2dChannel & 7) << 4)); 
        data[2] = 0; 
 
        a2d.spiWriteRead(data, sizeof(data) );
 
        a2dVal = 0;
                a2dVal = (data[1]<< 8) & 0b1100000000; 
                a2dVal |=  (data[2] & 0xff);
    
    return a2dVal;
  
}
