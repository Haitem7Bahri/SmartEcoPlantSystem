#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <pthread.h>
#include <wiringPi.h>
#include <thread>
#include "../include/mcp3008Spi.h"
#include "../include/ventilatingSystemThread.h"

using namespace std;

void *ventilatingSystemThread::process()
{
	wiringPiSetup();
   
	pinMode (0, OUTPUT) ;
	
	cout << "Ventilating System Thread Started \n";
	
	for (int i=0; i<10; i++)
	{
		digitalWrite (0, 1) ;
		delay (20*i) ;
		digitalWrite (0, 0) ;
		delay (200) ;
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
