#include <algorithm>
#include <iostream>

int * find(int * first, int * last, int element)
{
    if (first == last)
    {
        return first;
    }
    
    return *first == element ?
        first :
        find(first + 1, last, element);
}

bool is_sorted(int * first, int * last)
{
    if (last - first < 2)
    {
        return true;
    }
    
    return *first <= *(first + 1) && is_sorted(first + 1, last);
}

bool equal_range(int * first1, int * last1, int * first2)
{
    if (first1 == last1)
    {
        return true;
    }
    
    return *first1 == *first2 && equal_range(first1 + 1, last1, first2 + 1);
}

int * min_element(int * first, int * last)
{
    if (last - first < 2)
    {
        return first;
    }
    
    int * min_rest = min_element(first + 1, last);
    
    return *first <= *min_rest ? first : min_rest;
}

void selection_sort(int * first, int * last)
{
    if (first != last)
    {
        std::iter_swap(first, min_element(first, last));
        selection_sort(first + 1, last);
    }
}

int * lower_bound(int * first, int * last, int element)
{
    if (first == last)
    {
        return first;
    }
    
    int * mid = first + (last - first) / 2;
    
    return *mid < element ?
        lower_bound(mid + 1, last, element) :
        lower_bound(first, mid, element);
}

void insertion_sort(int * first, int * last)
{
    if (first != last)
    {
        insertion_sort(first + 1, last);
        std::rotate(first, first + 1, lower_bound(first + 1, last, *first));
    }
}

int main()
{
    int arr[]{4, 3, 2, 1, 5};
    std::cout << *find(std::begin(arr), std::end(arr), 2) << std::endl;
    std::cout << std::boolalpha << is_sorted(std::begin(arr), std::end(arr)) << std::endl;
    int sarr[]{1, 2, 3, 4, 5};
    std::cout << std::boolalpha << is_sorted(std::begin(sarr), std::end(sarr)) << std::endl;
    
    std::cout << std::boolalpha << equal_range(std::begin(arr), std::end(arr), std::begin(sarr)) << std::endl
                                << equal_range(std::begin(sarr), std::end(sarr), std::begin(sarr)) << std::endl;

    std::cout << *min_element(std::begin(arr), std::end(arr)) << std::endl;
    
    int carr[]{4, 3, 2, 1, 5};
    // selection_sort(std::begin(carr), std::end(carr));
    insertion_sort(std::begin(carr), std::end(carr));
    std::cout << std::boolalpha << is_sorted(std::begin(carr), std::end(carr)) << std::endl;
}
