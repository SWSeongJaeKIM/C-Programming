#include <NewPing.h>

NewPing sonar[3] = {
  NewPing(8, 9, 300),
  NewPing(10, 11, 300),
  NewPing(12, 13, 300)
}
double F_sonar_er = 0.0;
double F_sonar_dis = 0.0;
double F_sonar_old = 0.0;

double R_sonar_er = 0.0;
double R_sonar_dis = 0.0;
double R_sonar_old = 0.0;

double L_sonar_er = 0.0;
double L_sonar_dis = 0.0;
double L_sonar_old = 0.0;

double righ_avg_old =0.0;
double lift_avg_old =0.0;
double front_avg_old =0.0;

double righ_avg_new =0.0;
double lift_avg_new =0.0;
double front_avg_new =0.0;

double righ_a[5] = {0,}
double left_a[5] = {0,}
double front_a[5] = {0,}
void sona_mm (void)
{
  L_sonar_dis = sonar[0].ping_cm()*10;
  R_sonar_dis = sonar[1].ping_cm()*10;
  F_sonar_dis = sonar[2].ping_cm()*10;
}
void nomal_data(void)
{
  for(int i=1; i<=4; i++)
  {
    front_a[i]=front_a[i+1];
    right_a[i]=right_a[i+1];
    left_a[i]=left_a[i+1];
  }
  front_a[3] = F_sonar_dis;
  front_avg_new = F_sonar_old + (front_a[3]-front_a[1])/5;
  F_sonar_old = front_avg_new;
  
  left_a[3] = L_sonar_dis;
  left_avg_new = L_sonar_old + (left_a[3]-left_a[1])/5;
  L_sonar_old = left_avg_new;
  
  right_a[3] = R_sonar_dis;
  right_avg_new = R_sonar_old + (right_a[3]-right_a[1])/5;
  R_sonar_old = right_avg_new;
}

void nomal (int A)
{
  front_avg_new = (F_sonar_old*(A-1)/A)+(F_sonar_dis/A);
  F_sonar_old = front_avg_new;
  
  left_avg_new = (L_sonar_old*(A-1)/A)+(L_sonar_dis/A);
  L_sonar_old = left_avg_new;
  
  right_avg_new = (R_sonar_old*(A-1)/A)+(R_sonar_dis/A);
  R_sonar_old = right_avg_new;
}



void setup()
{
  for(int a = 1; a<=5; a++)
  {
    sona_mm;
    nomal(a);
    front_a[5-i] = F_sonar_dis;
    left_a[5-i] = L_sonar_dis;
    right_a[5-i] = R_sonar_dis;
  }
  Serial.begin(11520);
}

void loop() 
{
sona_mm;
nomal(a);

}
