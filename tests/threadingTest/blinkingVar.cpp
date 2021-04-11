#include "blinkingVar.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <pthread.h>
#include <wiringPi.h>
#include <thread>

void *blinkingVar::run(void)
{
	wiringPiSetup();
	pinMode (0, OUTPUT) ;
	
	for (int i=0; i<1000; i++)
	{
		digitalWrite (0, 1) ;
		delay (10*i) ;
		digitalWrite (0, 0) ;
		delay (10*i) ;
	}
	
	return 0;
}

void *blinkingVar::run_wrapper(void *object)
{
	return ((blinkingVar *)object)->run();
}

void blinkingVar::start()
{
	//std::thread t1(&blinkingVar::run, this);
	
	pthread_t thread1;
	
	pthread_create(&thread1, NULL, &blinkingVar::run_wrapper, this);
	
	//pthread_join(t1, NULL);
	
	//t1.join();
	
}

