/* 
 * This file is part of the Smart Eco-Plant System.
 * It is part of the Realtime Embedded Programming course at Uni of glasgow
 * 
 * The project is available at https://github.com/Haitem7Bahri/SmartEcoPlantSystem
 * 
 * This is a free software that can be modified and redistributed under the GPL-30
 * license.
 * 
 * No warranty is provided with this software, use it at your own responsibility,
 * check the GPL license documentation for more details.
 * 
 */

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <pthread.h>
#include <wiringPi.h>
#include <thread>
#include "../include/mcp3008Spi.h"
#include "../include/tempSensor.h"

using namespace std;

tempSensor::tempSensor(string spiBus, int analogChannel)
{
    //setting the spi bus
    _spiBus = spiBus;
    
    //setting the channel no from the mcp3008 chip
    _analogChannel = analogChannel;
}

int tempSensor::read()
{
    //creating mcp3008spi instance to read from the chip
	mcp3008Spi a2d(_spiBus, SPI_MODE_0, 1000000, 8);
    
    //create variable to store the final value
    int a2dVal = 0;
    
    //setting the channel on the mcp3008
    int a2dChannel = _analogChannel;
    
    //used to store data
    unsigned char data[3];
 
        // setting reading limits
        data[0] = 1;  
        data[1] = 0b10000000 |( ((a2dChannel & 7) << 4)); 
        data[2] = 0; 
 
        a2d.spiWriteRead(data, sizeof(data) );
 
        a2dVal = 0;
        
        //reading the first 8 bits
        a2dVal = (data[1]<< 8) & 0b1100000000; 
        a2dVal |=  (data[2] & 0xff);
    
    return a2dVal;
}

float tempSensor::readDeg()
{
    //converting value to degrees
    return (tempSensor::read() / 4.5);
}
