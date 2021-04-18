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
#include "../include/wateringSystem.h"

using namespace std;

wateringSystem::wateringSystem(int port, int runTime)
{
    //storing port no
    _port = port;
    
    //time to run the water pump
    _runTime = runTime;
    
    //wiringPi required setup method
    wiringPiSetup();
    
    //setting port to output
    pinMode (_port, OUTPUT) ;
}

void wateringSystem::run()
{
    //running the water pump for the amount of _runTime
    digitalWrite (_port, 1);
    delay(_runTime);
    digitalWrite(_port, 0);
    delay(5000);
}

void wateringSystem::stop()
{
    //stopping the water pump
	digitalWrite (_port, 0) ;
}


