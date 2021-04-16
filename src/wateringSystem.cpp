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
    _port = port;
    _runTime = runTime;
    wiringPiSetup();
    pinMode (_port, OUTPUT) ;
}

void wateringSystem::run()
{
    digitalWrite (_port, 1);
    delay(_runTime);
    digitalWrite(_port, 0);
}

void wateringSystem::stop()
{
	digitalWrite (_port, 0) ;
}


