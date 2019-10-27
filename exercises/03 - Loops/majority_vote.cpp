#include <iostream>

int majority_vote(unsigned n)
{
    unsigned count{0};
    int candidate{};

    for (unsigned i = 0; i < n; i++)
    {
        int number{};
        std::cin >> number;

        if (!count)
        {
            candidate = number;
            count = 1;
        }
        else if (candidate == number)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    return candidate;
}

int main()
{
    std::cout << majority_vote(5) << std::endl;
    return 0;
}
