#include <iostream>
#include <cmath>

const double EPSILON = 0.001;

double compare_doubles(double a, double b, double eps)
{
    double delta{a - b};
    return !(std::fabs(delta) < eps) * delta;
}

enum class PointToFigureRelation
{
    INSIDE,
    ON_BORDER,
    OUTSIDE,
};

PointToFigureRelation get_relation_to_circle(double x_circle, double y_circle,
                                             double radius,
                                             double x_point, double y_point)
{
    double squared_distance{(x_circle - x_point) * (x_circle - x_point) +
                            (y_circle - y_point) * (y_circle - y_point)};

    double squared_radius{radius * radius};

    double delta{compare_doubles(squared_distance, squared_radius, EPSILON)};

    if (delta < 0)
    {
        return PointToFigureRelation::INSIDE;
    }

    if (delta == 0)
    {
        return PointToFigureRelation::ON_BORDER;
    }

    return PointToFigureRelation::OUTSIDE;
}

enum class CircleToCircleRelation
{
    INTERSECTING,
    SEPARATE,
    TOUCHING,
};

CircleToCircleRelation convert_relation(PointToFigureRelation relation)
{
    switch (relation)
    {
        case PointToFigureRelation::INSIDE: return CircleToCircleRelation::INTERSECTING;
        case PointToFigureRelation::OUTSIDE: return CircleToCircleRelation::SEPARATE;
        case PointToFigureRelation::ON_BORDER: return CircleToCircleRelation::TOUCHING;
    }
}

CircleToCircleRelation get_circles_relation(double x1, double y1, double r1,
                                            double x2, double y2, double r2)
{
    return convert_relation(get_relation_to_circle(x1, x2, r1 + r2, x2, y2));
}

PointToFigureRelation get_relation_to_rectangle(double x_bottom, double y_bottom,
                                                double x_top, double y_top,
                                                double x_point, double y_point)
{
    double delta_x_bottom{compare_doubles(x_point, x_bottom, EPSILON)};
    double delta_x_top{compare_doubles(x_point, x_top, EPSILON)};
    double delta_y_bottom{compare_doubles(y_point, y_top, EPSILON)};
    double delta_y_top{compare_doubles(y_point, y_bottom, EPSILON)};

    if (delta_x_bottom > 0 && delta_x_top < 0 && delta_y_bottom > 0 && delta_y_top < 0)
    {
        return PointToFigureRelation::INSIDE;
    }

    if (delta_x_bottom >= 0 && delta_x_top <= 0 && delta_y_bottom >= 0 && delta_y_top <= 0)
    {
        return PointToFigureRelation::ON_BORDER;
    }

    return PointToFigureRelation::OUTSIDE;
}

int main()
{
    std::cout << (get_relation_to_circle(0, 0, 1, 0, 1) == PointToFigureRelation::ON_BORDER);
    return 0;
}
