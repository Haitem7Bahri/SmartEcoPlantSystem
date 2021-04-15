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
	
	cout << "ventilatingSystemThread Started \n";
	
	for (int i=0; i<1000; i++)
	{
		digitalWrite (0, 1) ;
		delay (200) ;
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
	pthread_create(&_thread, NULL, &ventilatingSystemThread::process_wrapper, this);
	
	ventilatingSystemThread::join();
}

void ventilatingSystemThread::join()
{
  	pthread_join(_thread, NULL);
}
