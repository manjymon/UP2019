#include <cstring>
#include <iostream>

const unsigned max_size = 100;

void print(const int board[max_size], int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            std::cout << (board[i] == j ? 'Q' : '_') << ' ';
        }

        std::cout << '\n';
    }
}

bool can_place_queen(const int board[max_size], int current_queen, int pos)
{
    int sum{current_queen + pos};
    int diff{current_queen - pos};

    for (int i = 0; i < current_queen; ++i)
    {
        if (board[i] == pos)
        {
            return false;
        }

        if (i + board[i] == sum)
        {
            return false;
        }

        if (i - board[i] == diff)
        {
            return false;
        }
    }

    return true;
}

bool n_queens(int board[max_size], int size, int current_queen)
{
    if (current_queen == size)
    {
        print(board, size);
        return true;
    }

    for (int i = 0; i < size; ++i)
    {
        if (can_place_queen(board, current_queen, i))
        {
            board[current_queen] = i;
            if (n_queens(board, size, current_queen + 1))
            {
                return true;
            }
        }
    }

    return false;
}

bool n_queens(int size)
{
    int board[max_size]{};

    if (size < 4)
    {
        return false;
    }

    return n_queens(board, size, 0);
}

int main()
{
    n_queens(4);

    return 0;
}
