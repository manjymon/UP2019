#include <iostream>

void even_digit_occurences(unsigned number)
{
    int digits_occurences[10]{};

    for (; number; number /= 10)
    {
        digits_occurences[number % 10]++;
    }

    for (unsigned i = 0; i < 10; i += 2)
    {
        if (digits_occurences[i])
        {
            std::cout << i << ": " << digits_occurences[i] << '\n';
        }
    }
}

int main()
{
    even_digit_occurences(3242726);
    return 0;
}
