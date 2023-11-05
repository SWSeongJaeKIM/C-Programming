#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int i = 0;
    int buf[5] = { 0, };
    int temp = 0;
    while (1)
    {
        scanf("%d", &buf[temp]);
        temp++;
        for (int j = 0; j < 5; j++)printf("%d ", buf[j]);
        printf("\n");

        if (temp >= 5) temp = 0;

    }
    return 0;
}