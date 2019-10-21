#include <iostream>
#include <cmath>

bool is_prime(unsigned number)
{
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

unsigned count_primes(int n)
{
    unsigned count{0};
    for (unsigned i = 0; i < n; i++)
    {
        unsigned number{};
        std::cin >> number;

        if (is_prime(number))
        {
            count++;
        }
    }

    return count;
}

void factorize(unsigned number)
{
    for (unsigned i = 2; number != 1; ++i)
    {
        if (number % i == 0)
        {
            std::cout << i << ' ';
            while (number % i == 0)
            {
                number /= i;
            }
        }
    }
}

int main()
{
    factorize(120);
    return 0;
}
