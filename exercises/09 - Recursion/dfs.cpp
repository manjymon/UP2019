#include <iostream>

const unsigned max_size{100};

bool path(bool arr[][max_size], unsigned height, unsigned width,
          int x_source, int y_source,
          int x_target, int y_target)
{
    if (x_source < 0 || y_source < 0 || x_source >= height || y_source >= width)
    {
        return false;
    }

    if (arr[x_source][y_source])
    {
        return false;
    }

    if (x_source == x_target && y_source == y_target)
    {
        return true;
    }

    arr[x_source][y_source] = true;

    bool has_path{
        path(arr, height, width, x_source - 1, y_source    , x_target, y_target) ||
        path(arr, height, width, x_source + 1, y_source    , x_target, y_target) ||
        path(arr, height, width, x_source    , y_source - 1, x_target, y_target) ||
        path(arr, height, width, x_source    , y_source + 1, x_target, y_target)
    };

    arr[x_source][y_source] = false;

    return has_path;
}

int main()
{
    bool grid[][max_size]{
        {0, 0, 0, 0},
        {0, 0, 1, 0},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };

    std::cout << std::boolalpha
              << path(grid, 4, 4, 0, 0, 1, 3) // true
              << '\n'
              << path(grid, 4, 4, 0, 0, 3, 1); // false

    return 0;
}
