#include <stdio.h>
#include <stdlib.h>

#define No_Calibriton_Point 5 //������ ��

struct {
    double X[No_Calibriton_Point]; //x��
    double Y[No_Calibriton_Point]; //y��
}cal_data;


double linear_mapping(double x) {
    double y;
    int i = 0;

    while (i < No_Calibriton_Point) {
        if (x <= cal_data.X[0]) { // x���� ���� �Ʒ��� ���� ��
            y = ((cal_data.Y[0] - cal_data.Y[1]) / (cal_data.X[0] - cal_data.X[1])) * (x - cal_data.X[1]) + cal_data.Y[1]; // ó������ ������ ���� �Լ� �̿�
            break;
        }
        else if (x > cal_data.X[i] && x <= cal_data.X[i + 1]) { // x���� ���� �ȿ� ���� ��
            y = ((cal_data.Y[i] - cal_data.Y[i + 1]) / (cal_data.X[i] - cal_data.X[i + 1])) * (x - cal_data.X[i + 1]) + cal_data.Y[i + 1]; // ���� �ȿ� �ִ� ���� �Լ��� �̿�
            break;
        }
        else if (x >= cal_data.X[No_Calibriton_Point - 1]) { // ���� ���� ���� ���� ��
            y = ((cal_data.Y[No_Calibriton_Point - 1] - cal_data.Y[No_Calibriton_Point - 2]) / (cal_data.X[No_Calibriton_Point - 1] - cal_data.X[No_Calibriton_Point - 2])) * (x - cal_data.X[No_Calibriton_Point - 2]) + cal_data.Y[No_Calibriton_Point - 2]; // ���������� ������ ���� �Լ� �̿�
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
       {0.0, 1.0, 2.0, 3.0, 4.0},  // X ����
       {10.0, 20.0, 30.0, 40.0, 50.0}  // y ��
    };

    double y = linear_mapping(3.5);

    printf("result : %lf \n", y);
}