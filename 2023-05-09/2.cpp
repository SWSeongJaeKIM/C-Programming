#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int speed, int car[], int cars_len)
{
	int answer = 0;
	for (int i = 0; i < cars_len; i++)
	{
		if (car[i] >= 110 && car[i] < 120) answer += 3;
		else if (car[i] >= 120 && car[i] < 130) answer += 5;
		else if (car[i] >= 130) answer += 7;
	}
	return answer;
}

int main()
{
	int speed = 100;
	int cars[] = { 110, 98, 125, 148, 120, 112, 89 };
	int cars_len = 7;
	int ret = solution(speed, cars, cars_len);
	printf("solution 함수의 반환값은 %d입니다.\n", ret);
}