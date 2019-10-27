#include <iostream>

unsigned max_contiguous_sum(unsigned n)
{
    if (n < 1)
    {
        return 0;
    }

    int max{0};
    int max_here{0};

    for (unsigned i = 0; i < n; i++)
    {
        int number{};
        std::cin >> number;

        max_here = max_here + number;

        max_here = std::max(max_here, 0);
        max = std::max(max, max_here);
    }

    return max;
}

int main()
{
    std::cout << max_contiguous_sum(8);
    return 0;
}
