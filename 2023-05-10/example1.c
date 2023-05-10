#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int solution(int num_apple, int num_carrot, int k) {
	int answer = 0;
	if (num_apple > num_carrot * 3) {
		answer = num_carrot;
		num_carrot = 0;
		num_apple -= num_carrot * 3;
		k -= num_apple;
	}
	else {
		answer = num_apple / 3;
		num_carrot -= num_apple / 3;
		num_apple = num_apple % 3;
		k -= (num_apple + num_carrot);
	}

	for (int i = 0; i < k; i++) {
		if (i % 4 == 0) {
			answer -= 1;
		}
	}

	return answer;
}

int main() {
	int num_apple1 = 5;
	int num_carrot1 = 1;
	int k1 = 1;
	int ret1 = solution(num_apple1, num_carrot1, k1);

	printf("solution 함수의 변환 값은 %d 입니다.\n", ret1);

	int num_apple2 = 10;
	int num_carrot2 = 5;
	int k2 = 4;
	int ret2 = solution(num_apple2, num_carrot2, k2);

	printf("solution 함수의 변환 값은 %d 입니다.\n", ret2);
	return 0;
}