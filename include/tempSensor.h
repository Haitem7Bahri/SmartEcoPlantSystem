#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <pthread.h>
#include <wiringPi.h>

using namespace std;

class tempSensor
{
	private:
		string _spiBus;
		int _analogChannel;
	public:
		tempSensor(string, int);
		int read();
		float readDeg();
}
;
