#include <iostream>

int* partition(int* begin, int* end, int pivot)
{
    for (int* i = begin; i != end; ++i)
    {
        if (*i <= pivot)
        {
            std::iter_swap(begin, i);
            ++begin;
        }
    }

    return begin;
}

void quick_sort(int* begin, int* end)
{
    if (end == begin)
    {
        return;
    }
    
    int* mid = partition(begin, end, *begin);
    std::iter_swap(begin, mid - 1);
    
    quick_sort(begin, mid - 1);
    quick_sort(mid, end);
}

int main()
{
    int arr[]{1, 0, 2, 3, 1, 4, 2, 3, 5};
    quick_sort(std::begin(arr), std::end(arr));

    for (int num : arr)
    {
        std::cout << num << ' ';
    }

    return 0;
}
