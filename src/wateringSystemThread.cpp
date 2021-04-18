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
#include "../include/mcp3008Spi.h"
#include "../include/wateringSystemThread.h"
#include "../include/moistureSensor.h"
#include "../include/wateringSystem.h"


using namespace std;

void *wateringSystemThread::process()
{
	// an instance of moisture sensor with spi port = spidev0.0 and channel 0 from the mcp3008
	moistureSensor mS("/dev/spidev0.0", 0);
	
	// an instance of the watering system connected to port 0 (GPIO17) with 500ms running time
	wateringSystem wS(0, 500);
	
	cout << "------------------------------ \n";
	cout << "Watering System Thread Started \n";

	// looping forever
	while(1)
	{
		//checking if the moisture level at the required level
		if(mS.readVal() > 80)
		{
			cout << "Soil is dry .. starting water pump!";
			
			//starting the watering system
			wS.run();
			
			delay(1000);
		}
	}
  
    return 0;
}

void *wateringSystemThread::process_wrapper(void *object)
{
	//returning the 'process' method to be used in a thread
	return ((wateringSystemThread *)object)->process();
}

void wateringSystemThread::start()
{
	//declaring a new pthread instance
	pthread_t t;
	 
	//assigning the process method to the thread 
	pthread_create(&t, NULL, &wateringSystemThread::process_wrapper, this);
	
	//making the thread joint the current threads
	wateringSystemThread::join(t);
}

void wateringSystemThread::join(pthread_t _t)
{
	// to make the thread join current threads
  	pthread_join(_t, NULL);
}
