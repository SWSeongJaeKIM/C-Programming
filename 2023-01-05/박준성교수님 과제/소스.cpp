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
    printf("������ ���⸦ ���߰� �����ø� -10�� ġ�ø� �˴ϴ�");
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
        printf("�Է��Ͻÿ�");
        scanf("%c", &A);      //�Է� A ���� B ���� C
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