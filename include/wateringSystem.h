#include <stdio.h>
#include <wiringPi.h>
#include <iostream>


class wateringSystem
{
	public:
		int _port;
		int _runTime;
		wateringSystem(int port, int runTime);
		void run();
		void stop();
};

