#include <iostream>

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

bool is_palindrome(unsigned number)
{
    return number == reverse_number(number);
}

unsigned largest_palindrome()
{
    unsigned largest{0};

    for (unsigned i = 100; i < 1000; i++)
    {
        for (unsigned j = i; j < 1000; j++)
        {
            unsigned number = i * j;
            if (is_palindrome(number))
            {
                largest = std::max(largest, number);
            }
        }
    }

    return largest;
}

int main()
{
    std::cout << largest_palindrome() << '\n';
    return 0;
}
