#include <iostream>

bool two_with_given_sum(const int arr[], unsigned begin, unsigned end, int sum)
{
    if (begin == end)
    {
        return false;
    }

    --end;

    while (begin != end)
    {
        int current_sum{arr[begin] + arr[end]};
        if (current_sum == sum)
        {
            return true;
        }

        if (current_sum < sum)
        {
            begin++;
        }
        else
        {
            end--;
        }
    }

    return false;
}

bool three_with_given_sum(const int arr[], unsigned begin, unsigned end, int sum)
{
    if (begin == end)
    {
        return false;
    }

    for (unsigned i = begin; i != end; ++i)
    {
        int remainder{sum - arr[begin]};
        if (two_with_given_sum(arr, begin + 1, end, remainder))
        {
            return true;
        }
    }

    return false;
}

int main()
{

    int arr[]{1, 2, 3, 4};

    std::cout << std::boolalpha << two_with_given_sum(arr, 0, 4, 6) << '\n'; // -> true (2 and 4)
    std::cout << std::boolalpha << two_with_given_sum(arr, 0, 4, 2) << '\n'; // -> false
    std::cout << std::boolalpha << three_with_given_sum(arr, 0, 4, 6) << '\n'; // -> true (1, 2, 3)
    std::cout << std::boolalpha << three_with_given_sum(arr, 0, 4, 2) << '\n'; // -> false
    return 0;
}
