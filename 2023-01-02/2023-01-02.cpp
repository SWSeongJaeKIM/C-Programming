#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
/*
//////////////////////////////////  파일 쓰기   //////////////////////////////////
int main()
{
    FILE *fp = fopen("data.txt","wt");
    if (fp == NULL)
    {
        printf("파일 오픈 실패!");
        return -1;// 비상식적인 종료를 의미하기 위해서 -1을 반환
    }
    fputc('A', fp);
    fputc('B', fp);
    fputc('C', fp);
    fclose(fp);      //스트림의 종료


    return 0;
}
//////////////////////////////////  파일 쓰기   //////////////////////////////////
*/

/*
//////////////////////////////////  파일 읽기   //////////////////////////////////
int main()
{
    int ch = 0;
    int i = 0;
    FILE* fp = fopen("data.txt", "rt");
    if (fp == NULL)
    {
        printf("파일 오픈 실패!");
        return -1;// 비상식적인 종료를 의미하기 위해서 -1을 반환
    }
    for (i = 0; i < 3; i++)
    {
        ch = fgetc(fp);
        printf("%c \n", ch);
    }
    fclose(fp);      //스트림의 종료


    return 0;
}
//////////////////////////////////  파일 읽기   //////////////////////////////////
*/

