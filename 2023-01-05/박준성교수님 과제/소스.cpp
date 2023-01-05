#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int DATA[20] = { 0, };
int dex = 0;
int dex2 = 0;
int count = 0;


int insert(void)
{
    int head;
    int dex3;
    int dex4 = 0;

    int dex5 = 0;
    int dex6 = 0;
    int line = 0;
    printf("데이터 쓰기를 멈추고 싶으시면 -10을 치시면 됩니다");
    while (1)
    {
        scanf("%d", &head);
        if (head == -10)break;
        DATA[dex] = head;
        dex++;
    }
    memmove(DATA + 1, DATA, sizeof(int) * 9);
    DATA[0] = 0;


    return 0;
}



int live(void)
{
    printf("\n");
    for (int i = 1; i < 10; i++)
    {
        printf("%d\t", DATA[i]);
    }
    return 0;
}

int main()
{
    while (1)
    {
        char A;
        printf("입력하시오");
        scanf("%c", &A);      //입력 A 빼기 B 쓰기 C
        switch (A)
        {
        case 'A':
            insert();
            break;
        case 'B':
            live();
            break;
        case 'c':
            //deinsert();
            break;

        }
    }
}