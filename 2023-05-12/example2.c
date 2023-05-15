#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int solution(int programs[][2], int programs_len) {
    const int MAX_TV = 25;
    int answer = 0;
    int used_tv[MAX_TV] = {0};

    for (int i = 0; i < programs_len; i++) {
        int start_time = programs[i][0];
        int end_time = programs[i][1];

        for (int j = start_time; j <= end_time; j++) {
            used_tv[j]++;
        }
    }

    for (int i = 0; i < MAX_TV; i++) {
        if (used_tv[i] >= 2) {
            answer++;
        }
    }

    return answer;
}

int main() {

	int programs[][2] = { {1,6},{3,5},{2,8} };
	int programs_len = 3;
	int ret = solution(programs, programs_len);
	printf("solution %d.\n", ret);

	return 0;
}