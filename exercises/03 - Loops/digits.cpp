#include <iostream>

unsigned count_digits(int number)
{
    if (!number)
    {
        return 0;
    }

    unsigned count{0};

    while (number)
    {
        count++;
        number /= 10;
    }

    return count;
}

unsigned reverse_number(unsigned number)
{
    unsigned reversed{0};

    while(number)
    {
        reversed = reversed * 10 + number % 10;
        number /= 10;
    }

    return reversed;
}

bool palindrome(unsigned number)
{
    return number == reverse_number(number);
}

int main()
{
    std::cout << std::boolalpha << palindrome(323);
    return 0;
}
