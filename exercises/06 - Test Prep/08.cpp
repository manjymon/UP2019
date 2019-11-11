#include <iostream>
#include <cmath>

unsigned cube_sum_with_k_larger(unsigned a, unsigned k)
{
    return std::pow(a, 3) + std::pow(a + k, 3);
}

unsigned find_smallest_cube_sum(unsigned p, unsigned k)
{
    for (unsigned a = 0; true; ++a)
    {
        unsigned cubed_sum = cube_sum_with_k_larger(a, k);
        if (cubed_sum > p)
        {
            return cubed_sum;
        }
    }
}

int main()
{
    std::cout << find_smallest_cube_sum(100, 1);
    return 0;
}
