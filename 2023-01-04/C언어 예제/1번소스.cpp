#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int A = 0;
	int B = 0;
	int C = 0; //�ӽ� ����
	while (1)
	{
		printf("1~10000�� ���� ������ ���� �ΰ��� �Է��Ͻÿ� ex)1\t5 \t");
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
			printf("���������� ������ϴ�");
			break;

		}
	}
}