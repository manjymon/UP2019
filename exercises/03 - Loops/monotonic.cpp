#include <iostream>

bool monotonic(unsigned n)
{
    if (n < 1)
    {
        return true;
    }

    int last_number{};
    std::cin >> last_number;
    bool increasing{true};
    bool decreasing{true};

    for (unsigned i = 1; i < n; i++)
    {
        int current_number{};
        std::cin >> current_number;

        if (current_number > last_number)
        {
            decreasing = false;
            if (!increasing)
            {
                return false;
            }
        }
        else if (current_number < last_number)
        {
            increasing = false;
            if (!decreasing)
            {
                return false;
            }
        }

        last_number = current_number;
    }

    return true;
}

int main()
{
    std::cout << std::boolalpha << monotonic(4);
    return 0;
}
