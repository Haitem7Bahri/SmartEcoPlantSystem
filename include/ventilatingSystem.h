#include <stdio.h>
#include <wiringPi.h>
#include <iostream>


class ventilatingSystem
{
	public:
		int _port;
		ventilatingSystem(int port);
		void run();
		void stop();
};

