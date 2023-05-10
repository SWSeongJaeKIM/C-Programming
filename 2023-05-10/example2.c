#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int solution(int member_age[], int member_age_len, const char* transportations)
{
	int answer = 0;
		
	int* sum[2] = {0, };
	int* sum2[2] = {0, };
	
	for(int i = 0 i < member_age_len; i++)
	{
		if (member_age[i] <=20) sum2[0]++;
		else sum2[1]++;
	}
	
	if(transportations == "Bus")
	{
		sum[0] = 40000;
		sum[1] = 15000;		
	}
	else if(transportations == "Ship") 	
	{
		sum[0] = 30000;
		sum[1] = 13000;
	}
	else if(transportations == "Airplane") 	
	{
		sum[0] = 70000;
		sum[1] = 45000;
	}
	
	sum1[0] = sum1[0] * sum2[0];
	sum1[1] = sum1[1] * sum2[1];

	if (member_age_len >= 10) {
		num1[0] = (float)(num1[0] * 0.9);
		num1[1] = (float)(num1[1] * 0.8);
	}
	answer = sum1[0] + sum1[1];





	return answer;
}

int main() {
	int member_age1[5] = { 13,33,45,11,20 };
	int member_age1_len = 5;
	const char* transportations1 = (char*)malloc(sizeof(char)*3);
	transportations1 = "Bus";
	int ret1= solution(member_age1,member_age1_len,transportations1);

	printf("solution 함수의 변환 값은 %d 입니다.\n", ret1);

	

	int member_age2[10] = { 25,11,27,56,7,19,52,31,77,8 };
	int member_age2_len = 10;
	const char* transportations2 = (char*)malloc(sizeof(char) * 4);
	transportations2 = "Ship";
	int ret2 = solution(member_age2, member_age2_len, transportations2);

	printf("solution 함수의 변환 값은 %d 입니다.\n", ret2);


	return 0;
}