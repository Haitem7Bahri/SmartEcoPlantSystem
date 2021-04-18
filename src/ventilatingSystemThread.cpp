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
#include "../include/ventilatingSystemThread.h"
#include "../include/tempSensor.h"
#include "../include/ventilatingSystem.h"

using namespace std;

void *ventilatingSystemThread::process()
{
	// an instance of temp sensor with spi port = spidev0.0 and channel 1 from the mcp3008
	tempSensor tS("/dev/spidev0.0", 1);
	
	// an instance of the ventilating system connected to port 1 (GPIO18);
	ventilatingSystem vS(1);
	
	cout << "------------------------------ \n";
	cout << "Ventilating System Thread Started \n";

	while(1)
	{
		if(tS.readDeg() > 36)
		{
			cout << "temp is high .. starting cooling fan!";

			//starting cooling fan
			vS.run();
			
			delay(1000);
		}
		else
		{
			//stopping the ventilting system
			vS.stop();
		}
	}
  
    return 0;
}

void *ventilatingSystemThread::process_wrapper(void *object)
{
	//returning the 'process' method to be used in a thread
	return ((ventilatingSystemThread *)object)->process();
}

void ventilatingSystemThread::start()
{
	//declaring a new pthread instance
	pthread_t t;
	
	//assigning the process method to the thread  
	pthread_create(&t, NULL, &ventilatingSystemThread::process_wrapper, this);
	
	//making the thread joint the current threads
	//ventilatingSystemThread::join(t);
}

void ventilatingSystemThread::join(pthread_t _t)
{
	// to make the thread join current threads
  	pthread_join(_t, NULL);
}
