#include <iostream>
#include <cmath>

unsigned digits_diff(unsigned number)
{
    unsigned min{9};
    unsigned max{0};

    while (number)
    {
        unsigned digit = number % 10;
        min = std::min(digit, min);
        max = std::max(digit, max);

        number /= 10;
    }

    return max - min;
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

unsigned digits_sum(unsigned number)
{
    unsigned sum{0};

    while (number)
    {
        sum += number % 10;
        number /= 10;
    }

    return sum;
}

unsigned sum_1(unsigned n)
{
    unsigned sum{0};
    for (unsigned i = 0; n; i++)
    {
        if (digits_diff(i) == 3)
        {
            std::cout << i << '\n';
            sum += i;
            n--;
        }
    }

    return sum;
}

unsigned sum_2(unsigned n)
{
    unsigned sum{0};
    for (unsigned i = 0; n; i++)
    {
        if (is_prime(digits_sum(i)))
        {
            std::cout << i << '\n';
            sum += i;
            n--;
        }
    }

    return sum;
}

int main()
{
    std::cout << sum_1(5) << "\n-------\n";
    std::cout << sum_2(10) << '\n';

    return 0;
}
