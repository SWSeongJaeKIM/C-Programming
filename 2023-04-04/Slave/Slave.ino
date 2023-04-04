//slave
#include <Wire.h>

#define SLAVE 4
volatile char data_1 = 5;
volatile int  data_1_master = 0;
volatile char data_2 = 10;
volatile int  data_2_master = 0;
volatile char data_3 = 15;
volatile int  data_3_master = 0;
volatile char data_4 = 20;
volatile int  data_4_master = 0;


void setup()
{
  Wire.begin(SLAVE);
  Serial.begin(115200);


 Wire.onRequest(requestEvent);
 Wire.onReceive(receiveEvent);
}


void loop ()
{
 

}


void requestEvent()
{
  Wire.write(data_1);
  Wire.write(data_2);
  Wire.write(data_3);
  Wire.write(data_4);
}
void receiveEvent()
{
   data_1_master = Wire.read();
   data_2_master = Wire.read();
   data_3_master = Wire.read();
   data_4_master = Wire.read();

   // Serial.println(first_data_master); // 마스터로부터 수신된 데이터 출력
}
