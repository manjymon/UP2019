#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>

int * sample(const int * begin, const int * end, int * out, unsigned samples)
{
    unsigned size = end - begin;
    samples = std::min(samples, size);

    int * result{std::copy(begin, begin + samples, out)};

    std::random_device rd;
    std::mt19937 gen(rd());

    for (const int * i = begin + samples; i < end; ++i)
    {
        unsigned random_index{std::uniform_int_distribution<unsigned>(0, i - begin - 1)(gen)};
        if (random_index < samples)
        {
            out[random_index] = *i;
        }
    }

    return result;
}

int main()
{
    int arr[10]{};
    std::iota(std::begin(arr), std::end(arr), 0);
    int samples[10]{};

    int * samples_end{sample(std::begin(arr), std::end(arr), std::begin(samples), 3)};

    for (int * i = std::begin(samples); i < samples_end; ++i)
    {
        std::cout << *i << ' ';
    }

    std::cout << '\n';

    samples_end = sample(std::begin(arr), std::end(arr), std::begin(samples), 3);

    for (int * i = std::begin(samples); i < samples_end; ++i)
    {
        std::cout << *i << ' ';
    }

    std::cout << '\n';

    return 0;
}
