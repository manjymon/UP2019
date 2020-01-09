#include <iostream>

void iota(int * begin, int * end, int value)
{
    for (; begin != end; ++begin)
    {
        *begin = value++;
    }
}

int main()
{
    int range[10]{};
    iota(std::begin(range), std::end(range), 0);

    for (int num : range)
    {
        std::cout << num << ' ';
    }

    std::cout << '\n';

    return 0;
}
