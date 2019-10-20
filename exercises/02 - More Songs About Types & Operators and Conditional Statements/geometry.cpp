#include <iostream>

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

    if (squared_distance < squared_radius)
    {
        return PointToFigureRelation::INSIDE;
    }

    if (squared_distance == squared_radius)
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
    if (x_point > x_bottom && x_point < x_top && y_point > y_bottom && y_point < y_top)
    {
        return PointToFigureRelation::INSIDE;
    }

    if (x_point >= x_bottom && x_point <= x_top && y_point >= y_bottom && y_point <= y_top)
    {
        return PointToFigureRelation::ON_BORDER;
    }

    return PointToFigureRelation::OUTSIDE;
}

int main()
{
    return 0;
}
