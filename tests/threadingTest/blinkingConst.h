#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <pthread.h>
#include <wiringPi.h>

class blinkingConst
{
	public:
		void* run();
		static void *run_wrapper(void *);
		void start();
}
;
