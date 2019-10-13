#include <iostream>
#include <cmath>

double triangle_perimeter(double a, double b, double c)
{
    return a + b + c;
}

double triangle_semiperimeter(double a, double b, double c)
{
    return triangle_perimeter(a, b, c) / 2;
}

double triangle_area(double a, double b, double c)
{
    // Here p is a fine name, same as the mathematical formula
    double p = triangle_semiperimeter(a, b, c);

    return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

int main()
{
    double a{};
    double b{};
    double c{};

    std::cin >> a >> b >> c;

    std::cout << triangle_area(a, b, c) << '\n';

    return 0;
}
