#include <cstring>
#include <iostream>

void print_range(const char * begin, const char * end)
{
    for (; begin != end; ++begin)
    {
        std::cout << *begin;
    }
}

const char * find_last_word(const char * begin, const char * end)
{
    for (--end; end > begin; --end)
    {
        if (*end == ' ')
        {
            return end + 1;
        }
    }

    return end;
}

void backwards_rec(const char * begin, const char * end);

void backwards(const char * s)
{
    backwards_rec(s, s + strlen(s));
}

void backwards_rec(const char * begin, const char * end)
{
    const char * last_word_begin{find_last_word(begin, end)};
    print_range(last_word_begin , end);

    if (last_word_begin != begin)
    {
        std::cout << ' ';
        backwards_rec(begin, last_word_begin - 1);
    }
}

int main()
{
    backwards("i love programming with cpp"); // "cpp with programming love i"
    std::cout << '\n';

    return 0;
}
