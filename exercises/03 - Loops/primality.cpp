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

        count += is_prime(i)
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

void number_as_product_of_primes(unsigned number)
{
    unsigned i{2};
    bool first{true};

    while(number != 1)
    {
        if (number % i == 0)
        {
            if (!first)
            {
                std::cout << " * ";
            }
            else
            {
                first = !first;
            }
            std::cout << i;
            number /= i;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    number_as_product_of_primes(120);
    std::cout << '\n';
    factorize(120);
    return 0;
}
