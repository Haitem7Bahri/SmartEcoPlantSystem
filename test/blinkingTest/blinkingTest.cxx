#include <stdio.h>
#include <wiringPi.h>
#include <iostream>

using namespace std;

// LED Pin - wiringPi pin 0 is BCM_GPIO 17.

#define LED     0

int main (void)
{
  cout << "SmartEcoPlantSystem - Realtime Embedded Progrsmming\n" ;
  cout << "blinkingTest - Blinking LED at different frequency to check the board responsiveness\n" ;
  
  wiringPiSetup () ;

  pinMode (LED, OUTPUT) ;

  for (int i=0; i<100; i++)
  {
    digitalWrite (LED, 1) ;
    delay (10*i) ;
    digitalWrite (LED, 0) ;
    delay (10*i) ;
  }
  return 0 ;
}
