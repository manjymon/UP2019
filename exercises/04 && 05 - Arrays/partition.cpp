#include <iostream>

void print(const int arr[], unsigned begin, unsigned end)
{
    for (begin; begin != end; ++begin)
    {
        std::cout << arr[begin] << ' ';
    }
    std::cout << '\n';
}

unsigned partition(int arr[], unsigned begin, unsigned end, int pivot)
{
    for (unsigned i = begin; i != end; ++i)
    {
        if (arr[i] <= pivot)
        {
            std::swap(arr[begin], arr[i]);
            ++begin;
        }
    }

    return begin;
}

int main()
{
    int arr[]{1, 30, -4, 3, 5, -4, 1, 6, -8, 2, -5, 64, 1, 92};
    std::cout << arr[partition(arr, 0, 13, 0)] << '\n';
    print(arr, 0, 13);
    return 0;
}
