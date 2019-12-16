#include <iostream>
#include <algorithm>

int * stable_partition_parity(int * begin, int * end)
{
    unsigned length = end - begin;

    if (length == 0)
    {
        return begin;
    }
    
    if (length == 1)
    {
        return begin + (*begin % 2 == 0);
    }

    int * mid = begin + length / 2;
    
    return std::rotate(stable_partition_parity(begin, mid),
                       mid,
                       stable_partition_parity(mid, end));
}

int main()
{
    int arr[]{1, 3, 5, 2, 6, 8, 7, 10, 9, 11, 12, 20, 13, 15};
    int * pivot = stable_partition_parity(std::begin(arr), std::end(arr));
    for (int * i = std::begin(arr); i != pivot; ++i)
    {
        std::cout << *i << ' ';
    }
    std::cout << '\n';
    for (int * i = pivot; i != std::end(arr); ++i)
    {
        std::cout << *i << ' ';
    }
    std::cout << '\n';
}
