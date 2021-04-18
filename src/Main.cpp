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
  
  ventilatingSystemThread vsT;
  wateringSystemThread wsT;
  
  vsT.start(); 
  wsT.start();
  
  
  return 0;
}
