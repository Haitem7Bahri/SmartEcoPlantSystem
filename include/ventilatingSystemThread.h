#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <pthread.h>
#include <thread>

class ventilatingSystemThread
{
	private:
		pthread_t _thread;
	public:
		void *process();
		static void *process_wrapper(void *);
		void start();
		void join();
};	
