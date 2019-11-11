#include <iostream>

bool alternating_digits(unsigned number)
{
    bool should_be_smaller{false};
    unsigned last_digit{0};

    for (; number; number /= 10)
    {
        unsigned digit{number % 10};
        if (digit < last_digit != should_be_smaller)
        {
            return false;
        }
        last_digit = digit;
        should_be_smaller = !should_be_smaller;
    }

    return true;
}

bool alternating_number_in_range(unsigned p, unsigned q)
{
    for (unsigned i = p; i <= q; ++i)
    {
        if (alternating_digits(i))
        {
            return true;
        }
    }

    return false;
}

int main()
{
    std::cout << std::boolalpha << alternating_number_in_range(1300, 1400) << '\n';
    std::cout << std::boolalpha << alternating_number_in_range(1350, 1355);
    return 0;
}
