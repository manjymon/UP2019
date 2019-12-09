#pragma once

#include "algorithm.h"

bool equal(const int* begin_1, const int* end_1, const int* begin_2, const int* end_2)
{
    for (; begin_1 != end_1 && begin_2 != end_2; ++begin_1, ++begin_2)
    {
        if (*begin_1 != *begin_2)
        {
            return false;
        }
    }

    return begin_1 == end_1 && begin_2 == end_2;
} 

const int* search(const int* begin, const int* end, const int* s_begin, const int* s_end)
{
    for (; begin != end; ++begin)
    {
        for (const int* it = begin, *s_it = s_begin; *it == *s_it; ++it, ++s_it)
        {
            if (s_it + 1 == s_end)
            {
                return begin;
            }
            if (it == end)
            {
                return end;
            }
        }
    }

    return end;
}

int* search(int* begin, int* end, int* s_begin, int* s_end)
{
    for (; begin != end; ++begin)
    {
        for (int* it = begin, *s_it = s_begin; *it == *s_it; ++it, ++s_it)
        {
            if (s_it + 1 == s_end)
            {
                return begin;
            }
            if (it == end)
            {
                return end;
            }
        }
    }

    return end;
}

const int* search_n(const int* begin, const int* end, unsigned count, int elem)
{
    if (!count)
    {
        return begin;
    }

    for (; begin != end; ++begin)
    {
        if (*begin == elem)
        {
            unsigned current{0};
            const int * start{begin};

            for (; *begin == elem; ++begin)
            {
                if (++current == count)
                {
                    return start;
                }
            }
        }
    }

    return end;
}

int* search_n(int* begin, int* end, unsigned count, int elem)
{
    if (!count)
    {
        return begin;
    }

    for (; begin != end; ++begin)
    {
        if (*begin == elem)
        {
            unsigned current{0};
            int * start{begin};

            for (; *begin == elem; ++begin)
            {
                if (++current == count)
                {
                    return start;
                }
            }
        }
    }

    return end;
}

const int* adjacent_find(const int* begin, const int* end)
{
    if (begin == end)
    {
        return end;
    }

    for (const int * next = begin + 1; next != end; ++next, ++begin)
    {
        if (*begin == *next)
        {
            return begin;
        }
    }

    return end;
}

int* adjacent_find(int* begin, int* end)
{
    if (begin == end)
    {
        return end;
    }

    for (int * next = begin + 1; next != end; ++next, ++begin)
    {
        if (*begin == *next)
        {
            return begin;
        }
    }

    return end;
}

const int* find_end(const int* begin, const int* end, const int* s_begin, const int* s_end)
{
    const int * last{end};
    const int * next{search(begin, end, s_begin, s_end)};
    while(next != end)
    {
        last = next;
        next = search(next + 1, end, s_begin, s_end);
    }

    return last;
}

int* find_end(int* begin, int* end, int* s_begin, int* s_end)
{
    int * last{end};
    int * next{search(begin, end, s_begin, s_end)};
    while(next != end)
    {
        last = next;
        next = search(next + 1, end, s_begin, s_end);
    }

    return last;
}

const int* find_first_of(const int* begin, const int* end, const int* s_begin, const int* s_end)
{
    for (; begin != end; ++begin)
    {
        if (contains(s_begin, s_end, *begin))
        {
            return begin;
        }
    }

    return end;
}

int* find_first_of(int* begin, int* end, int* s_begin, int* s_end)
{
    for (; begin != end; ++begin)
    {
        if (contains(s_begin, s_end, *begin))
        {
            return begin;
        }
    }

    return end;
}

void swap_ranges(int* begin_1, int* end_1, int* begin_2)
{
    for (; begin_1 != end_1; ++begin_1, ++begin_2)
    {
        iter_swap(begin_1, begin_2);
    }
}

int* copy_backward(const int* begin, const int* end, int* output_begin)
{
    int* output_end{copy(begin, end, output_begin)};
    reverse(output_begin, output_end);

    return output_end;
}

int* remove(int* begin, int* end, int element)
{
    int* it{begin};

    for (; begin != end; ++begin)
    {
        if (*begin != element)
        {
            *(it++) = *begin; 
        }
    }

    return it;
}

void replace(int* begin, int* end, int old_value, int new_value)
{
    for (; begin != end; ++begin)
    {
        if (*begin == old_value)
        {
            *begin = new_value;
        }
    }
}
