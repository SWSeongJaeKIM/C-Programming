#include <stdio.h>

#define SWAP(a,b)  {int t; t = a; a=b; b=t;}//a와 b를 교환
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
    for (step = size / 2; step > 0; step /= 2)//step의 폭을 1/2로 줄여간다.
    {
        printf("step:%d\n", step);
        for (i = 0; i < step; i++) //step 간격에 있는 요소들을 삽입정렬
        {
            InsertionSort2(base + i, size - i, step);
        }
    }
 }



void InsertionSort2(int* base, int size, int step)
{
     int i, j;
         for (i = step; i < size; i += step)//정렬 대상 원소는 step 간격으로 이동
    {
        for (j = i; j > 0; j -= step)//step 간격으로 앞으로 이동
        {
            if (base[j - step] > base[j])//앞쪽이 더 클 때
            {
                SWAP(base[j - step], base[j]);//교환
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
    ViewArr(base, n);//현재 상태 출력
    for (i = 1; i < n; i++)//정렬할 범위를 확대해 나갑니다.
    {
        for (j = i; j > 0; j--)
        {
            if (base[j - 1] > base[j])//앞쪽 원소가 더 크면
            {
                SWAP(base[j - 1], base[j]);//교환
                ViewArr(base, n);//상태 출력
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
        ViewArr(base, n);//현재 상태 출력
    for (i = n; i > 1; i--)//정렬할 범위를 축소해 나갑니다.
         {
                maxi = 0;
        for (j = 1; j < i; j++)
        {
            if (base[maxi] < base[j])//더 큰 원소를 만나면
            {
                maxi = j;
            }
        }
        SWAP(base[maxi], base[i - 1]);//교환
        ViewArr(base, n);//상태 출력
    }
}


void BubbleSort(int* base, int n)
{
    int i, j;
    ViewArr(base, n);//현재 상태 출력
    for (i = n; i > 1; i--)//정렬할 범위를 축소해 나갑니다.
    {
        for (j = 1; j < i; j++)
        {
            if (base[j - 1] > base[j])//앞쪽 원소가 더 크면
            {
                SWAP(base[j - 1], base[j]);//교환
                ViewArr(base, n);//상태 출력
            }
        }
    }
}







void SequenceSort(int* base, int n)
{
    int i, j;
    ViewArr(base, n);//현재 상태 출력
        for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            if (base[i] > base[j])//앞쪽 원소가 더 크면
            {
                SWAP(base[i], base[j]);//교환
                ViewArr(base, n);//상태 출력
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