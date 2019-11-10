#include <iostream>

void count_sort(int arr[], unsigned begin, unsigned end)
{
    int counts[100]{};
    
    for (unsigned i = begin; i != end; ++i)
    {
        counts[arr[i]]++;
    }
    
    for (unsigned i = 0; i < 100; ++i)
    {
        for (unsigned j = 0; j < counts[i]; ++j)
        {
            arr[begin++] = i;
        }
    }
}

int main()
{
    int arr[]{0, 3, 2, 1, 1, 4, 1, 5, 6, 3, 2, 2, 0, 3};
    count_sort(arr, 0, 14);
    for (int num : arr)
    {
        std::cout << num << ' ';
    }
    
    return 0;
}
