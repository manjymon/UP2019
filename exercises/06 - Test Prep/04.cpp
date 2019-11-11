#include <iostream>
#include <cmath>

double compare_doubles(double a, double b, double eps)
{
    double delta{a - b};
    return !(std::fabs(delta) < eps) * delta;
}

double cos3(double x, double eps)
{
    double sum{0};
    double delta{1};
    double last_member{0};
    double sign{1};
    double power_of_3{1};
    double factoriel{1};
    double power_of_x{1};

    for (unsigned k = 1; delta; k++)
    {

        sign *= -1;
        power_of_3 *= 9;
        factoriel *= 2 * k * (2 * k - 1);
        power_of_x *= x * x;
        
        double next = sign * (power_of_3 + 3) / factoriel * power_of_x;
        sum += next;
        delta = compare_doubles(next, last_member, eps);
        last_member = next;
    }

    return sum / 4;
}

int main()
{
    std::cout << cos3(1, 0.001) << std::endl;
    return 0;
}
