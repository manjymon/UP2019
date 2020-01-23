#include <iostream>
#include <algorithm>

using UnaryPredicate = bool(*)(int);
using Comparator = bool(*)(int, int);
using UnaryOperation = int(*)(int);
using BinaryOperation = int(*)(int, int);
using UnaryProcedure = void(*)(int);

bool all_of(const int * begin, const int * end, UnaryPredicate p)
{
    for (; begin != end; ++begin)
    {
        if (!p(*begin))
        {
            return false;
        }
    }

    return true;
}

bool any_of(const int * begin, const int * end, UnaryPredicate p)
{
    for (; begin != end; ++begin)
    {
        if (p(*begin))
        {
            return true;
        }
    }

    return false;
}

bool none_of(const int * begin, const int * end, UnaryPredicate p)
{
    for (; begin != end; ++begin)
    {
        if (p(*begin))
        {
            return false;
        }

        return true;
    }
}

void for_each(const int * begin, const int * end, UnaryProcedure p)
{
    for (; begin != end; ++begin)
    {
        p(*begin);
    }
}

int * transform(int * begin, int * end, UnaryOperation f)
{
    for (; begin != end; ++begin)
    {
        *begin = f(*begin);
    }

    return begin;
}

unsigned count_if(const int * begin, const int * end, UnaryPredicate p)
{
    unsigned count{0};

    for (; begin != end; ++begin)
    {
        count += p(*begin);
    }

    return count;
}

const int * find_if(const int * begin, const int * end, UnaryPredicate p)
{
    for (; begin != end; ++begin)
    {
        if (p(*begin))
        {
            return begin;
        }
    }

    return begin;
}

int * remove_if(int * begin, int * end, UnaryPredicate p)
{
    for (int * i{begin}; i != end; ++i)
    {
        if (!p(*i))
        {
            *(begin++) = *i;
        }
    }

    return begin;
}

int accumulate(int * begin, int * end, int init, BinaryOperation op)
{
    for (; begin != end; ++begin)
    {
        init = op(init, *begin);
    }

    return init;
}

int inner_product(const int * begin1, const int * end1,
                  const int * begin2, int init,
                  BinaryOperation op1, BinaryOperation op2)
{
    for (; begin1 != end1; ++begin1, ++begin2)
    {
        init = op1(init, op2(*begin1, *begin2));
    }

    return init;
}


int * stable_partition(int * begin, int * end, UnaryPredicate p)
{
    int length{end - begin};

    if (length == 0)
    {
        return begin;
    }

    if (length == 1)
    {
        return begin + p(*begin);
    }

    int * mid{begin + length / 2};
    
    return std::rotate(stable_partition(begin, mid, p),
                       mid,
                       stable_partition(mid, end, p));
}

int count_pairwise_matches(const int * begin1, const int * end1, const int * begin2)
{
    return inner_product(begin1, end1,
                         begin2, 0,
                         [](int a, int b) { return a + b; },
                         [](int a, int b) -> int { return a == b; });
}

int sum_maximums(const int * begin1, const int * end1, const int * begin2)
{
    return inner_product(begin1, end1,
                         begin2, 0,
                         [](int a, int b) { return a + b; },
                         [](int a, int b) { return a >= b ? a : b; });
}

void print_range(const int * begin, const int * end)
{
    for_each(begin, end, [](int elem) { std::cout << elem << ' '; });
    std::cout << '\n';
}

void insertion_sort(int* begin, int* end, Comparator cmp)
{
    for (int * i{begin}; i != end; ++i)
    {
        std::rotate(std::upper_bound(begin, i, *i, cmp), i, i + 1);
    }
}

int main()
{
    int a[]{1, 2, 2};
    int b[]{1, 0, 3};

    std::cout << count_pairwise_matches(a, a + 3, b) << '\n';
    std::cout << sum_maximums(a, a + 3, b) << '\n';

    int to_sort[]{1, 3, 2, 6, 8, 0, 7, 5, 4};
    print_range(std::begin(to_sort), std::end(to_sort));
    insertion_sort(std::begin(to_sort), std::end(to_sort), [](int a, int b){ return a <= b; });
    print_range(std::begin(to_sort), std::end(to_sort));

    insertion_sort(std::begin(to_sort), std::end(to_sort), [](int a, int b){ return a >= b; });
    print_range(std::begin(to_sort), std::end(to_sort));


    insertion_sort(std::begin(to_sort), std::end(to_sort), [](int a, int b){ return a % 3 <= b % 3; });
    print_range(std::begin(to_sort), std::end(to_sort));
    return 0;
}
