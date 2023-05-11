#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int solution(int korea, int english)
{
  	int avg = 210-(korea+english);
	return avg;
}
int main()
{
	int korea = 70;
	int english = 60;
	int ret = solution(korea, english);
	printf("solution 함수의 값은 %d 입니다. \n", ret);
}