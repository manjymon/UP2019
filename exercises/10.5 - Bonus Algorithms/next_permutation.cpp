#include <algorithm>
#include <iostream>

bool next_permutation(int * begin, int * end)
{
    unsigned size = end - begin;
    if (size <= 1)
    {
        return false;
    }

    for (int * i = end - 2; i >= begin; --i)
    {
        if (*i < *(i + 1))
        {
            int * right_min{i + 1};
            for (int * j = i + 1; j < end; ++j)
            {
                if (*j > *i && *j < *right_min)
                {
                    right_min = j;
                }
            }
            std::iter_swap(i, right_min);
            std::reverse(i + 1, end);
            return true;
        }
    }

    std::reverse(begin, end);
    return false;
}

int main()
{
    int arr[]{1, 2, 3};

    do
    {
        for (int num : arr)
        {
            std::cout << num << ' ';
        }

        std::cout << std::endl;
    } while(next_permutation(std::begin(arr), std::end(arr)));

    return 0;
}
