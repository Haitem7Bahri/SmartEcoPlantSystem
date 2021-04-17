#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <wiringPi.h>
#include <wiringSerial.h>
#include "./../include/co2tf.h"

void setup(){
  int fd=0;
 if((fd = serialOpen("/dev/ttyAMA0",9600)) == -1){
    std :: cerr << "Serial Error" << std :: endl;
    exit(-1);
    } else{printf("Serial Open sucess\n");
      }
      
  if (wiringPiSetup() == -1){
    std :: cerr << "WiringPi Error" << std :: endl;
    exit(-1);
    } else{ printf("WiringPi Open sucess\n");
      }
  }

int main(void){
  int bit0, bit1, bit2, bit3;
  int fd=0;
  setup();
  serialFlush(fd);
	getco2(&bit0, &bit1, &bit2, &bit3);
  while(1){
    getco2(&bit0, &bit1, &bit2, &bit3);
    printf("co2= %d %d %d %d ppm\n", bit0, bit1, bit2, bit3);
    delay(500);
    }
}
