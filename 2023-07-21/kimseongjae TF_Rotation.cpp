// TF_Rotation.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#define _USE_MATH_DEFINES
#include "math.h"

#define DEG2RAD(x)   x/180*M_PI
#define RAD2DEG(x)   x*180/M_PI

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

Pose2D base_link_origin;
Point2D base_link_Point2D, base_link_map_Point2D;

double angle_degree;
double angle_radian;

double Rotation_matrix[2][2];
double Rotation_matrix_inverse[2][2];

void set_rotation_matrix(double m_angle_degree)
{
	angle_radian = DEG2RAD(m_angle_degree);
	Rotation_matrix[0][0] = cos(angle_radian); Rotation_matrix[0][1] = -sin(angle_radian);
	Rotation_matrix[1][0] = sin(angle_radian); Rotation_matrix[1][1] = cos(angle_radian);
}

void set_rotation_matrix_inverse(double m_angle_degree)
{
	angle_radian = DEG2RAD(m_angle_degree);
	Rotation_matrix_inverse[0][0] = cos(angle_radian);  Rotation_matrix_inverse[0][1] = sin(angle_radian);
	Rotation_matrix_inverse[1][0] = -sin(angle_radian); Rotation_matrix_inverse[1][1] = cos(angle_radian);
}

void TF_base_link_base_link_map(Point2D base_link_point2d, Point2D* base_link_map_point2d, Pose2D base_link_origin)
{
	set_rotation_matrix(base_link_origin.theta);
	base_link_map_point2d->x = (base_link_point2d.x * Rotation_matrix[0][0]) + (base_link_point2d.y * Rotation_matrix[0][1]);
	base_link_map_point2d->y = (base_link_point2d.x * Rotation_matrix[1][0]) + (base_link_point2d.y * Rotation_matrix[1][1]);
}

void TF_base_link_map_base_link(Point2D* base_link_point2d, Point2D base_link_map_point2d, Pose2D base_link_origin)
{
	set_rotation_matrix_inverse(base_link_origin.theta);
	base_link_point2d->x = (Rotation_matrix_inverse[0][0] * base_link_map_point2d.x) + Rotation_matrix_inverse[0][1] * (base_link_map_point2d.y);
	base_link_point2d->y = (Rotation_matrix_inverse[1][0] * base_link_map_point2d.x) + Rotation_matrix_inverse[1][1] * (base_link_map_point2d.y);
}

void TF_base_link_map_map(Point2D base_link_2D, Point2D* base_link_map_2D, Pose2D base_link_origin)
{
	base_link_map_2D->x += base_link_origin.x;
	base_link_map_2D->y += base_link_origin.y;
}

void TF_map_base_link_map(Point2D* base_link_2D, Point2D base_link_map_2D, Pose2D base_link_origin) 
{
	base_link_2D->x -= base_link_origin.x;
	base_link_2D->y -= base_link_origin.y;
}

void TF_map_base_link(Point2D* base_link_2D, Point2D* base_link_map_2D, Pose2D base_link_origin)
{
	TF_base_link_base_link_map(base_link_Point2D, &base_link_map_Point2D, base_link_origin);
	TF_base_link_map_map(base_link_Point2D, &base_link_map_Point2D, base_link_origin);
	printf("Base_link to Map  x:%6.3lf / y:%6.3lf\n\n", base_link_map_Point2D.x, base_link_map_Point2D.y);
}

void TF_base_link_map(Point2D* base_link_2D, Point2D base_link_map_2D, Pose2D base_link_origin)
{
	TF_map_base_link_map(base_link_Point2D, base_link_map_Point2D, base_link_origin);
	TF_base_link_map_base_link(&base_link_Point2D, base_link_map_Point2D, base_link_origin);
	printf("Map to Base_link  x:%6.3lf / y:%6.3lf\n\n", base_link_Point2D.x, base_link_Point2D.y);
}

int main(int argc, char* argv[])
{
	base_link_origin.x = 5.0;
	base_link_origin.y = 4.0;
	base_link_origin.theta = 90;

	base_link_Point2D.x = 1.0;
	base_link_Point2D.y = -1.0;

	base_link_map_Point2D.x = 6.0;
	base_link_map_Point2D.y = 5.0;
	TF_map_base_link(base_link_Point2D, &base_link_map_Point2D, base_link_origin);
	TF_base_link_map(&base_link_Point2D, base_link_map_Point2D, base_link_origin);

	return 0;
}
