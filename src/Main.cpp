#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <pthread.h>
#include <wiringPi.h>
#include "../include/moistureSensor.h"
#include "../include/tempSensor.h"
#include "../include/ventilatingSystem.h"


using namespace std;

int main (void)
{
  cout << "**  SmartEcoPlantSystem - Realtime Embedded Programming  **\n" ;
  cout << "**  Main Application Entry Point  **\n" ;
  
  moistureSensor mS("/dev/spidev0.0", 0);
  tempSensor tS("/dev/spidev0.0", 1);
    
  ventilatingSystem vS(0);

  
  while(1)
  {
    //v = mS.read();
    //cout << v;
    //cout << "\n";
    //cout << tS.read();
    //cout <<"\n";
    //delay(500);
    
    vS.run();
    delay(500);
    vS.stop();
    delay(200);
    
  }
  
  return 0;
}
