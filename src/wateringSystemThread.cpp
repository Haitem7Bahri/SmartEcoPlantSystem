#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <pthread.h>
#include <wiringPi.h>
#include <thread>
#include "../include/mcp3008Spi.h"
#include "../include/wateringSystemThread.h"
#include "../include/moistureSensor.h"

using namespace std;

void *wateringSystemThread::process()
{
	wiringPiSetup();
   
	pinMode (1, OUTPUT) ;
	
	moistureSensor mS("/dev/spidev0.0", 0);
	
	cout << "Watering System Thread Started \n";

	for (int i=0; i<10000; i++)
	{
		digitalWrite (1, 1) ;
		delay (mS.read()) ;
		digitalWrite (1, 0) ;
		delay (1000) ;
	}
  
    return 0;
}

void *wateringSystemThread::process_wrapper(void *object)
{
	return ((wateringSystemThread *)object)->process();
}

void wateringSystemThread::start()
{
	pthread_t t;
	 
	pthread_create(&t, NULL, &wateringSystemThread::process_wrapper, this);
	
	wateringSystemThread::join(t);
}

void wateringSystemThread::join(pthread_t _t)
{
  	pthread_join(_t, NULL);
}
