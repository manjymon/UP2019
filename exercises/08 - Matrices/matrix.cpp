#include <algorithm>
#include <iostream>

const unsigned max_size{100};

void print(const int arr[max_size][max_size], unsigned rows, unsigned columns)
{
    for (unsigned i = 0; i < rows; ++i)
    {
        for (unsigned j = 0; j < columns; ++j)
        {
            std::cout << arr[i][j] << ' ';
        }

        std::cout << '\n';
    }
}

void transpose(const int arr[max_size][max_size], unsigned rows, unsigned columns, int arr_t[max_size][max_size])
{
    for (unsigned i = 0; i < rows; ++i)
    {
        for (unsigned j = 0; j < columns; ++j)
        {
            arr_t[j][i] = arr[i][j];
        }
    }
}

int* min_elements(const int arr[max_size][max_size], unsigned rows, unsigned columns, int* output_begin)
{
    for (unsigned i = 0; i < rows; ++i)
    {
        const int* row_begin{&arr[i][0]};
        *(output_begin++) = *std::min_element(row_begin, row_begin + columns);
    }

    return output_begin;
}

void add(const int a[max_size][max_size], const int b[max_size][max_size], unsigned rows, unsigned columns,
         int res[max_size][max_size])
{
    for (unsigned i = 0 ; i < rows; ++i)
    {
        for (unsigned j = 0; j < rows; ++j)
        {
            res[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiply(const int a[max_size][max_size], unsigned a_rows, unsigned a_columns,
              const int b[max_size][max_size],
              int res[max_size][max_size])
{
    for (unsigned i = 0; i < a_rows; ++i)
    {
        for (unsigned j = 0; j < a_rows; ++j)
        {
            for (unsigned k = 0; k < a_columns; ++k)
            {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int* spiral(const int arr[max_size][max_size], unsigned size, int* output)
{
    unsigned start{0};

    for (; size > start; ++start, --size)
    {
        for (unsigned j = start ; j < size; ++j)
        {
            *(output++) = arr[start][j];
        }

        for (unsigned j = start + 1; j < size; ++j)
        {
            *(output++) = arr[j][size - 1];
        }

        for (unsigned j = size - 2; j > start; --j)
        {
            *(output++) = arr[size - 1][j];
        }

        for (unsigned j = size - 1; j > start; --j)
        {
            *(output++) = arr[j][start];
        }
    }

    return output;
}

int main()
{
    const unsigned arr_rows = 3;
    const unsigned arr_columns = 2;
    const int arr[][max_size]{
        {1, 2},
        {3, 4},
        {5, 6}
    };

    int arr_t[max_size][max_size]{};

    print(arr, arr_rows, arr_columns);

    transpose(arr, arr_rows, arr_columns, arr_t);

    print(arr_t, arr_columns, arr_rows);

    std::cout << "----------------\n";

    int min_elems[max_size]{};

    int* min_elems_end{min_elements(arr, arr_rows, arr_columns, std::begin(min_elems))};

    for (int * i = std::begin(min_elems); i != min_elems_end; ++i)
    {
        std::cout << *i << ' ';
    }
    std::cout << '\n';

    std::cout << "----------------\n";

    const int a[][max_size]{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    const int b[][max_size]{
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int res[max_size][max_size]{};

    add(a, b, 3, 3, res);

    print(res, 3, 3);

    std::cout << "----------------\n";

    const int am[][max_size]{
        {1, 2, 3},
        {4, 5, 6},
    };

    const int bm[][max_size]{
        {7, 8},
        {9, 10},
        {11, 12}
    };

    int resm[max_size][max_size]{};

    multiply(am, 2, 3, bm, resm);

    print(resm, 2, 2);

    std::cout << "----------------\n";

    const int sp4[][max_size]{
        { 1,  2,  3,  4},
        {12, 13, 14,  5},
        {11, 16, 15,  6},
        {10,  9,  8,  7},
    };

    int spiral_arr4[16]{};

    spiral(sp4, 4, spiral_arr4);

    for (int num : spiral_arr4)
    {
        std::cout << num << ' ';
    }

    std::cout << '\n';

    const int sp3[][max_size]{
        {1, 2, 3},
        {8, 9, 4},
        {7, 6, 5},
    };

    int spiral_arr3[9]{};

    spiral(sp3, 3, spiral_arr3);

    for (int num : spiral_arr3)
    {
        std::cout << num << ' ';
    }

    std::cout << '\n';

    return 0;
}
