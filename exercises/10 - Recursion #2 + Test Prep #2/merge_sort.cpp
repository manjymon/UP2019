#include <algorithm>
#include <iostream>

const unsigned max_size{200};

void inplace_merge(int* begin, int* mid, int* end)
{
    int buffer[max_size];
    int* buffer_end = std::merge(begin, mid, mid, end, buffer); // See exercise 04 (index based implementation) or 07 (this implementation)
    std::copy(std::begin(buffer), buffer_end, begin);
}

void merge_sort(int* begin, int* end)
{
    if (end - begin <= 1)
    {
        return;
    }

    int* mid = begin + (end - begin) / 2;
    merge_sort(begin, mid);
    merge_sort(mid, end);
    inplace_merge(begin, mid, end);
}

int main()
{
    int arr[]{1, 3, 2, 1, 2, 3, 2, 1, 9, 0, 8, 10};
    merge_sort(std::begin(arr), std::end(arr));

    for (int num : arr)
    {
        std::cout << num << ' ';
    }

    return 0;
}
