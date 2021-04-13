#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <pthread.h>
#include <wiringPi.h>

class moistureSensor
{
	public:
		int read();
}
;
