#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <pthread.h>
#include <wiringPi.h>
#include "../include/moistureSensor.h"
#include "../include/tempSensor.h"
#include "../include/ventilatingSystem.h"
#include "../include/wateringSystem.h"
#include "../include/ventilatingSystemThread.h"


using namespace std;

int main (void)
{
  cout << "**  SmartEcoPlantSystem - Realtime Embedded Programming  **\n" ;
  cout << "**  Main Application Entry Point  **\n" ;
  
  //moistureSensor mS("/dev/spidev0.0", 0);
  //tempSensor tS("/dev/spidev0.0", 1);
    
  //ventilatingSystem vS(0);
  //wateringSystem wS(2,2000);

  //delay(1000);
  
  //wS.run();
  
  ventilatingSystemThread vsT;
  
  vsT.start();
  
  return 0;
}
