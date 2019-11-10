#include <iostream>

void print(const int arr[], unsigned begin, unsigned end)
{
    for (begin; begin != end; ++begin)
    {
        std::cout << arr[begin] << ' ';
    }
    std::cout << '\n';
}

unsigned unique(int arr[], unsigned begin, unsigned end)
{
    if (begin == end)
    {
        return begin;
    }

    ++begin;

    for (unsigned it = begin; it != end; ++it)
    {
        if (arr[it - 1] != arr[it])
        {
            arr[begin++] = arr[it];
        }
    }

    return begin;
}

int main()
{
    int arr[]{1, 1, 1, 2, 3, 4, 5, 5, 6, 6};
    unsigned end{unique(arr, 0, 10)};

    print(arr, 0, end);

    return 0;
}
