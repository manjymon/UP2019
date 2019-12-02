#include <iostream>

const unsigned max_size = 100;

void flood_fill(int screen[][max_size], unsigned height, unsigned width,
                int x, int y,
                unsigned starting_color, unsigned new_color)
{
    if (x < 0 || x >= height || y < 0 || y >= width)
    {
        return;
    }
    
    if (screen[x][y] != starting_color)
    {
        return;
    }
    
    screen[x][y] = new_color;
    
    flood_fill(screen, height, width, x + 1, y    , starting_color, new_color);
    flood_fill(screen, height, width, x    , y + 1, starting_color, new_color);
    flood_fill(screen, height, width, x - 1, y    , starting_color, new_color);
    flood_fill(screen, height, width, x    , y - 1, starting_color, new_color);
}

void flood_fill(int screen[][max_size], unsigned height, unsigned width,
                int x, int y,
                unsigned new_color)
{
    flood_fill(screen, height, width, x, y, screen[x][y], new_color);
}

void print_matrix(int arr[][max_size], unsigned height, unsigned width)
{
    for (unsigned i = 0; i < width; ++i)
    {
        for (unsigned j = 0; j < height; ++j)
        {
            std::cout << arr[i][j] << ' ';
        }
        
        std::cout << '\n';
    }
}

int main()
{
    int screen[][max_size]{
        {0, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 0, 0},
        {1, 1, 1, 0, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 0, 1, 1, 1},
        {0, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 0, 0}
    };

    flood_fill(screen, 7, 7, 0, 3, 2);
    print_matrix(screen, 7, 7);

    return 0;
}
