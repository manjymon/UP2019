#include <iostream>
#include <cmath>

// Comparing doubles using regular comparision operators would not be considered an error
const double epsilon = 0.0001;

double compare_doubles(double a, double b, double eps)
{
    double delta{a - b};
    return !(std::abs(delta) < eps) * delta;
}

// Given bottom right and upper left points of square
bool inside_square_2_points(double x_bottom, double y_bottom,
                            double x_top, double y_top,
                            double x_point, double y_point)
{
    double delta_x_bottom{compare_doubles(x_point, x_bottom, epsilon)};
    double delta_x_top{compare_doubles(x_point, x_top, epsilon)};
    double delta_y_bottom{compare_doubles(y_point, y_bottom, epsilon)};
    double delta_y_top{compare_doubles(y_point, y_top, epsilon)};

    return delta_x_bottom <= 0 && delta_x_top >= 0 && delta_y_bottom >= 0 && delta_y_top <= 0;
}

// Given upper left point and length of square
bool inside_square(double x_top, double y_top, double length,
                   double x_point, double y_point)
{
    return inside_square_2_points(x_top + length, y_top - length,
                                  x_top, y_top,
                                  x_point, y_point);
}

unsigned input()
{
    unsigned x{11};

    while (!x || x > 10)
    {
        std::cin >> x;
    }

    return x;
}

// Problem 1

bool in_at_least_1_square(const double squares_xs[], const double squares_ys[], const double squares_lengths[],
                          unsigned total_squares,
                          double x_point, double y_point)
{
    for (unsigned i = 0; i < total_squares; ++i)
    {
        if (inside_square(squares_xs[i], squares_ys[i], squares_lengths[i], x_point, y_point))
        {
            return true;
        }
    }

    return false;
}

unsigned points_in_at_least_1_square(const double squares_xs[], const double squares_ys[], double const squares_lengths[],
                                     unsigned total_squares,
                                     const double points_xs[], const double points_ys[],
                                     unsigned total_points)
{
    unsigned count{0};

    for (unsigned i = 0; i < total_points; ++i)
    {
        if (in_at_least_1_square(squares_xs, squares_ys, squares_lengths, total_squares, points_xs[i], points_ys[i]))
        {
            ++count;
        }
    }

    return count;
}

// Problem 2

unsigned points_in_square(double x_square, double y_square, double square_length,
                          const double points_xs[], const double points_ys[],
                          unsigned total_points)
{
    unsigned count{0};

    for (unsigned i = 0; i < total_points; ++i)
    {
        if (inside_square(x_square, y_square, square_length, points_xs[i], points_ys[i]))
        {
            ++count;
        }
    }

    return count;
}

bool no_points(double x_square, double y_square, double square_length,
               const double points_xs[], const double points_ys[],
               unsigned total_points)
{
    return points_in_square(x_square, y_square, square_length, points_xs, points_ys, total_points) == 0;
}

unsigned squares_with_no_points(const double squares_xs[], const double square_ys[], double const square_lengths[],
                                unsigned total_squares,
                                double points_xs[], double points_ys[],
                                unsigned total_points)
{
    unsigned count{0};

    for (unsigned i = 0; i < total_squares; ++i)
    {
        if (no_points(squares_xs[i], square_ys[i], square_lengths[i], points_xs, points_ys, total_points))
        {
            ++count;
        }
    }

    return count;
}

// Problem 3

unsigned most_occupied_square(const double squares_xs[], const double squares_ys[], double const squares_lengths[],
                              unsigned total_squares,
                              double points_xs[], double points_ys[],
                              unsigned total_points)
{
    unsigned max{0};
    unsigned max_index{0};

    for (unsigned i = 0; i < total_squares; ++i)
    {
        unsigned points_in_current_square{
            points_in_square(squares_xs[i], squares_ys[i], squares_lengths[i], points_xs, points_ys, total_points)
        };

        if (points_in_current_square > max)
        {
            max = points_in_current_square;
            max_index = i;
        }
    }

    return max_index;
}

int main()
{
    unsigned total_squares{input()};
    unsigned total_points{input()};

    double squares_xs[10]{};
    double squares_ys[10]{};
    double squares_lengths[10]{};

    double points_xs[10]{};
    double points_ys[10]{};

    for (unsigned i = 0; i < total_squares; ++i)
    {
        std::cin >> squares_xs[i] >> squares_ys[i] >> squares_lengths[i];
    }

    for (unsigned i = 0; i < total_points; ++i)
    {
        std::cin >> points_xs[i] >> points_ys[i];
    }

    std::cout << points_in_at_least_1_square(squares_xs, squares_ys, squares_lengths, total_squares, points_xs, points_ys, total_points) << '\n'
              << squares_with_no_points(squares_xs, squares_ys, squares_lengths, total_squares, points_xs, points_ys, total_points) << '\n'
              << most_occupied_square(squares_xs, squares_ys, squares_lengths, total_squares, points_xs, points_ys, total_points) << '\n';

    return 0;
}
