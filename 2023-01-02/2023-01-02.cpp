#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 

void example1(void)     //���� ����
{
    FILE* fp;
        fp = fopen("data1.txt", "wt");
    if (fp == NULL)
    {
        printf("File Writing Error! \n  ");
        return ;// �������� ���Ḧ �ǹ��ϱ� ���ؼ� -1�� ��ȯ
    }
    else
    {
        printf("File Writing Success! \n  ");
    }
    fputc('A', fp);    //fprintf(fp, "%C", "A");
    fputc('B', fp);
    fputc('C', fp);
    fputc('\nDEF\n', fp);
    printf("%d \n"fclose(fp));      //��Ʈ���� ����


    return 1;
 }

void example2(void)     //���� �б�
{
    int i;
    char ch;
    FILE* fp;
    fp = fopen("data2.txt", "rt");

    if (fp == NULL)
    {
        printf("File Reading Error! \n  ");
        return ;// �������� ���Ḧ �ǹ��ϱ� ���ؼ� -1�� ��ȯ
    }
    else
    {
        printf("File Reading Success! \n  ");
    }
    for (i = 0; i < 7; i++)
    {
        //ch = fgetc(fp);
        fscanf(fp, "%c", &fp)
            printf("%c \n", ch);
    }
    fclose(fp);
    return 1;
}

int main(void)
{
    FILE* fp;
    int data1 = 0;
    double data2 = 0;
    int i = 0;
    fp = fopen("data3.txt", "rt");

    if (fp == NULL)
    {       
        //printf("File Writing Error! \n");
        puts("File Reading Error! \n");
        return -1;
    }
    else
    {
        printf("File Reading Success!\n");
    }
    for (i = 0; i < 2; i++)
    {
        fscanf(fp, "%d", &data1);
        printf("%d \n", data1);
    }
    for (i = 0; i < 2; i++)
    {
        fscanf(fp, "%lf", &data2);
        printf("%lf \n", data2);
    }
    fclose(fp);

    return 1;
}