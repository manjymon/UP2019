#include <iostream>

// Change this to 2 for var2
const unsigned BASE{2};

unsigned count_digits(unsigned i)
{
    unsigned digits{1};

    while (i /= BASE)
    {
        ++digits;
    }

    return digits;
}

/*const*/ char * to_string(unsigned i)
{
    unsigned len{count_digits(i)};

    char * result{new char[len + 1]{}};

    for (char * output_it{result + len - 1}; output_it >= result; --output_it)
    {
        *output_it = i % BASE + '0';
        i /= BASE;
    }

    return result;
}

int main()
{
    const char * num_str{to_string(1024)};

    std::cout << num_str << '\n';

    delete [] num_str;

    return 0;
}
