#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <pthread.h>
#include <wiringPi.h>

using namespace std;

class moistureSensor
{
	private:
		string _spiBus;
		int _analogChannel;
	public:
		moistureSensor(string, int);
		int read();
		float readVal();
}
;
