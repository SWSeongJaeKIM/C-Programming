#include <Wire.h>
#include <MsTimer2.h>

#define SLAVE 4
#define start_chack   4

int data_1 = 0;
int data_1_slave = 5;
int data_2 = 0;
int data_2_slave = 10;
//int data_3 = 0;
//int data_3_slave = 15;
//int data_4 = 0;
//int data_4_slave = 20;

int flag = 0;

void onTimer()
{
  digitalWrite(start_chack, HIGH);
  flag = 1;
  digitalWrite(start_chack, LOW);
 }

void setup()
{
  pinMode(start_chack, OUTPUT);
  Serial.begin(115200);
  Wire.begin();
  MsTimer2::set(1, onTimer);   //1.25 // 이걸 1
  MsTimer2::start();
}

void loop()
{
  if(flag == 1)
  {
   Wire.requestFrom(SLAVE,4); 
  data_1 = Wire.read();
  data_2 = Wire.read();
  data_3 = Wire.read();
  data_4 = Wire.read();
   Wire.beginTransmission(SLAVE);
  Wire.write(data_1_slave);
  Wire.write(data_2_slave);
 Wire.write(data_3_slave);
  Wire.write(data_4_slave);
  Wire.endTransmission();
  flag = 0;
  }
}
