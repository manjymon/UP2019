#include <iostream>

// Hack
bool is_power_of_v2(unsigned number)
{
    return (number & (number - 1)) == 0;
}

// :(
bool is_power_of_2(unsigned number)
{
    while (number % 2 == 0)
    {
        number /= 2;
    }

    return number == 1;
}

unsigned largest_power_of_2(unsigned arr[], unsigned size)
{
    unsigned max{1};
    for (unsigned i = 0; i < size; ++i)
    {
        if (is_power_of_2(arr[i]))
        {
            max = std::max(max, arr[i]);
        }
    }

    return max;
}

int main()
{
    unsigned arr1[]{4, 1, 3, 4, 16, 9, 9};
    std::cout << largest_power_of_2(arr1, 7) << '\n';
    unsigned arr2[]{3, 6, 12, 5, 5};
    std::cout << largest_power_of_2(arr2, 5) << '\n';
}
