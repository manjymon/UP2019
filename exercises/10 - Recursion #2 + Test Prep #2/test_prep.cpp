#include <cstring>
#include <iostream>

const unsigned max_size = 100;

// abcdef, cba -> true
bool reversed_prefix(const char * word, const char * candidate)
{
    unsigned candidate_length = strlen(candidate);
    unsigned word_length = strlen(word);

    if (candidate_length > word_length)
    {
        return false;
    }

    for (unsigned i = 0; i < candidate_length; ++i)
    {
        if (candidate[candidate_length - 1 - i] != word[i])
        {
            return false;
        }
    }

    return true;
}

bool cyclical_palindrome_from_pos(const char* word, unsigned length, unsigned start)
{
    for (unsigned i = 0; i < length / 2; ++i)
    {
        if (word[(start + i) % length] != word[(start - 1 - i + length) % length])
        {
            return false;
        }

    }

    return true;
}

// orrobborrow -> 5, borroworrob -> 0, borr -> -1, obichammachibozaaz -> 6
int cyclical_palindrome(const char* word)
{
    unsigned length = strlen(word);

    for (unsigned i = 0; i < length; ++i)
    {
        if (cyclical_palindrome_from_pos(word, length, i))
        {
            return i;
        }
    }

    return -1;
}

bool valid_directions(const bool lab[max_size][max_size], unsigned height, unsigned width,
                      const char * directions)
{
    unsigned x{height - 1};
    unsigned y{width - 1};
    unsigned directions_length = strlen(directions);

    if (!directions_length)
    {
        return lab[x][y];
    }

    for (int i = directions_length - 1; i >= 0; --i)
    {
        if (!lab[x][y])
        {
            return false;
        }

        switch (directions[i])
        {
            case 'E':
            {
                if (y == 0)
                {
                    return false;
                }
                y--;
                break;
            }

            case 'W':
            {
                if (y == width - 1)
                {
                    return false;
                }

                y++;
                break;
            }

            case 'N':
            {
                if (x == height - 1)
                {
                    return false;
                }
                x++;
                break;
            }

            case 'S':
            {
                if (x == 0)
                {
                    return false;
                }
                x--;
                break;
            }

            default:
            {
                return false;
            }
        }
    }

    return lab[x][y];
}

bool equal_row_and_column(const int matrix[max_size][max_size], unsigned size, unsigned i)
{
    for (unsigned start = 0; start < size; ++start)
    {
        if (matrix[i][start] != matrix[start][i])
        {
            return false;
        }
    }

    return true;
}

unsigned count_equal_rows_and_columns(const int matrix[max_size][max_size], unsigned size)
{
    unsigned count{0};

    for (unsigned i = 0; i < size; ++i)
    {
        count += equal_row_and_column(matrix, size, i);
    }

    return count;
}

int index(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return c - 'a';
    }

    if (c >= 'A' && c <= 'Z')
    {
        return c - 'A';
    }

    return 26;
}

void alpha_count(const char* str)
{
    unsigned char_map[27]{0};

    for (; *str; ++str)
    {
        ++char_map[index(*str)];
    }

    for (unsigned i = 0 ; i < 26; ++i)
    {
        if (unsigned count = char_map[i]; count)
        {
            std::cout << static_cast<char>('A' + i) << ": " << count << '\n';
        }
    }
}

const char* parent(const char* child, const char * const knowledge_base[max_size][2], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
    {
        if (strcmp(child, knowledge_base[i][0]) == 0)
        {
            return knowledge_base[i][1];
        }
    }

    return "";
}

bool inheritor(const char* predecessor, const char* ancestor,
               const char * const knowledge_base[max_size][2], unsigned size)
{
    const char* p{parent(predecessor, knowledge_base, size)};

    if (strcmp(p, "") == 0)
    {
        return false;
    }

    if (strcmp(p, ancestor) == 0)
    {
        return true;
    }

    return inheritor(p, ancestor, knowledge_base, size);
}

bool can_read_word_from(const char table[max_size][max_size], int size,
                        const char* word, int x, int y)
{
    if (!strlen(word))
    {
        return true;
    }

    if (x < 0 || y < 0 || x >= size || y >= size)
    {
        return false;
    }

    if (table[x][y] != *word)
    {
        return false;
    }

    return can_read_word_from(table, size, word + 1, x + 1, y - 1) ||
           can_read_word_from(table, size, word + 1, x + 1, y + 1) ||
           can_read_word_from(table, size, word + 1, x - 1, y - 1) ||
           can_read_word_from(table, size, word + 1, x - 1, y + 1);
}

bool can_read_word(const char table[max_size][max_size], unsigned size,
                   const char* word)
{
    for (unsigned x = 0; x < size; ++x)
    {
        for (unsigned y = 0; y < size; ++y)
        {
            if (can_read_word_from(table, size, word, x, y))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    const bool lab[max_size][max_size]{
        {1, 1, 1},
        {1, 1, 0},
        {1, 1, 1}
    };

    std::cout << std::boolalpha << valid_directions(lab, 3, 3, "SS") << '\n'
                                << valid_directions(lab, 3, 3, "ESSW") << '\n'
                                << valid_directions(lab, 3, 3, "WSSE") << '\n';

    const int matrix[max_size][max_size]{
        {1, 1, 0, 1},
        {1, 0, 1, 1},
        {0, 1, 1, 0},
        {1, 1, 1, 1}
    };

    std::cout << count_equal_rows_and_columns(matrix, 4) << '\n';

    alpha_count("This is some text!!!");

    const char* kb[max_size][2]{
        {"Go6o", "Stavri"},
        {"Stavri", "Stamat"},
        {"Spartak", "Stamat"},
        {"Pe6o", "Go6o"}
    };

    std::cout << parent("Pe6o", kb, 4) << '\n'
              << parent("Stamat", kb, 4) << '\n';

    std::cout << std::boolalpha << inheritor("Pe6o", "Stamat", kb, 4) << '\n'
                                << inheritor("Pe6o", "Spartak", kb, 4) << '\n';

    const char table[max_size][max_size]{
        {'a', 'p', 'p', 'd'},
        {'k', 'a', 'x', 'p'},
        {'c', 'a', 'a', 'p'},
        {'a', 'k', 'e', 'r'},
    };

    return 0;
}
