#include <iostream>
#include <cmath>

bool knight_can_capture(int x_knight, int y_knight,
                        int x_figure, int y_figure)
{
    return std::abs(x_knight - x_figure) * std::abs(y_knight - y_figure) == 2;
}

int main()
{
    std::cout << knight_can_capture(1, 1, 2, 3) << '\n';
    return 0;
}
