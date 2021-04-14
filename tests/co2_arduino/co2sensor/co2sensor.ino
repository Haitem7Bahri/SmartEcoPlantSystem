void getco2(int* co2) {
  static char i = 0;
  char j = 0;
  int sum2 = 0;
  int sum3 = 0;
  int sum4 = 0; 
  static int rx[11];
  if(Serial.available()) {  
    rx[i] = Serial.read();
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
  }  
}

void setup() {
  Serial.begin(9600);
  Serial.println("start");
}

void loop() {
  int co2 = 0;
  getco2(&co2);
  while(!co2){
    getco2(&co2);
    if(co2){
      Serial.print("co2=");
      Serial.print(co2);
      Serial.println(" ppm");
      }
    }
}
