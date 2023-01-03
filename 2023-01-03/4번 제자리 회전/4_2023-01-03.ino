#include <NewPing.h>    //NewPing(초음파 라이브러리) 선언
#define MAX_DS 100
NewPing sonar[3] =
{
  NewPing (8, 8, 200),
  NewPing (10, 10, 200),
  NewPing (11, 11, 200),
  
};

#define IN1 2// 1번째 모터
#define IN2 3// 1번째 모터
#define ENA 5// 1번째 모터  PWM제어

#define IN3 4   // 2번째 모터
#define IN4 7   // 2번째 모터
#define ENB 6   // 2번째 모터 PWM제어
int speed = 0;

double F_distance =0;
double L_distance =0;
double R_distance =0;


void motor_control_l(int direction, int speed1, int speed2)
{
  switch(direction)
  {
    case 1: digitalWrite(IN1, LOW);
            digitalWrite(IN2, LOW);
            digitalWrite(IN3, LOW);
            digitalWrite(IN4, LOW);
            analogWrite(ENA, speed1);
            analogWrite(ENB, speed2);// 0-255까지 입력
            break;

    case 2: digitalWrite(IN1, LOW);
            digitalWrite(IN2, HIGH);
            digitalWrite(IN3, HIGH);
            digitalWrite(IN4, LOW);           
            analogWrite(ENA, speed1);
            analogWrite(ENB, speed2);
            break;

    case 3: digitalWrite(IN1,HIGH);
            digitalWrite(IN2,LOW);
            digitalWrite(IN3,LOW);
            digitalWrite(IN4,HIGH);
            analogWrite(ENA, speed1);
            analogWrite(ENA, speed2);
            break;

  }
}


void setup()
{
    int i=0;
    double mini_dis =0.0;
    double mini_dis2 =0.0;
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    Serial.begin(115200);
  R_distance = sonar[2].ping_cm() * 10; 
  L_distance = sonar[1].ping_cm() * 10; 
  F_distance = sonar[0].ping_cm() * 10; 
  mini_dis = F_distance;
  for(i=0; i<400; i++)
  {   
    motor_control_l(2,90,90);
    F_distance = sonar[0].ping_cm() * 10;    
    mini_dis2 = F_distance;
    if (mini_dis > mini_dis2)
    {
      mini_dis = mini_dis2;
    }
    
    if(F_distance < MAX_DS)
    {
        F_distance = MAX_DS;
    }
    Serial.println(F_distance);
    
  }
   motor_control_l(1,0,0);
   delay(1000);
   Serial.println("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
   Serial.println(mini_dis);    //최소값 추출 완료
   Serial.println("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
   
   while(1)
   {     motor_control_l(2,90,90);
    
      R_distance = sonar[2].ping_cm() * 10; 
       L_distance = sonar[1].ping_cm() * 10; 
            Serial.println("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
            Serial.println(L_distance);     //최소값을 따라가야할 L값
            Serial.println(R_distance);     //최소값을 따라가야할 R값
            Serial.println("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
         if(L_distance < mini_dis+1 && L_distance > mini_dis -1)
         {
          delay(250);
            Serial.println("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ"); 
            Serial.println("왼쪽이 더먼저 최소값에 도달하였습니다. 정지합니다.");     //정상작동할시 뜨는 문구
            Serial.println("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
         motor_control_l(2,0,0);
         break;
         
         }
         else if(R_distance < mini_dis +1 && R_distance > mini_dis -1)
         {
          delay(250);
            Serial.println("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ"); 
            Serial.println("오른쪽이 더먼저 최소값에 도달하였습니다. 정지합니다.");     //정상작동할시 뜨는 문구
            Serial.println("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
         motor_control_l(2,0,0);
          break;
         }
           
   }
       
          
     
}

void loop()

{



             
} 
