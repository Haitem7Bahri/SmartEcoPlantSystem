#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <pthread.h>
#include <wiringPi.h>
#include "blinkingVar.h"
#include "blinkingConst.h"


using namespace std;

//void *blinking1(void *)
//{
   //wiringPiSetup();
   
   //pinMode (0, OUTPUT) ;
	
   //for (int i=0; i<1000; i++)
   //{
      //digitalWrite (0, 1) ;
      //delay (100) ;
      //digitalWrite (0, 0) ;
      //delay (100) ;
   //}
   
   //return 0;
//}

//void *blinking2(void *)
//{
    //wiringPiSetup();
   
    //pinMode (1, OUTPUT) ;
	
    //for (int i=0; i<10000; i++)
    //{
      //digitalWrite (1, 1) ;
      //delay (1*i) ;
      //digitalWrite (1, 0) ;
      //delay (1*i) ;
    //}
    //return 0;
//}

int main () {
   pthread_t threads[2];
   
   //blinkingVar MyBlinkingVar;
   
   blinkingVar M;
   
   blinkingConst N;
   
   pthread_create(&threads[0], NULL, &blinkingVar::run_wrapper, &M);
   pthread_create(&threads[1], NULL, &blinkingConst::run_wrapper, &N);
   
   pthread_exit(NULL);
   

   //M.start();

   //N.start();
}
