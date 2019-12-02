#include <iostream>

unsigned factorial(unsigned n)
{
    return n ? n * factorial(n - 1) : 1;
}

unsigned fib(unsigned n)
{
    return n <= 1 ? 1 : fib(n - 1) + fib(n - 2);
}

int exponent(int a, unsigned n)
{
    return n ? a * exponent(a, n - 1) : 1;
}

int fast_exponent(int a, unsigned n)
{
    return n ? (n % 2 ? a * fast_exponent(a, n - 1) : fast_exponent(a * a, n / 2)) : 1;
}

int sum(const int* begin, const int* end)
{
    return begin == end ? 0 : *begin + sum(begin + 1, end);
}

int main()
{
    std::cout << factorial(6) << '\n';
    std::cout << fib(9) << '\n';
    std::cout << exponent(2, 10) << '\n';
    std::cout << fast_exponent(-2, 11) << '\n';

    int arr[]{1, 2, 3, 4, 5};
    std::cout << sum(std::begin(arr), std::end(arr));

    return 0;
}
