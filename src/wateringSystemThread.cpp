#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <pthread.h>
#include <wiringPi.h>
#include <thread>
#include "../include/mcp3008Spi.h"
#include "../include/wateringSystemThread.h"
#include "../include/moistureSensor.h"
#include "../include/wateringSystem.h"


using namespace std;

void *wateringSystemThread::process()
{
	moistureSensor mS("/dev/spidev0.0", 0);
	wateringSystem wS(0, 500);
	
	cout << "------------------------------ \n";
	cout << "Watering System Thread Started \n";

	while(1)
	{
		if(mS.readVal() > 80)
		{
			cout << "Soil is dry .. starting water pump!";
			wS.run();
		}
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
