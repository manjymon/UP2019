#include <iostream>

unsigned digits_product(unsigned num)
{
    unsigned ones = num % 10;
    unsigned tens = num / 10 % 10;
    unsigned hundreds = num / 100;

    return ones * tens * hundreds;
}

bool same_digits_product(int num1, int num2)
{
    return digits_product(num1) == digits_product(num2);
}

unsigned reverse(unsigned num)
{
    unsigned ones = num % 10;
    unsigned tens = num / 10 % 10;
    unsigned hundreds = num / 100;

    return ones * 100 + tens * 10 + hundreds;
}

int main()
{
    int num1{};
    int num2{};

    std::cin >> num1 >> num2;

    std::cout << same_digits_product(num1, num2) << '\n';

    std::cout << reverse(num1) << '\n';

    return 0;
}
