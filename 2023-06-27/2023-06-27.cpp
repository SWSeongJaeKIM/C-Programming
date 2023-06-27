#include <stdio.h>
#include <stdlib.h>

#define No_Calibriton_Point 5 //데이터 수

struct {
    double X[No_Calibriton_Point]; //x값
    double Y[No_Calibriton_Point]; //y값
}cal_data;


double linear_mapping(double x) {
    double y;
    int i = 0;

    while (i < No_Calibriton_Point) {
        if (x <= cal_data.X[0]) { // x값이 범위 아래로 있을 때
            y = ((cal_data.Y[0] - cal_data.Y[1]) / (cal_data.X[0] - cal_data.X[1])) * (x - cal_data.X[1]) + cal_data.Y[1]; // 처음으로 생성된 선형 함수 이용
            break;
        }
        else if (x > cal_data.X[i] && x <= cal_data.X[i + 1]) { // x값이 범위 안에 있을 때
            y = ((cal_data.Y[i] - cal_data.Y[i + 1]) / (cal_data.X[i] - cal_data.X[i + 1])) * (x - cal_data.X[i + 1]) + cal_data.Y[i + 1]; // 범위 안에 있는 선형 함수를 이용
            break;
        }
        else if (x >= cal_data.X[No_Calibriton_Point - 1]) { // 값이 범위 위에 있을 때
            y = ((cal_data.Y[No_Calibriton_Point - 1] - cal_data.Y[No_Calibriton_Point - 2]) / (cal_data.X[No_Calibriton_Point - 1] - cal_data.X[No_Calibriton_Point - 2])) * (x - cal_data.X[No_Calibriton_Point - 2]) + cal_data.Y[No_Calibriton_Point - 2]; // 마지막으로 생성된 선형 함수 이용
            break;
        }

        i++;
    }

    return y;
}

int main()
{
    cal_data =
    {
       {0.0, 1.0, 2.0, 3.0, 4.0},  // X 범위
       {10.0, 20.0, 30.0, 40.0, 50.0}  // y 값
    };

    double y = linear_mapping(3.5);

    printf("result : %lf \n", y);
}