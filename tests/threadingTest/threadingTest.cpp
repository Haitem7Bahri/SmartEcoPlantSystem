#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <pthread.h>
#include <wiringPi.h>

using namespace std;

void *blinking1(void *)
{
   wiringPiSetup();
   
   pinMode (0, OUTPUT) ;
	
   for (int i=0; i<1000; i++)
   {
      digitalWrite (0, 1) ;
      delay (100) ;
      digitalWrite (0, 0) ;
      delay (100) ;
   }
   
   return 0;
}

void *blinking2(void *)
{
    wiringPiSetup();
   
    pinMode (1, OUTPUT) ;
	
    for (int i=0; i<10000; i++)
    {
      digitalWrite (1, 1) ;
      delay (1*i) ;
      digitalWrite (1, 0) ;
      delay (1*i) ;
    }
    return 0;
}

int main () {
   pthread_t threads[2];
   
   pthread_create(&threads[0], NULL, blinking1, NULL);
   pthread_create(&threads[1], NULL, blinking2, NULL);
   
   pthread_exit(NULL);
}
