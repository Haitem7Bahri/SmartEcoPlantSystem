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
#include "../include/ventilatingSystem.h"

using namespace std;

ventilatingSystem::ventilatingSystem(int port)
{
    //storing port no
    _port = port;
    
    //wiringPi required setup method
    wiringPiSetup();
    
    //setting port to output
    pinMode (_port, OUTPUT) ;
}

void ventilatingSystem::run()
{
    //starting the coooling fan
    digitalWrite (_port, 1) ;
}

void ventilatingSystem::stop()
{
    //stopping the colling fan
    digitalWrite (_port, 0) ;
}


