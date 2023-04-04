#include <Wire.h>
#include <MsTimer2.h>

#define SLAVE 4
#define start_chack   4

volatile int sum = 0;
volatile int ADC_val_1 = 0;
volatile int ADC_val_2 = 0;
volatile int pro_butten = 0;
volatile int butten_33 = 0;
int flag = 0;
volatile bool isInterrupted = false;

union
{
  unsigned int adc_re;
  unsigned char adc_ch[2];
} adc_val_2;

void onTimer() {
  digitalWrite(start_chack, HIGH);
  flag = 1;
  butten_33 = Serial.read();
  pro_butten = butten_33;
  adc_val_2.adc_ch[0] = ADC_val_1;
  adc_val_2.adc_ch[1] = ADC_val_2;
  Serial.write(sum); // 버튼 총합 값
  Serial.write(ADC_val_1); // ADC 값 1
  Serial.write(ADC_val_2); // ADC 값 2
  Serial.write("\n"); // 프로세싱 마지막 \n
  digitalWrite(start_chack, LOW);
 }

void setup()
{
  pinMode(start_chack, OUTPUT);
  Serial.begin(115200);
  Wire.begin();
  MsTimer2::set(1, onTimer);   //1.25
  MsTimer2::start();
}

void loop()
{
  if(flag == 1)
  {
   Wire.requestFrom(SLAVE, 3);
  sum = Wire.read();
  ADC_val_1 = Wire.read();
  ADC_val_2 = Wire.read();
  Wire.beginTransmission(SLAVE);
  Wire.write((uint8_t*)&pro_butten, sizeof(pro_butten));
  Wire.endTransmission();

  flag = 0;
  }
}
