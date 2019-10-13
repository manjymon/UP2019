#include <iostream>

int round_up(int number, int divisor)
{   
    return (number + divisor - 1) / divisor * divisor;
}

int main()
{
    int number{};
    int divisor{};

    std::cin >> number >> divisor;

    std::cout << round_up(number, divisor) << '\n';

    return 0;
}
