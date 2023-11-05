#include <stdio.h>

#define SWAP(a,b)  {int t; t = a; a=b; b=t;}//a�� b�� ��ȯ
void SequenceSort(int* base, int n);
void BubbleSort(int* base, int n);
void SelectionSort(int* base, int n);
void InsertionSort(int* base, int n);
void ShellSort(int* base, int n);
void InsertionSort2(int* base, int size, int step);




int main(void)
{
    int* origin;
    int on;
    int arr[10] = { 9,4,3,10,5,8,7,6,2,1 };
    SequenceSort(arr, 10);
    BubbleSort(arr, 10);
    SelectionSort(arr, 10);
    InsertionSort(arr, 10);

    origin = arr;
    on = 10;
    ShellSort(arr, 10);


    return 0;
}
void ViewArr(int* arr, int n);
void BubbleSort(int* base, int n);
void SelectionSort(int* base, int n);
void InsertionSort(int* base, int n);
void ShellSort(int* base, int size);
void InsertionSort2(int* base, int size, int step);







void ShellSort(int* base, int size)

{
        int i, step;
    for (step = size / 2; step > 0; step /= 2)//step�� ���� 1/2�� �ٿ�����.
    {
        printf("step:%d\n", step);
        for (i = 0; i < step; i++) //step ���ݿ� �ִ� ��ҵ��� ��������
        {
            InsertionSort2(base + i, size - i, step);
        }
    }
 }



void InsertionSort2(int* base, int size, int step)
{
     int i, j;
         for (i = step; i < size; i += step)//���� ��� ���Ҵ� step �������� �̵�
    {
        for (j = i; j > 0; j -= step)//step �������� ������ �̵�
        {
            if (base[j - step] > base[j])//������ �� Ŭ ��
            {
                SWAP(base[j - step], base[j]);//��ȯ
                ViewArr(origin, on);
            }
            else
            {
                break;
            }
        }
    }
}


void InsertionSort(int* base, int n)
{
    int i, j;
    ViewArr(base, n);//���� ���� ���
    for (i = 1; i < n; i++)//������ ������ Ȯ���� �����ϴ�.
    {
        for (j = i; j > 0; j--)
        {
            if (base[j - 1] > base[j])//���� ���Ұ� �� ũ��
            {
                SWAP(base[j - 1], base[j]);//��ȯ
                ViewArr(base, n);//���� ���
            }
            else
            {
                break;
            }
        }
    }
}





void SelectionSort(int* base, int n)
{
     int i, j;
    int maxi;
        ViewArr(base, n);//���� ���� ���
    for (i = n; i > 1; i--)//������ ������ ����� �����ϴ�.
         {
                maxi = 0;
        for (j = 1; j < i; j++)
        {
            if (base[maxi] < base[j])//�� ū ���Ҹ� ������
            {
                maxi = j;
            }
        }
        SWAP(base[maxi], base[i - 1]);//��ȯ
        ViewArr(base, n);//���� ���
    }
}


void BubbleSort(int* base, int n)
{
    int i, j;
    ViewArr(base, n);//���� ���� ���
    for (i = n; i > 1; i--)//������ ������ ����� �����ϴ�.
    {
        for (j = 1; j < i; j++)
        {
            if (base[j - 1] > base[j])//���� ���Ұ� �� ũ��
            {
                SWAP(base[j - 1], base[j]);//��ȯ
                ViewArr(base, n);//���� ���
            }
        }
    }
}







void SequenceSort(int* base, int n)
{
    int i, j;
    ViewArr(base, n);//���� ���� ���
        for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            if (base[i] > base[j])//���� ���Ұ� �� ũ��
            {
                SWAP(base[i], base[j]);//��ȯ
                ViewArr(base, n);//���� ���
            }
        }
    }
}


void ViewArr(int* arr, int n)
{
    int i = 0;
        for (i = 0; i < n; i++)
    {
        printf("%2d ", arr[i]);
    }
            printf("\n");
}