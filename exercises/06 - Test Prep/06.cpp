#include <iostream>

bool increasing_digits(unsigned number)
{
    unsigned last_digit{9};
    for (; number; number /= 10)
    {
        unsigned digit{number % 10};

        if (digit > last_digit)
        {
            return false;
        }
        last_digit = digit;
    }

    return true;
}

int main()
{
    std::cout << std::boolalpha << increasing_digits(1223) << ' ' << increasing_digits(1232); 
    return 0;
}
