#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <pthread.h>
#include <wiringPi.h>
#include <thread>
#include "../include/mcp3008Spi.h"
#include "../include/ventilatingSystemThread.h"
#include "../include/tempSensor.h"
#include "../include/ventilatingSystem.h"

using namespace std;

void *ventilatingSystemThread::process()
{
	tempSensor tS("/dev/spidev0.0", 1);
	ventilatingSystem vS(1);
	
	cout << "------------------------------ \n";
	cout << "Ventilating System Thread Started \n";

	while(1)
	{
		if(tS.readDeg() > 36)
		{
			cout << "T = ";
			cout << tS.readDeg();
			cout << "\n";
			vS.run();
			delay(1000);
		}
		else
		{
			vS.stop();
		}
	}
  
    return 0;
}

void *ventilatingSystemThread::process_wrapper(void *object)
{
	return ((ventilatingSystemThread *)object)->process();
}

void ventilatingSystemThread::start()
{
	pthread_t t;
	 
	pthread_create(&t, NULL, &ventilatingSystemThread::process_wrapper, this);
	
	//ventilatingSystemThread::join(t);
}

void ventilatingSystemThread::join(pthread_t _t)
{
  	pthread_join(_t, NULL);
}
