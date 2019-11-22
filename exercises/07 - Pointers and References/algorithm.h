#include <iostream>

#pragma once

void swap(int& a, int& b)
{
    int c = a;
    a = b;
    b = c;
}

void iter_swap(int* a, int* b)
{
    swap(*a, *b);
}

void print(const int* begin, const int* end)
{
    for (; begin != end; ++begin)
    {
        std::cout << *begin << ' ';
    }

    std::cout << '\n';
}

void reverse(int* begin, int* end)
{
    for (; begin !=end && begin != --end; ++begin)
    {
        iter_swap(begin, end);
    }
}

int* copy(const int* input_begin, const int* input_end,
          int* output_begin)
{
    for (; input_begin != input_end; ++input_begin)
    {
        *(output_begin++) = *input_begin;
    }

    return output_begin;
}

int* rotate(int* begin, int* mid, int* end)
{
    reverse(begin, mid);
    reverse(mid, end);
    reverse(begin, end);

    return begin + (end - mid);
}

int* erase(int* begin, int* end, unsigned index)
{
    int* element_position = begin + index;
    return rotate(element_position, element_position + 1, end);
}

int* insert(int* begin, int* end, unsigned index, int element)
{
    int* element_position = begin + index;

    *end = element;
    rotate(element_position, end, end + 1);

    return end + 1;
}

const int* find(const int* begin, const int* end, int element)
{
    for (; begin != end; ++begin)
    {
        if (*begin == element)
        {
            return begin;
        }
    }

    return begin;
}

int* find(int* begin, int* end, int element)
{
    for (; begin != end; ++begin)
    {
        if (*begin == element)
        {
            return begin;
        }
    }

    return begin;
}

bool contains(const int* begin, const int* end, int element)
{
    return find(begin, end, element) != end;
}

int inner_product(const int* begin_1, const int* end_1,
                  const int* begin_2)
{
    int result{0};

    for (; begin_1 != end_1; ++begin_1, ++begin_2)
    {
        result += *begin_1 * *begin_2;
    }

    return result;
}

int* partial_sum(const int* input_begin, const int* input_end,
                 int* output_begin)
{
    int sum{0};

    for(; input_begin != input_end; ++input_begin)
    {
        *(output_begin++) = sum += *input_begin;
    }

    return output_begin;
}

int* adjacent_difference(const int* input_begin, const int* input_end,
                         int* output_begin)
{
    int last{0};

    for(; input_begin != input_end; ++input_begin)
    {
        int current = *input_begin;
        *(output_begin++) = current - last;
        last = current;
    }

    return output_begin;
}

const int* min_element(const int* begin, const int* end)
{
    const int* min_element{begin};
    int minimum(*begin);

    for (; begin != end; ++begin)
    {
        if (*begin < minimum)
        {
            minimum = *begin;
            min_element = begin;
        }
    }

    return min_element;
}

int* min_element(int* begin, int* end)
{
    int* min_element{begin};
    int minimum(*begin);

    for (; begin != end; ++begin)
    {
        if (*begin < minimum)
        {
            minimum = *begin;
            min_element = begin;
        }
    }

    return min_element;
}

void selection_sort(int* begin, int* end)
{
    for (; begin != end; ++begin)
    {
        iter_swap(begin, min_element(begin, end));
    }
}

int* merge(const int* input_begin_1, const int* input_end_1,
           const int* input_begin_2, const int* input_end_2,
           int* output_begin)
{
    while (input_begin_1 != input_end_1 && input_begin_2 != input_end_2)
    {
        if (*input_begin_1 <= *input_begin_2)
        {
            *(output_begin++) = *(input_begin_1++);
        }
        else
        {
            *(output_begin++) = *(input_begin_2++);
        }
    }

    output_begin = copy(input_begin_1, input_end_1, output_begin);
    return copy(input_begin_2, input_end_2, output_begin);
}

const int* upper_bound(const int* begin, const int* end, int element)
{
    while (begin < end)
    {
        const int* mid{begin + (end - begin) / 2};

        if (element >= *mid)
        {
            begin = mid + 1;
        }
        else
        {
            end = mid; 
        }
    }

    return begin;
}

int* upper_bound(int* begin, int* end, int element)
{
    while (begin < end)
    {
        int* mid{begin + (end - begin) / 2};

        if (element >= *mid)
        {
            begin = mid + 1;
        }
        else
        {
            end = mid; 
        }
    }

    return begin;
}

bool binary_search(const int* begin, const int* end, int element)
{
    const int* greater = upper_bound(begin, end, element);
    return greater != begin && *(greater - 1) == element;
}

void insertion_sort(int* begin, int* end)
{
    for (int* i = begin; i != end; ++i)
    {
        rotate(upper_bound(begin, i, *i), i, i + 1);
    }
}
