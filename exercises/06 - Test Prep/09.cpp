#include <iostream>

bool duplicate_digits(unsigned number)
{
    bool digits_map[10]{};

    for (; number; number /= 10)
    {
        unsigned digit{number % 10};

        if (digits_map[digit])
        {
            return true;
        }

        digits_map[digit] = true;
    }

    return false;
}

int main()
{
    std::cout << std::boolalpha << duplicate_digits(123) << ' ' << duplicate_digits(1231) << std::endl;
    return 0;
}
