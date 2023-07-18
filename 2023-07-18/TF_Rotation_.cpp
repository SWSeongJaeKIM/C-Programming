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


Pose2D    base_link_origin;
Point2D   base_link_Point2D, base_link_map_Point2D;

double angle_degree;
double angle_radian;

double Rotation_matrix[2][2];
double Rotation_matrix_inverse[2][2];

/*************************************************Matrix***************************************************************/
void set_rotation_matrix(double m_angle_degree)
{
	angle_radian = DEG2RAD(m_angle_degree);
	Rotation_matrix[0][0] = cos(angle_radian);	Rotation_matrix[0][1] = sin(angle_radian);
	Rotation_matrix[1][0] = -sin(angle_radian);	Rotation_matrix[1][1] = cos(angle_radian);
}

void set_rotation_matrix_inverse(double m_angle_degree)
{
	angle_radian = DEG2RAD(m_angle_degree);

	Rotation_matrix_inverse[0][0] = cos(angle_radian);  Rotation_matrix_inverse[0][1] = -sin(angle_radian);
	Rotation_matrix_inverse[1][0] = sin(angle_radian); Rotation_matrix_inverse[1][1] = cos(angle_radian);
}
/*************************************************Matrix***************************************************************/



/****************************************Coordinate transformation*****************************************************/

void TF_base_link_base_link_map(Point2D base_link_point2d, Point2D* base_link_map_point2d, Pose2D base_link_origin)
{
	double base2map_x = (base_link_Point2D.x * Rotation_matrix_inverse[0][0]) + (base_link_Point2D.y * Rotation_matrix_inverse[0][1]);
	double base2map_y = (base_link_Point2D.x * Rotation_matrix_inverse[1][0]) + (base_link_Point2D.y * Rotation_matrix_inverse[1][1]);
	 printf("BASE_LINK TO MAP Matrix:\n");
	 printf("BASE_LINK TO MAP  Point: %6.3lf  %6.3lf\n", base2map_x, base2map_y);

}

void TF_base_link_map_base_link(Point2D base_link_point2d, Point2D* base_link_map_point2d, Pose2D base_link_origin)
{

	double map2base_x = (base_link_map_point2d->x * Rotation_matrix[0][0]) + (base_link_map_point2d->y * Rotation_matrix[0][1]);
	double map2base_y = (base_link_map_point2d->x * Rotation_matrix[1][0]) + (base_link_map_point2d->y * Rotation_matrix[1][1]);
	 printf("MAP TO BASE_LINK Matrix_inverse:\n");
	 printf("MAP TO BASE_LINK Point_Inverse: %6.3lf  %6.3lf\n", map2base_x, map2base_y);

}

/****************************************Coordinate transformation*****************************************************/

int _tmain(int argc, _TCHAR* argv[])
{
	base_link_origin.x = 1.0;
	base_link_origin.y = 2.0;
	base_link_origin.theta = 90;

	base_link_Point2D.x = 1.0;//-0.707;
	base_link_Point2D.y = 0.0;//2.121;

	base_link_map_Point2D.x = 0; //0.1;
	base_link_map_Point2D.y = 1;//0.1;

	set_rotation_matrix(base_link_origin.theta);
	printf("\n\n");
	printf("===================================\n");
	printf("\tRotation Matrix\n");
	printf("\t%6.3lf  %6.3lf\n", Rotation_matrix[0][0], Rotation_matrix[0][1]);
	printf("\t%6.3lf  %6.3lf\n", Rotation_matrix[1][0], Rotation_matrix[1][1]);
	set_rotation_matrix_inverse(base_link_origin.theta);
	printf("   Rotation Matrix_inverse:\n");
	printf("\t%6.3lf  %6.3lf\n", Rotation_matrix_inverse[0][0], Rotation_matrix_inverse[0][1]);
	printf("\t%6.3lf  %6.3lf\n", Rotation_matrix_inverse[1][0], Rotation_matrix_inverse[1][1]);
	printf("===================================\n");
	printf("\n\n");
	printf("=============================================\n");
	TF_base_link_base_link_map(base_link_Point2D, &base_link_map_Point2D, base_link_origin);
	printf("=============================================\n");
	printf("\n\n");
	printf("=============================================\n");
	TF_base_link_map_base_link(base_link_Point2D, &base_link_map_Point2D, base_link_origin);
	printf("=============================================\n");
	return 0;
}