#include <iostream>

int branchless_max(int num1, int num2)
{
    return (num1 >= num2) * num1 + (num1 < num2) * num2;
}

int main()
{
    int num1{};
    int num2{};

    std::cin >> num1 >> num2;

    std::cout << branchless_max(num1, num2);

    return 0;
}
