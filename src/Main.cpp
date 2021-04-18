/* 
 * This file is part of the Smart Eco-Plant System.
 * It is part of the Realtime Embedded Programming course at Uni of glasgow
 * 
 * The project is available at https://github.com/Haitem7Bahri/SmartEcoPlantSystem
 * 
 * This is a free software that can be modified and redistributed under the GPL-30
 * license.
 * 
 * No warranty is provided with this software, use it at your own responsibility,
 * check the GPL license documentation for more details.
 * 
 */



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
  
  //creating an instance of the ventilation system thread
  ventilatingSystemThread vsT;
  
  //creating an instance of the watering system thread
  wateringSystemThread wsT;
  
  
  // starting ventilating thread
  vsT.start(); 
  
  //starting watering system thread
  wsT.start();
  
  
  return 0;
}
