#include <iostream>

double squared_distance(double x_1, double y_1,
                        double x_2, double y_2)
{
    return (x_1 - x_2) * (x_1 - x_2) + (y_1 - y_2) * (y_1 - y_2);    
}

unsigned furthest_from_center(double x_coords[], double y_coords[], unsigned n)
{
    double max_squared_distance{0};
    unsigned max_index{0};
    for (unsigned i = 0; i < n; ++i)
    {
        double current_squared_distance{squared_distance(x_coords[0], y_coords[0], 0, 0)};
        if (current_squared_distance >= max_squared_distance)
        {
            max_squared_distance = current_squared_distance;
            max_index = i;
        }
    }

    return max_index;
}

int main()
{
    double x_coords[]{1, 2, 3};
    double y_coords[]{3, 2, 2};

    unsigned index = furthest_from_center(x_coords, y_coords, 3);

    std::cout << x_coords[index] << ", " << y_coords[index];

    return 0;
}
