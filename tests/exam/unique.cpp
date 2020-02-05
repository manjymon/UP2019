#include <iostream>

unsigned count_if_true(const bool * begin, const bool * end)
{
    unsigned count{0};

    for (; begin != end; ++begin)
    {
        count += *begin;
    }

    return count;
}

/*const*/ char * unique(const char * s)
{
    bool char_set[256]{};

    for (const char * it{s}; *it; ++it)
    {
        char_set[static_cast<int>(*it)] = true;
    }

    unsigned len{count_if_true(std::begin(char_set), std::end(char_set)) + 1};

    char * result{new char[len]{}};
    char * output_it{result};

    for (const char * input_it{s}; *input_it; ++input_it)
    {
        if (char_set[static_cast<int>(*input_it)])
        {
            *(output_it++) = *input_it;
            char_set[static_cast<int>(*input_it)] = false;
        }
    }

    return result;
}

int main()
{
    const char * result{unique("I love programming with cpp")};
    std::cout << result << '\n';

    delete [] result;

    return 0;
}
