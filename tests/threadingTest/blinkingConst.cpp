#include "blinkingConst.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <pthread.h>
#include <wiringPi.h>
#include <thread>


void *blinkingConst::run()
{
	wiringPiSetup();
   
	pinMode (1, OUTPUT) ;
	
	for (int i=0; i<1000; i++)
	{
		digitalWrite (1, 1) ;
		delay (200) ;
		digitalWrite (1, 0) ;
		delay (200) ;
	}
	
	return 0;
  
}

void *blinkingConst::run_wrapper(void *object)
{
	return ((blinkingConst *)object)->run();
	
	
}

void blinkingConst::start()
{
	
	//std::thread t1(&blinkingVar::run, this);
	
	pthread_t thread1;
	
	pthread_create(&thread1, NULL, &blinkingConst::run_wrapper, this);
	
	//pthread_join(t1, NULL);
	
	//t1.join();
	
}

