#include <iostream>
#include <numeric>
#include <random>

void shuffle(int * begin, int * end)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int * i = end - 1; i >= begin; --i)
    {
        unsigned random_index{std::uniform_int_distribution<unsigned>(0, i - begin)(gen)};
        std::iter_swap(i, begin + random_index);
    }
}

int main()
{
    int arr[10]{};
    std::iota(std::begin(arr), std::end(arr), 0);

    shuffle(std::begin(arr), std::end(arr));

    for (int num : arr)
    {
        std::cout << num << ' ';
    }

    std::cout << '\n';

    shuffle(std::begin(arr), std::end(arr));

    for (int num : arr)
    {
        std::cout << num << ' ';
    }

    std::cout << '\n';

    return 0;
}
