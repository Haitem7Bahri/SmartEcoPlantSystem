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
    _port = port;
    wiringPiSetup();
    pinMode (_port, OUTPUT) ;
}

void ventilatingSystem::run()
{
    digitalWrite (_port, 1) ;
}

void ventilatingSystem::stop()
{
	digitalWrite (_port, 0) ;
}


