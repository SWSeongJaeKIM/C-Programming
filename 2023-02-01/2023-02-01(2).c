#include <stdio.h>
#include <stdlib.h>
double data[5]={0, };
double old_A=0;
double new_A=0;
int A=1;

void nom_avr(double a,int A);
void data_input (double a)


int main(void){
	double b=0;
		for(int i=0; i<5; i++)
       {
		printf("Plese input : ");
		scanf("%f",&b);
		nom_avr (b,A);
		A = A+1;
		printf("%f \n",new_A);
		data[i]=b;
	}
	while(1){
		
		printf("Plese input ");
		scanf("%f",&b);
		data_input(b);
		printf("%f \n",new_A);
	}
}

void nom_avr (double a,int A)
{
    new_A = (old_A*(A-1)/A)+(a/A);
    old_A = new_A;
}
 void data_input (double a){
	 for(int i=1; i<=5; i++)
	{
		 data[i]=data[i+1];
	 }

     data[4]=a;
     new_A=old_A+(data[4]-data[0])/5;
     old_A=new_A ;
  }