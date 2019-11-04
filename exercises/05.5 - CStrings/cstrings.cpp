#include <iostream>

// Let's pretend templates don't exist
unsigned copy(const char input_arr[], unsigned input_begin, unsigned input_end,
              char output_arr[], unsigned output_begin)
{
    for (input_begin; input_begin != input_end; ++input_begin)
    {
        output_arr[output_begin++] = input_arr[input_begin];
    }

    return output_begin;
}

// Let's pretend pointers don't exist
unsigned strlen(const char str[])
{
    unsigned i{0};
    while (str[i])
    {
        ++i;
    }

    return i;
}

int strcmp(const char lhs[], const char rhs[])
{
    unsigned i{0};
    while (lhs[i] && rhs[i] && lhs[i] == rhs[i])
    {
        ++i;
    }

    return lhs[i] - rhs[i];
}

// Let's stop pretending that pointers don't exist as we need them here
char * strcpy(char dest[], const char src[])
{
    copy(src, 0, strlen(src) + 1, dest, 0);
    return dest;
}

char * strcat(char dest[], const char src[])
{
    strcpy(dest + strlen(dest), src); // another pointer :)
    return dest;
}

char get_relation(int delta);

int main()
{
    const unsigned SIZE = 100;
    char buffer1[SIZE]{};
    char buffer2[SIZE]{};
    std::cin.getline(buffer1, SIZE);
    std::cin.getline(buffer2, SIZE);

    std::cout << buffer1 << " " << buffer2 << '\n';
    std::cout << strlen(buffer1) << " " << strlen(buffer2) << '\n';
    std::cout << buffer1 << " " << get_relation(strcmp(buffer1, buffer2)) << " " << buffer2 << '\n';

    std::cout << strcat(buffer1, buffer2);
    return 0;
}

char get_relation(int delta)
{
    if (delta < 0)
    {
        return '<';
    }

    if (delta == 0)
    {
        return '=';
    }

    return '>';
}
