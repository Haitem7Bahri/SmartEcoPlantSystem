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
#include "../include/wateringSystemThread.h"



using namespace std;

int main (void)
{
  cout << "**  SmartEcoPlantSystem - Realtime Embedded Programming  **\n" ;
  cout << "**  Main Application Entry Point  **\n" ;
  
  moistureSensor mS("/dev/spidev0.0", 1);
  tempSensor tS("/dev/spidev0.0", 0);
  
  while(1)
  {
    cout << "Temp = ";
    cout << tS.readDeg();
    cout << "C\n";
    
    cout << "moiature lvl = ";
    cout << mS.readVal();
    cout << "\n";
    
    delay(1000);
    
    
    
    
    
  }
    
  //ventilatingSystem vS(0);
  //wateringSystem wS(2,2000);

  //delay(1000);
  
  //wS.run();
  
  //ventilatingSystemThread vsT;
  //wateringSystemThread wsT;
  
  //vsT.start();
  //wsT.start();
  
  //wateringSystem wSys(0, 2000);
  //wSys.run();
  
    //wiringPiSetup();
    //pinMode (0, OUTPUT) ;
    //digitalWrite (0, 1);
    //delay(2000);
    //digitalWrite(0, 0);
  
  return 0;
}
