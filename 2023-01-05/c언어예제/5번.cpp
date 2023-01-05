#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int N = 1;
    int Ans = 1;
    scanf("%d", &N);
    if (N >= 1 && N <= 100)
    {
        while (N > 1)
        {
            N >>= 1;
            Ans <<= 1;
        }
        printf("\n%d\n", Ans);
    }
    return 0;
}