#include <cstring>
#include <iostream>

/*
    Modified version of a problem from Ex07s Bonus
        - Change to char pointers
        - Add variable offset to support columns (alternatively you can copy the columns into regular char arrays instead)
*/
const char * search(const char * begin, const char * end, const char * s_begin, const char * s_end, size_t offset)
{
    for (; begin != end; begin += offset)
    {
        for (const char* it = begin, *s_it = s_begin; *it == *s_it; it += offset, ++s_it)
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

const int size = 5;

bool contains(const char A[size][size], const char * s)
{
    for (unsigned i{0}; i < size; ++i)
    {
        const char * row_start{A[i]};
        const char * row_end{row_start + size};
        const char * column_start{&A[0][i]};
        const char * column_end{column_start + size * size};
        const char * s_end = s + strlen(s);

        if (search(row_start, row_end, s, s_end, 1) != row_end)
        {
            return true;
        }
        
        if (search(column_start, column_end, s, s_end, size) != column_end)
        {
            return true;
        }
    }
    
    return false;
}

int main()
{
    const char A[5][5]{
        {'a', 'b', 'g', 'o', 'd'},
        {'r', 'o', 'c', 'a', 't'},
        {'1', '2', 'a', '4', '5'},
        {'d', 'e', 't', 'd', 'o'},
        {'6', 'd', 'o', '9', 'g'}
    };
    
    std::cout << std::boolalpha << contains(A, "rocat") << '\n'  // true
                                << contains(A, "god")   << '\n'  // true
                                << contains(A, "dog")   << '\n'  // false
                                << contains(A, "bo2ed") << '\n'  // true
                                << contains(A, "r1d")   << '\n'  // true
                                << contains(A, "zzz")   << '\n'; // false
    
    return 0;
}
