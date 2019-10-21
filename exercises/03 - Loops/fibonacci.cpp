#include <iostream>

unsigned fibonacci(unsigned n)
{
    unsigned a{0};
    unsigned b{1};

    for (int i = 0; i < n ; i++)
    {
        std::swap(a, b);
        b += a;
    }

    return a;
}

int main()
{
    std::cout << fibonacci(6);
    return 0;
}
