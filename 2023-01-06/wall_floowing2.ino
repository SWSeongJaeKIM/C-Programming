#include <NewPing.h> 
#define MAX_DISTANCE 250
#define ERE 7
#define IN1 3// 1번째 모터
#define IN2 2// 1번째 모터
#define ENA 5// 1번째 모터  PWM제어
#define IN3 4   // 2번째 모터
#define IN4 7   // 2번째 모터
#define ENB 6   // 2번째 모터 PWM제어
float R_Sonar_Distance = 0.0;
float R_Sonar_Distance_old = 0.0;
float R_Sonar_Error = 0.0;
float L_Sonar_Distance = 0.0;
float L_Sonar_Distance_old = 0.0;
float L_Sonar_Error = 0.0;
float F_Sonar_Distance = 0.0;
float F_Sonar_Distance_old = 0.0;
float F_Sonar_Error = 0.0;

int motor_diff=0;

NewPing sonar[3] =
{
  NewPing (8, 8, MAX_DISTANCE),
  NewPing (10, 10, MAX_DISTANCE),
  NewPing (11, 11, MAX_DISTANCE),
  
};

void motor_control_l(int direction, int speed1, int speed2)    //방향 속도 1: 전진 2: 후진 3: 정지
{
  switch(direction)
  {
    case 2: digitalWrite(IN1, HIGH);
            digitalWrite(IN2, LOW);
            digitalWrite(IN3, LOW);
            digitalWrite(IN4, HIGH);           
            analogWrite(ENA, speed1);
            analogWrite(ENB, speed2);
            break;
  }
}

void read_sonar_sensor(void)  //초음파 센서 값을 읽는 함수
{
    
 R_Sonar_Distance = sonar[1].ping_cm() * 10;
 L_Sonar_Distance = sonar[2].ping_cm() * 10;
 F_Sonar_Distance = sonar[0].ping_cm() * 10;
 if(R_Sonar_Distance == 0) R_Sonar_Distance = MAX_DISTANCE *10.0;
 if(L_Sonar_Distance == 0) L_Sonar_Distance = MAX_DISTANCE *10.0;
 if(F_Sonar_Distance == 0) F_Sonar_Distance = MAX_DISTANCE *10.0;
}

void update_sonar_old(void)
{
  R_Sonar_Distance_old = R_Sonar_Distance;  //측정된거된값을 과거에 넣는다
  L_Sonar_Distance_old = L_Sonar_Distance;  //측정된거된값을 과거에 넣는다
  F_Sonar_Distance_old = F_Sonar_Distance;  //측정된거된값을 과거에 넣는다
}

void update_sonar_error(void)
{
  R_Sonar_Error = R_Sonar_Distance - 95;  //현재 값에서 옛날 값을 뺀것
  L_Sonar_Error = L_Sonar_Distance - 95;  //현재 값에서 옛날 값을 뺀것
  F_Sonar_Error = F_Sonar_Distance - 95;  //현재 값에서 옛날 값을 뺀것
}

void setup()
{
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
  Serial.begin(115200);
}

void loop() 
{
  
  //float p_gain =1.3;
  
  read_sonar_sensor();
 // update_sonar_error();
 // update_sonar_old();
  //motor_diff = R_Sonar_Error * p_gain; 
 
    /*Serial.print(R_Sonar_Distance); Serial.print("\t");
    Serial.print(R_Sonar_Distance_old); Serial.print("\t");
    Serial.println(R_Sonar_Error);
    motor_control_l(2,70+motor_d iff,70-motor_diff);
    delay(100);*/
   if(L_Sonar_Distance>200 && R_Sonar_Distance>200 )
    if(L_Sonar_Distance > R_Sonar_Distance)
    {
      motor_control_l(2,50,145);
    }
    else if(L_Sonar_Distance < R_Sonar_Distance && L_Sonar_Distance!=0 && L_Sonar_Distance!=0)
    {
      motor_control_l(2,145,50);
    }
    else if((L_Sonar_Distance == R_Sonar_Distance))
    {
      motor_control_l(2,130,130);      
    }
    
 
      
  
}
