#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int a, int b)
{
	int answer = 0;
	
	for (answer = 1; answer <= a*b; answer++)
	{
		if ((answer%a == 0) && (answer%b == 0))
		{
			break;
		}
	}

	return answer;
}

int main()
{
	int a = 4;
	int b = 6;
	int ret = solution(a, b);
	printf("soloution �Լ��� ��ȯ���� %d �Դϴ� \n", ret);
	return 0;
}
