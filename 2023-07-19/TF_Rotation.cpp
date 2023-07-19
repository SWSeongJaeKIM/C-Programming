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
Point2D base_link_Point2D, base_link_map_Point2D, map2base, base2map, map2base2, base2map2;

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

void TF_base_link_base_link_map(const Point2D* base_link_point2d, Point2D* base_link_map_point2d, const Pose2D* base_link_origin)
{
	set_rotation_matrix(base_link_origin->theta);

	base2map.x = (base_link_point2d->x * Rotation_matrix[0][0]) + (base_link_point2d->y * Rotation_matrix[0][1]);
	base2map.y = (base_link_point2d->x * Rotation_matrix[1][0]) + (base_link_point2d->y * Rotation_matrix[1][1]);

	printf("**********************************************************************************************\n");
	printf("Transformed Point Matrix: %6.3lf  %6.3lf\n", base_link_Point2D.x, base_link_Point2D.y);
	printf("BASE_LINK TO MAP  Point: %6.3lf  %6.3lf\n", base2map.x, base2map.y);
	printf("\n");
}

void TF_base_link_map_map(Point2D* base2map, Pose2D base_link_origin)  // Base_Link_Map -> Map
{
	base2map2.x = base2map->x + base_link_origin.x;;
	base2map2.y = base2map->y + base_link_origin.y;

	printf("**********************************************************************************************\n");
	printf("Transformed Point Matrix: %6.3lf  %6.3lf\n", base2map->x, base2map->y);
	printf("Base_Link_Map -> Map: %6.3lf  %6.3lf\n", base2map2.x, base2map2.y);
}

void TF_map_base_link_map(Point2D* base2map2, Pose2D base_link_origin)  // Map -> Base_Link_Map
{
	map2base2.x = base2map2->x - base_link_origin.x;
	map2base2.y = base2map2->y - base_link_origin.y;

	printf("**********************************************************************************************\n");
	printf("Transformed Point Matrix: %6.3lf  %6.3lf\n", base2map2->x, base2map2->y);
	printf("Map -> Base_Link_Map: %6.3lf  %6.3lf\n", map2base2.x, map2base2.y);
}

void TF_base_link_map_base_link(Point2D* map2base2, const Point2D* base_link_map_point2d, const Pose2D* base_link_origin)
{
	set_rotation_matrix_inverse(base_link_origin->theta);

	map2base.x = (map2base2->x * Rotation_matrix_inverse[0][0]) + (map2base2->y * Rotation_matrix_inverse[0][1]);
	map2base.y = (map2base2->x * Rotation_matrix_inverse[1][0]) + (map2base2->y * Rotation_matrix_inverse[1][1]);

	printf("**********************************************************************************************\n");
	printf("Transformed Point Matrix: %6.3lf  %6.3lf\n", map2base2->x, map2base2->y);
	printf("MAP TO BASE_LINK Point_Inverse: %6.3lf  %6.3lf\n", map2base.x, map2base.y);
	printf("\n");
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

	TF_base_link_base_link_map(&base_link_Point2D, &base_link_map_Point2D, &base_link_origin);
	TF_base_link_map_map(&base2map, base_link_origin);
	TF_map_base_link_map(&base2map2, base_link_origin);
	TF_base_link_map_base_link(&map2base2, &base_link_map_Point2D, &base_link_origin);
	return 0;
}
