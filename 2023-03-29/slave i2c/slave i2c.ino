#include <Wire.h>

// 자신의 슬레이브 주소를 설정해 줍니다.(슬레이브 주소에 맞게 수정해야 합니다.)
#define SLAVE 4
#define ADC         A0

#define numbuttons1 22
#define numbuttons2 23
#define numbuttons3 24
#define numbuttons4 25
#define numbuttons5 26
#define numbuttons6 27
#define numbuttons7 28
#define numbuttons8 29

#define LED1    30
#define LED2    31
#define LED3    32
#define LED4    33
#define LED5    34
#define LED6    35
#define LED7    36
#define LED8    37


int ADC_val = 0;
int bt[8] = {0, };
int led_val[8] = {0, };
int sum;
int led_a = 0;
int led_a_2 = 0;

//int[] buttonValues = {0,0,0,0,0,0,0,0};


// 카운터
byte count = 0; 
char temp;


union
{
  unsigned int adc_re;
  unsigned char adc_ch[2];
}adc_val_2;

///////////////////////////////////////////////////////
void control_led(int data)
{
    for(int i=0; i<=7; i++)       // data의 2진수 표현을 8비트로 나누어서, 각각의 비트에 대해 아래 코드를 실행
    {
        if(data>>i & 1 == 1)      // i번째 비트가 1인지 확인
            led_val[i] = 1;   // i번째 비트가 1이면 OUTPUT_buff[i]에 1 저장
        else
            led_val[i] = 0;   // i번째 비트가 0이면 OUTPUT_buff[i]에 0 저장
    }

                                  // OUTPUT_buff 값에 따라 각각의 LED를 켜거나 끄는 동작 수행
    (led_val[0] == 1) ?  digitalWrite(LED1, HIGH) : digitalWrite(LED1, LOW);
    (led_val[1] == 1) ?  digitalWrite(LED2, HIGH) : digitalWrite(LED2, LOW);
    (led_val[2] == 1) ?  digitalWrite(LED3, HIGH) : digitalWrite(LED3, LOW);
    (led_val[3] == 1) ?  digitalWrite(LED4, HIGH) : digitalWrite(LED4, LOW);
    (led_val[4] == 1) ?  digitalWrite(LED5, HIGH) : digitalWrite(LED5, LOW);
    (led_val[5] == 1) ?  digitalWrite(LED6, HIGH) : digitalWrite(LED6, LOW);
    (led_val[6] == 1) ?  digitalWrite(LED7, HIGH) : digitalWrite(LED7, LOW);
    (led_val[7] == 1) ?  digitalWrite(LED8, HIGH) : digitalWrite(LED8, LOW);
}




/////////////////////////////////////////////////////////


void setup()
{
  // Wire 라이브러리 초기화
  // 슬레이브로 참여하기 위해서는 주소를 지정해야 한다.
  Wire.begin(SLAVE);
  Wire.onReceive(receiveFromMaster);
  // 마스터의 데이터 전송 요구가 있을 때 처리할 함수 등록
  Wire.onRequest(sendToMaster);

  //버튼 IO설정
  pinMode(22, INPUT);
  pinMode(23, INPUT);
  pinMode(24, INPUT);
  pinMode(25, INPUT);
  pinMode(26, INPUT);
  pinMode(27, INPUT);
  pinMode(28, INPUT);
  pinMode(29, INPUT);



  //보드레이트 설정
  Serial.begin(115200);
 
}

void button()
{
  int button_state1 = digitalRead(22);
  int button_state2 = digitalRead(23);
  int button_state3 = digitalRead(24);
  int button_state4 = digitalRead(25);
  int button_state5 = digitalRead(26);
  int button_state6 = digitalRead(27);
  int button_state7 = digitalRead(28);
  int button_state8 = digitalRead(29);

  if(button_state1 ==HIGH)  bt[0] = 0;
  else                      bt[0] = 1;

  if(button_state2 ==HIGH)  bt[1] = 0;
  else                      bt[1] = 1;

  if(button_state3 ==HIGH)  bt[2] = 0;
  else                      bt[2] = 1;

  if(button_state4 ==HIGH)  bt[3] = 0;
  else                      bt[3] = 1;

  if(button_state5 ==HIGH)  bt[4] = 0;
  else                      bt[4] = 1;

  if(button_state6 ==HIGH)  bt[5] = 0;
  else                      bt[5] = 1;

  if(button_state7 ==HIGH)  bt[6] = 0;
  else                      bt[6] = 1;

  if(button_state8 ==HIGH)  bt[7] = 0;
  else                      bt[7] = 1;
}


void ADC_data_save()
{
  ADC_val = analogRead(ADC);
  //Serial.println(ADC_val);
  adc_val_2.adc_re = ADC_val;
}


void loop ()
{
  button();
  button_calculation();
  ADC_data_save();
  Wire.onReceive(receiveEvent); 
     if(led_a != -1)
   {
  
    led_a_2= led_a; 
  
  }

     led_a=led_a_2;     
     Serial.println(led_a_2);
     Serial.println(sum);
     Serial.println(ADC_val);
    control_led(led_a_2);
  // 요청이 들어오면 13번 LED를 0.5초간 켜줍니다.

 // Serial.println(sum);

}


void receiveEvent(int byteCount) {
  if (byteCount == sizeof(led_a)) { // 받은 데이터의 크기가 변수의 크기와 같은지 확인
    Wire.readBytes((uint8_t*)&led_a, sizeof(led_a)); // 받은 바이트를 변수값으로 변환하여 저장
    // 받은 변수값을 시리얼 모니터에 출력
  }
}



void receiveFromMaster(int bytes)
{
  char ch[2];
  for (int i = 0 ; i < bytes ; i++)
  {
    // 수신 버퍼 읽기
    ch[i] = Wire.read(); 
  }
  temp = ch[0];
  
}


void button_calculation()
{
  /*
  for(int i=0; i<=7; i++)
  {
    if(numButtons[i]>>i&1 == 1)    buttonValues[numButtons] = 1;
    else                        buttonValues[numButtons] = 0;
  }
  */
sum = 0;
sum = (bt[0] << 0) | (bt[1] << 1) | (bt[2] << 2) | (bt[3] << 3) | (bt[4] << 4) | (bt[5] << 5) | (bt[6] << 6) | (bt[7] << 7);


/*
    sum = 0;
    if(bt[0] == 1)    sum = sum+1;
    if(bt[1] == 1)    sum = sum+2;
    if(bt[2] == 1)    sum = sum+4;
    if(bt[3] == 1)    sum = sum+8;
    if(bt[4] == 1)    sum = sum+16;
    if(bt[5] == 1)    sum = sum+32;
    if(bt[6] == 1)    sum = sum+64;
    if(bt[7] == 1)    sum = sum+128;

    //temp = 0;
    */
}




void sendToMaster()
{
  Wire.write(sum);                 //Button Data 전송
  Wire.write(adc_val_2.adc_ch[0]); //ADC 상위 1 바이트 값 전송
  Wire.write(adc_val_2.adc_ch[1]); //ADC 하위 1 바이트 값 전송 
  
}