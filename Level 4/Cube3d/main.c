#include <stdio.h>
#include <math.h>
#include <unistd.h>

// #define M_PI 3.14159265358979323846264338327950288


// Structure to represent a point in 2D space
typedef struct s_coord
{
    double x;
    double y;
} t_coord;

t_coord mk_coord(double x, double y)
{
    t_coord new_coord;

    new_coord.x = x;
    new_coord.y = y;
    return (new_coord);
}

typedef struct s_vectors
{
    t_coord direction;
    // it could also be just add angle
    // is the hypotheus, if the direction is the end point
    double  magnitude;
} t_vectors;


int exemple() {

    double angle = 60.0; // Angle in degrees

    double radians = angle * (M_PI / 180.0); // Convert to radians

    double cosineResult = cos(radians);

    printf("Cosine: cos(%.2lf degrees) = %.2lf\n", angle, cosineResult);

    return 0;
}


void player_action()
{
    int map[10][10] = {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 2, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };



    t_coord player_position = mk_coord(5, 5);
    double angle_looking = 0;

    double angle_drift = 50;
    int lenght_check = 10;
    int i = 0;
    int j = 0;
    double  randiant_angle_looking = (angle_looking + angle_drift) * (M_PI / 180);

    t_coord fardest_point = mk_coord(lenght_check * cos(randiant_angle_looking), lenght_check * sin(randiant_angle_looking));

    if (fardest_point.x >= 0)
    {
        if (fardest_point.y >= 0)
        {
            printf("fardestpoint is (%f, %f)\n", fardest_point.x, fardest_point.y);
            double current_x = 0;
            double current_y = 0;
            while (fardest_point.x > floor(current_x) + 1 && fardest_point.y > floor(current_y) + 1)
            {
                printf("curentposition looking is (%f, %f)\n", current_x, current_y);
                // *need to be 2 dirrent thing base on which is moving
                if (current_x > current_y)
                {
                    current_x = floor(current_x);
                    current_x++;
                    current_y = current_x * sin(randiant_angle_looking) / cos(randiant_angle_looking);
                }
                else
                {
                    current_y = floor(current_y);
                    current_y++;
                    current_x = current_y / sin(randiant_angle_looking) * cos(randiant_angle_looking);
                }
                if (map[(int)round(current_x + player_position.x)][(int)round(current_y + player_position.y)] == 1)
                {
                    printf("wall seen at (%d, %d)\n", (int)round(current_x + player_position.x), (int)round(current_y + player_position.y));
                    return ;
                }
            }
        }
        else
        {

        }
        
    }
    else
    {

    }




    // while (i < lenght_check)
    // {
    //     t_coord current_coord = mk_coord()
    //     cos((angle_looking + angle_drift) / (M_PI * 180))
    // }
    

    // t_coord end_point_vector

}

int main()
{
    t_coord A;
    t_coord B;
    double  angle;
    player_action();
    pause();
    return (0);
}