# Problems

## 01

Implement a function that checks if a boolean variable p implies the boolean variable q

```c++
bool implication(bool p, bool q)
{
    return !p || q;
}
```

## 02

Implement a function that calculates the XOR of 2 booleans

```c++
bool exclusive_or(bool a, bool b)
{
    return a != b;
}
```

## 03

Given the coordinates of the center of a circle, the length of its radius and the coordinates of another point, return whether the function is inside, outside or on the circle.

```c++
const double EPSILON = 0.001;

double compare_doubles(double a, double b, double eps)
{
    double delta = a - b;
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

    double delta = compare_doubles(squared_distance, squared_radius, EPSILON);

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
```

## 04

Map a number between 1 and 7 to the corresponding day of the week.

```c++
enum class Weekday
{
    MONDAY = 1,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY,
    NO_SUCH_DAY,
};

Weekday get_weekday(int number)
{
    switch(number)
    {
        case 1: return Weekday::MONDAY;
        case 2: return Weekday::TUESDAY;
        case 3: return Weekday::WEDNESDAY;
        case 4: return Weekday::THURSDAY;
        case 5: return Weekday::FRIDAY;
        case 6: return Weekday::SATURDAY;
        case 7: return Weekday::SUNDAY;
        default: return Weekday::NO_SUCH_DAY;
    }
}
```

## 05

Given 2 integers, return the smaller one.

```c++
int min(int a, int b)
{
    return a < b ? a : b;
}
```

# Bonus problems

## Bonus 01

Given a date represented with 3 numbers (day, month and year), check if the date is valid.

## Bonus 02

Given the coordinates (x, y) on a chess board ( 1 <= x <= 8 and 1 <= y <= 8) of a knight and another figure, check if the knight can capture the other figure

## Bonus 03

Given the coordinates of the centers and the lengths of the radiuses of 2 circles return whether they touch, intersect or don't touch eachother.

HINT: Use the function in 03 and translate but return a new type of enum

## Bonus 04

Given the coordinates of the bottom-left and upper-right corner of a rectangle, check where a point is in relation to that rectangle.

HINT: Use the enum from problem 03.
