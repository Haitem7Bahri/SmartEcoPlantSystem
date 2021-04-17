/* co2 sensor data transmission */
#include "./../include/co2tf.h"

void getco2(int* bit0, int* bit1, int* bit2, int* bit3){
  static int i = 0;
  int fd = 1;
  char rx[11];   
  if(serialDataAvail(fd)>=1) {  
    rx[i] = serialGetchar(fd);
    if(rx[0] != 0x20) {
      i = 0;
    } else if(i == 1 && rx[1] != 0x20) {
      i = 0;
    } else if(rx[10] == 0x0D && rx[11] == 0x0A) {
      *bit0 = rx[2] - '0'; *bit1 = rx[3] - '0';
      *bit2 = rx[4] - '0'; *bit3 = rx[5] - '0';
      i = 0;
    } else {
      i++;
    } 
  } else {
	  *bit0 = -1;
	  } 
}

/*void getco2(int* co2){
  static int i = 0;
  int fd = 1;
  char data[11];
  int rx[11];

  if(serialDataAvail(fd)>=1) {  
    data[i] = serialGetchar(fd);
    rx[i] = data[i] - '0';
    if(data[0] != 0x20) {
      i = 0;
    } else if(i == 1 && data[1] != 0x20) {
      i = 0;
    } else if(data[10] == 0x0D && data[11] == 0x0A) {
      *co2 = 1000 * rx[2] + 100 * rx[3] + 10 * rx[4] + rx[5];
      i = 0;
    } else {
      i++;
    } 
  } else {
	  *co2 = -1;
	  } 
}
*/

/*void getco2(int* co2) {
  static char i = 0;
  int fd;
  int sum2 = 0;
  int sum3 = 0;
  int sum4 = 0; 
  static int rx[11];
  if(serialDataAvail(fd)>=1) {  
    rx[i] = serialGetchar(fd);
    if(rx[0] != 0x20) {
      i = 0;
    } else if(i == 1 && rx[1] != 0x20) {
      i = 0;
    } else if(rx[10] ==0x0D && rx[11] ==0x0A) {
      sum2 = rx[2] - 0x30;
      sum3 = rx[3] - 0x30;
      sum4 = rx[4] - 0x30;
      *co2 = 1000 * sum2 + 100 * sum3 + 10 * sum2 + rx[5];
      i = 0;
    } else {
      i++;
    } 
  } else {
	  *co2 = -1;
	  } 
}
*/

/*void getco2(char* co2){
  static int i = 0;
  int fd = 1;
  char rx[11];
  int sum2;
  int sum3;
  int sum4;

  if(serialDataAvail(fd)>=1) {  
    rx[i] = serialGetchar(fd);
    if(rx[0] != 0x20) {
      i = 0;
    } else if(i == 1 && rx[1] != 0x20) {
      i = 0;
    } else if(rx[10] == 0x0D && rx[11] == 0x0A) {
      sum2 = rx[2] - 0x30;
      sum3 = rx[3] - 0x30;
      sum4 = rx[4] - 0x30;
      *co2 = 1000 * sum2 + 100 * sum3 + 10 * sum4 + rx[5];
      i = 0;
    } else {
      i++;
    } 
  } else {
	  *co2 = -1;
	  } 
}*/
