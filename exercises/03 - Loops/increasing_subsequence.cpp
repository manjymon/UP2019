#include <iostream>

unsigned longest_increasing_subsequence(unsigned n)
{
    if (n < 1)
    {
        return 0;
    }

    int last{};
    std::cin >> last;
    unsigned longest{1};
    unsigned longest_here{1};

    for (unsigned i = 1; i < n; i++)
    {
        int next{};
        std::cin >> next;
        if (next > last)
        {
            longest_here++;
            longest = std::max(longest, longest_here);
        }
        else
        {
            longest_here = 1;
        }

        last = next;
    }

    return longest;
}

int main()
{
    std::cout << longest_increasing_subsequence(5);
    return 0;
}
