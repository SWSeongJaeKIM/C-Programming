#include <NewPing.h>    //NewPing(초음파 라이브러리) 선언

NewPing sonar[3] =
{
  NewPing (8, 8, 500),
  NewPing (10, 10, 500),
  NewPing (11, 11, 500),
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


void motor_control_l(int direction, int speed1, int speed2)    //방향 속도 1: 전진 2: 후진 3: 정지
{
  switch(direction)
  {
    case 1: digitalWrite(IN1, HIGH);
            digitalWrite(IN2, LOW);
            digitalWrite(IN3, HIGH);
            digitalWrite(IN4, LOW);
            analogWrite(ENA, speed1);
            analogWrite(ENB, speed2);// 0-255까지 입력
            break;

    case 2: digitalWrite(IN1, LOW);
            digitalWrite(IN2, HIGH);
            digitalWrite(IN3, LOW);
            digitalWrite(IN4, HIGH);           
            analogWrite(ENA, speed1);
            analogWrite(ENB, speed2);
            break;

    case 3: digitalWrite(IN1,LOW);
            digitalWrite(IN2,LOW);
            digitalWrite(IN3,LOW);
            digitalWrite(IN4,LOW);
            analogWrite(ENA, 0);
            analogWrite(ENA, 0);
            break;

  }
}
void Ang_Calcul()
{
      Serial.println();
           
  double dist =0;
  double disf1=0;
  double disf3=0;
  double disf2=0;
  double disf4=0;
  double ang =0;
   delay(300);
   F_distance = sonar[0].ping_cm() * 10;
   R_distance = sonar[1].ping_cm() * 10;
   L_distance = sonar[2].ping_cm() * 10;      
  
    delay(300);
    dist=F_distance;
    disf2=L_distance;
    motor_control_l(2,70,70);
    delay(800);
    motor_control_l(2,0,0);
    delay(300);
    L_distance = sonar[1].ping_cm() * 10;
    F_distance = sonar[0].ping_cm() * 10;
   disf2=F_distance;
    disf4=R_distance;
    disf1 = dist - disf2;
        Serial.print("F_Total\t:\t");
        Serial.print(dist); 
        Serial.println();
        Serial.print("F_D1\t:\t");
        Serial.print(disf1); 
        Serial.println();
        Serial.print("F_D2\t:\t");
        Serial.print(disf2);
        Serial.println();   
        Serial.print("L_D1\t:\t");
        Serial.print(disf2);
        Serial.println();
        Serial.print("L_D2\t:\t");
        Serial.print(disf4);
        Serial.println();
        Serial.println();
        ang=atan((disf2-disf4)/dist);
        ang= ang * 180 /3.1415;
        Serial.println();
        Serial.println();
        Serial.println();
        Serial.print("Angle \t:\t");
        Serial.println(ang);
        
}


void setup()
{
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    Serial.begin(115200);

    Ang_Calcul();
     
}

void loop()

{




             
} 
