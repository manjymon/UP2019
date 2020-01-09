#include <cmath>
#include <iostream>
#include <random>

const double epsilon = 0.001;

double compare_doubles(double a, double b, double eps)
{
    double delta{a - b};
    return !(std::fabs(delta) < eps) * delta;
}

bool inside_circle(double c_x, double c_y, double radius, double p_x, double p_y, double eps)
{
    double squared_distance{(c_x - p_x) * (c_x - p_x) +
                            (c_y - p_y) * (c_y - p_y)};

    double squared_radius{radius * radius};

    return compare_doubles(squared_distance, squared_radius, eps) <= 0;
}

double approximate_pi(unsigned tries, double eps)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);

    unsigned successes{0};

    for (unsigned i = 0; i < tries; ++i)
    {
        double p_x{dis(gen)};
        double p_y{dis(gen)};

        successes += inside_circle(0.5, 0.5, 0.5, p_x, p_y, eps);
    }

    return 4.0 * successes / tries;
}

int main()
{
    std::cout << approximate_pi(1000000, 0.0001) << '\n'
              << approximate_pi(1000000, 0.0001) << '\n';
    return 0;
}
