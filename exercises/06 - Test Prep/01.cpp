#include <iostream>

bool equal_sums(unsigned number)
{
    unsigned sums[2]{ 0, 0 };

    while (number)
    {
        unsigned digit = number % 10;
        sums[digit % 2] += digit;
        number /= 10;
    }

    return sums[0] == sums[1];
}

int main()
{
    std::cout << std::boolalpha << equal_sums(1234) << '\n';
    std::cout << std::boolalpha << equal_sums(1223) << '\n';

    return 0;
}
