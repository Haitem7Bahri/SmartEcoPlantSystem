#include <stdio.h>
#include <wiringPi.h>
#include <iostream>

using namespace std;

// LED Pin - wiringPi pin 0 is BCM_GPIO 17.

#define LED     0

int main (void)
{
  cout << "Raspberry Pi - Gertboard Blink\n" ;

  wiringPiSetup () ;

  pinMode (LED, OUTPUT) ;

  for (int i=0; i<100000; i++)
  {
    digitalWrite (LED, 1) ;     // On
    delay (10*i) ;               // mS
    digitalWrite (LED, 0) ;     // Off
    delay (10*i) ;
  }
  return 0 ;
}
