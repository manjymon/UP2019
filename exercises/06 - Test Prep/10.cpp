#include <iostream>
#include <cmath>

unsigned divisors_smaller_than_n(unsigned number, unsigned n)
{
    unsigned divisors{0};
    for (unsigned i = 1; i < std::min(number + 1, n); ++i)
    {
        if (number % i == 0)
        {
            divisors++;
        }
    }

    return divisors;
}

bool is_prime(unsigned number)
{
    if (number < 2)
    {
        return false;
    }

    unsigned limit = sqrt(number);

    for (unsigned i = 2; i <= limit; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }

    return true;
}

unsigned insert_name_here(unsigned n)
{
    unsigned sum{0};

    for (unsigned i = 0, count = n; count; ++i)
    {
        if (is_prime(divisors_smaller_than_n(i, n)))
        {
            sum += i;
            count--;
        }
    }

    return sum;
}

int main()
{
    std::cout << insert_name_here(5);
    return 0;
}
