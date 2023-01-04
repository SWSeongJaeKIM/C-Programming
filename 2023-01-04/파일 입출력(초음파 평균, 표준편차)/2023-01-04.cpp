#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define MAX_data 300
float dis_total[MAX_data] = { -1, };

float r1(float dis_tot2[], int no_line)		//평균값 구해주는 함수
{	
	double unit = 0;
	double sum = 0.0;
	for (int i = 0; i < no_line; i++)
	{
		sum += dis_tot2[i];
		unit++;
	}
	printf("sum \t:\t%f\n",sum);
	sum = sum / unit;
	return sum;
}

float r2(float dis_tot2[], int no_line, double avr)		//표준편차 구해주는 함수
{
	double po = 0.0;
	double to1 = 0.0;
	double to2 = 0.0;
	double sum = 0.0;
	for (int i = 0; i < no_line; i++)
	{
		to1 = pow(dis_tot2[i] - avr,2);
		to2 += to1;
	}
	po = sqrt(to2 / no_line);
	return po;
	
}

int main()
{
	double result = 0.0;
	float dis = 0.0;
	int no_line = 0;
	float avr = 0.0;
	float sta = 0.0;

	FILE* fp = fopen("sonadata.txt", "r");

	if (fp == NULL)
	{
		printf("Connection complete");
	}
	else
	{
		do
		{
			result = fscanf(fp, "%f", &dis);
			dis_total[no_line] = dis;

			no_line++;

		} while (result != EOF);
		fclose(fp);
		dis_total[no_line - 1] = { 0, };
		no_line = no_line - 1;

		for (int i = 0; i < no_line; i++)
		{
			printf("%f \n", dis_total[i]);
		}
		printf("no_line\t:\t%d\n", no_line);


		avr = r1(dis_total, no_line);
		printf("total \t %f\n", avr);
		sta = r2(dis_total, no_line, avr);
		printf("sta \t %f", sta);
		return 0;
	}

	
}