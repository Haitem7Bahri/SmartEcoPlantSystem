#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <wiringPi.h>
#include <wiringSerial.h>
#include "./../include/co2tf.h"

void setup(){
  if(wiringPiSetup() == -1){
    std :: cerr << "Setup Error" << std :: endl;
    exit(-1);
    }
  }

int main(void){
  int fd;
  int bit0, bit1, bit2, bit3;
  serialOpen("/dev/ttyAMA0",9600);
  if((fd = serialOpen("/dev/ttyAMA0",9600)) == -1){
    std :: cerr << "Serial Error" << std :: endl;
    exit(-1);
    } else{printf("Serial Open sucess\n");
      }
        
	getco2(&bit0, &bit1, &bit2, &bit3);
  while(1){
    getco2(&bit0, &bit1, &bit2, &bit3);
    if(1){
      printf("co2= %d %d %d %d ppm\n", bit0, bit1, bit2, bit3);
      }
    delay(500);
    }
}
