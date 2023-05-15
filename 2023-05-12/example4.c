#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int* solution(const char* schedule[], int schedule_len) {
    int count = 0;

 
    for (int i = 0; i < schedule_len; i++) {
        if (strcmp(schedule[i], "x") == 0) {
            count++;
        }
    }

    int* answer = (int*)malloc(sizeof(int) * count);

    int answerIndex = 0; 

    
    for (int i = 0; i < schedule_len; i++) {
        if (strcmp(schedule[i], "x") == 0) {
            answer[answerIndex] = i + 1;
            answerIndex++;
        }
    }

    return answer;
}

int main() {

	const char* schedule[] = { "o","x","x","o","o","o","x","o","x","x" };
	int schedule_len = 10;
	int* ret = solution(schedule, schedule_len);
	printf("solution %d ");
	for (int i = 0; i < 5; i++) {
		printf("%d, ", ret[i]);
	}
	printf("입니다.");
	return 0;
}