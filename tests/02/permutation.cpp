#include <iostream>

// Exercise 10, Non-recursive version in Exercise 7s Bonus Problems
bool equal(int * first1, int * last1, int * first2)
{
    if (first1 == last1)
    {
        return true;
    }
    
    return *first1 == *first2 && equal(first1 + 1, last1, first2 + 1);
}

// Ex10, Non-recursive in Ex4
int * min_element(int * first, int * last)
{
    if (last - first < 2)
    {
        return first;
    }
    
    int * min_rest = min_element(first + 1, last);
    
    return *first <= *min_rest ? first : min_rest;
}

// Ex10, Non-recursive in Ex4
void selection_sort(int * first, int * last)
{
    if (first != last)
    {
        std::iter_swap(first, min_element(first, last));
        selection_sort(first + 1, last);
    }
}

// Recursive
bool permutation(int * a, int * b, size_t size)
{
    // return std::is_permutation(a, a + size, b);
    selection_sort(a, a + size);
    selection_sort(b, b + size);

    return equal(a, a + size, b);
}

// Also recursive
bool permutationrec(int * a, int * b, size_t size)
{
    return permutation(a, b, size);
}

int main()
{
    int a[]{1, 1, 2};
    int b[]{1, 2, 1};
    int c[]{1, 2, 2};
    
    std::cout << std::boolalpha << permutationrec(a, b, 3) << '\n'  // true
                                << permutationrec(a, c, 3) << '\n'; // false

    return 0;
}
