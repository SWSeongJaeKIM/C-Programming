#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int T = 0;
    char str[255];
    int r = 0, c = 0;
    int c1 = 0, c2 = 0;
    int CHK1 = 0, CHK2 = 0, CHK3 = 0;
    int i = 0;
    int N = 0;
    scanf("%d%*c", &T);
    if (T >= 1 && T <= 30)
    {
        char** M = (char**)malloc(sizeof(char*) * T);
        for (r = 0; r < T; r++)
        {
            scanf("%s%*c", str);
            if (strlen(str) >= 3 && strlen(str) <= 100000)
            {
                M[r] = (char*)malloc(sizeof(char) * (strlen(str) + 1));
                strcpy(M[r], str);
            }
            else
                return 0;
        }
        for (r = 0; r < T; r++)
        {
            CHK1 = -1;
            N = strlen(M[r]);
            for (c = 0; c < N / 2; c++)
                if (M[r][c] != M[r][N - 1 - c])
                {
                    CHK1 = c;
                    break;
                }
            if (CHK1 == 1)
            {
                printf("0\n");
            }
            else
            {      
                c1 = c2 = 0;
                CHK2 = 0;
                CHK3 = 0;
                char* CHKStr1 = (char*)malloc(sizeof(char) * (strlen(M[r] + 1)));
                char* CHKStr2 = (char*)malloc(sizeof(char) * (strlen(M[r] + 1)));
                for (i = 0; i < N - 1; i++)
                {
                    if (i != CHK1) CHKStr1[c1++] = M[r][i];
                    if (i != N - 1 - CHK1) CHKStr2[c2++] = M[r][i];
                }

                /.
                for (i = 0; i < N - 1; i++)
                {
                    if (CHKStr1[i] != CHKStr1[N - 2 - i]) CHK2 = 1;
                    if (CHKStr2[i] != CHKStr2[N - 2 - i]) CHK3 = 1;
                }
                if (CHK2 == 1 && CHK3 == 1)
                    printf("2\n");
                else
                    printf("1\n")
                free(CHKStr1);
                free(CHKStr2);
            }
        }
        for (r = 0; r < T; r++)
        {
            free(M[r]);
            free(M);
        }
        return 0;
    }
}
