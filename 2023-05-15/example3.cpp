#include < stdio.h>
#include < stdbool.h>
#include < stdlib.h>
int solution(int arr[], int arr_len)
{
	int answer = 0;
	int temp = 0;
	for (int i = 0; i < arr_len; i++)
	{
		temp = arr[i] / 2;
		for (int j = 0; j < arr_len; j++)
		{
			if (temp == arr[j])
			{
				answer++;
				break;
			}
		}
	}
	return answer;
}

int main()
{
	int arr[] = { 4, 8, 3, 6, 3 };
	int arr_len = 5;
	int ret = solution(arr, arr_len);
	printf("solution 함수의 반환 값은 %d 입니다. \n",ret);
}