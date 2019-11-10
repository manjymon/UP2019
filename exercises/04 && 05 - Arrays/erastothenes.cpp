#include <iostream>

unsigned sieve_10000(int output[], unsigned begin)
{
    bool sieve[10000]{};
    for (unsigned i = 2; i < 100; ++i)
    {
        if (!sieve[i])
        {
            for (unsigned j = i * i; j < 10000; j+=i)
            {
                sieve[j] = true;
            }
        }
    }
    
    for (unsigned i = 2; i < 10000; ++i)
    {
        if (!sieve[i])
        {
            output[begin++] = i;
        }
    }
    
    return begin;
}

void print(const int arr[], unsigned begin, unsigned end)
{
    for (begin; begin != end; ++begin)
    {
        std::cout << arr[begin] << ' ';
    }
    std::cout << '\n';
}

int main()
{
    int arr[10000]{};
    unsigned size{sieve_10000(arr, 0)};
    
    print(arr, 0, size);
}
