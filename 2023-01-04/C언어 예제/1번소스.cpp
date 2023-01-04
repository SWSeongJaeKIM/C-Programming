#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int A = 0;
	int B = 0;
	int C = 0; //임시 변수
	while (1)
	{
		printf("1~10000의 수중 임의의 정수 두개를 입력하시오 ex)1\t5 \t");
		scanf("%d %d", &A, &B);
		if (A > 0 && A < 10000 && B > 0 && B < 10000)
		{
			if (A > B)
			{
				C = A;
				A = B;
				B = C;
			}
			printf("N:%d	M:%d \n", A, B );
			for (int i = A; i < B+1; i++)
			{
				printf("%d  ", i);
			}
			return 0;
		}
		else
		{
			printf("범위값에서 벗어났습니다");
			break;

		}
	}
}