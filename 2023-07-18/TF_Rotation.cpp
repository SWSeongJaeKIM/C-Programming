// TF_Rotation.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#define _USE_MATH_DEFINES
#include "math.h"

#define RAD2DEG(x)   x*180/M_PI
#define DEG2RAD(x)   x*180/M_PI

typedef struct 
{
	double x;
	double y;
	double theta;
} Pose2D;

typedef struct
{
	double x;
	double y;	
} Point2D;


Pose2D    base_link_origin;
Point2D   base_link_Point2D, base_link_map_Point2D;

double angle_degree;
double angle_radian;

/*
double Rotation_matrix[2][2]
= {
	{ cos(angle_radian), -sin(angle_radian) },
	{ sin(angle_radian), cos(angle_radian) }
  };
*/

double Rotation_matrix[2][2];
double Rotation_matrix_inverse[2][2];


void set_rotation_matrix(double m_angle_degree)
{
	double x_result = 0.0;
	double y_result = 0.0;
	angle_radian = DEG2RAD(m_angle_degree);
	Rotation_matrix[0][0] = cos(angle_radian);   Rotation_matrix[0][1] = -sin(angle_radian);
	Rotation_matrix[1][0] = sin(angle_radian);   Rotation_matrix[1][1] = cos(angle_radian);

	base_link_map_Point2D.x = base_link_map_Point2D.x * Rotation_matrix[0][0] + base_link_map_Point2D.y * Rotation_matrix[0][1];
	base_link_map_Point2D.y = base_link_map_Point2D.x * Rotation_matrix[1][0] + base_link_map_Point2D.y * Rotation_matrix[1][1];

}

void set_rotation_matrix_inverse(double m_angle_degree)
{
	double x_result_2 = 0.0;
	double y_result_2 = 0.0;
    angle_radian = DEG2RAD(m_angle_degree);
    Rotation_matrix_inverse[0][0] =  cos(angle_radian);   Rotation_matrix_inverse[0][1] = sin(angle_radian);
    Rotation_matrix_inverse[1][0] = -sin(angle_radian);   Rotation_matrix_inverse[1][1] = cos(angle_radian);

	base_link_Point2D.x = base_link_origin.x * Rotation_matrix_inverse[0][0] + base_link_origin.y * Rotation_matrix_inverse[0][1];
	base_link_Point2D.y = base_link_origin.x * Rotation_matrix_inverse[1][0] + base_link_origin.y * Rotation_matrix_inverse[1][1];
}


void TF_base_link_base_link_map(Point2D base_link_point2d, Point2D *base_link_map_point2d, Pose2D base_link_origin)
{
	printf("%6.3lf  %6.3lf\n", Rotation_matrix[0][0], Rotation_matrix[0][1]);
	printf("%6.3lf  %6.3lf\n", Rotation_matrix[1][0], Rotation_matrix[1][1]);

	printf("\n\n");
	printf("%6.3lf  %6.3lf\n", base_link_point2d.x, base_link_point2d.y);

	printf("%6.3lf  %6.3lf\n", base_link_map_point2d->x, base_link_map_point2d->y);

	printf("%6.3lf  %6.3lf  %6.3lf\n", base_link_origin.x, base_link_origin.y, base_link_origin.theta);


}

int _tmain(int argc, _TCHAR* argv[])
{
	//angle_degree = 90;
	//angle_radian = DEG2RAD(angle_degree);

	base_link_origin.x = 1.0;
	base_link_origin.y = 2.0;
	base_link_origin.theta = 90;	
	set_rotation_matrix(base_link_origin.theta);
	set_rotation_matrix_inverse(base_link_origin.theta);
	TF_base_link_base_link_map(base_link_Point2D, &base_link_map_Point2D, base_link_origin);

	return 0;
}

