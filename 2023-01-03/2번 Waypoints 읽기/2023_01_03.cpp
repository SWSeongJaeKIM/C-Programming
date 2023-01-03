#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NO_MAX_WAYPOINTS 50

float   x[NO_MAX_WAYPOINTS] = { 0, };
float   y[NO_MAX_WAYPOINTS] = { 0, };
float yaw[NO_MAX_WAYPOINTS] = { 0, };

int read_waypoints_data(void)

{
    int result = 0;
    FILE* fp;
    int no_line = 0;
    float x1, y2, yaw3;

    fp = fopen("waypoints.dat", "r");

        while(feof(fp)==0)

        {

            result = fscanf(fp, "%f %f %f", &x1, &y2, &yaw3);

            x[no_line] = x1;
            y[no_line] = y2;
            yaw[no_line] = yaw3;

            no_line++;

        }
        fclose(fp);
        x[no_line -1] = { 0, };
        y[no_line - 1] = { 0, };
        yaw[no_line - 1] = { 0, };
        no_line = no_line - 1;
        for(int i=0; i< no_line; i++)
        {
            printf(" %f %f %f\n", x[i], y[i], yaw[i]);
        }
        printf("no of line %d\n", no_line);
        return 0;

}
int main()
{
    read_waypoints_data();
    return 0;
}