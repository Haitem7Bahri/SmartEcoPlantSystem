#ifndef _CO2_TF_H_
#define _CO2_TF_H_

#include <stdio.h>
#include <wiringPi.h>
#include <wiringSerial.h>

void getco2(int* bit0, int* bit1, int* bit2, int* bit3);

#endif
