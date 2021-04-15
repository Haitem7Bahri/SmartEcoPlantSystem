#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <pthread.h>
#include <wiringPi.h>

class wateringSystemThread
{
	public:
		void* run();
		static void *run_wrapper(void *);
		void start();
		void join();
}
;