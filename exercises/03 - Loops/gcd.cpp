#include <iostream>

unsigned gcd(unsigned a, unsigned b)
{
    while (b)
    {
        std::swap(a, b);
        b %= a;
    }

    return a;
}

int main()
{
    std::cout << gcd(24, 36);
    return 0;
}
