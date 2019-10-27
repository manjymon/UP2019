#include <iostream>

double square_root(double number, unsigned iterations)
{
    double root{number};
    for (unsigned i = 0; i < iterations; i++)
    {
        root = 0.5 * (root + number / root);
    }

    return root;
}

int main()
{
    std::cout << square_root(2, 100);
    return 0;
}
