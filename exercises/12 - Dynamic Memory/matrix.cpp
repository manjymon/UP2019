#include <iostream>
#include <algorithm>

// height + 1 allocations => height + 1 deallocations
// loop
// height + 1 pointers
// Double indirection
// Scattered memory => bad cache performance
int ** allocate_2d_array_matrix(size_t height, size_t width)
{
    int ** matrix = new int * [height]{};
    for (size_t i{0}; i < height; ++i)
    {
        matrix[i] = new int[width]{};
    }

    return matrix; // BAD: Simply returning a pointer to the heap is not a good idea but we don't have the right tools yet.
}

void deallocate_2d_array_matrix(int ** matrix, size_t height)
{
    for (size_t i{0}; i < height; ++i)
    {
        delete [] matrix[i];
    }

    delete [] matrix;
}

// + Single allocation => single deallocation
// + One operation
// + Single pointer
// + Consecutive memory => good cache performance
// - We have to deal with the indexing ourselves
int * allocate_1d_array_matrix(size_t height, size_t width)
{
    return new int[height * width]; // Still BAD.
}

void deallocate_1d_array_matrix(int * matrix)
{
    delete [] matrix;
}

int& element_at(int * matrix, size_t width, size_t i, size_t j)
{
    return matrix[i * width + j];
}

int main()
{
    size_t height{3};
    size_t width{3};

    int ** matrix{allocate_2d_array_matrix(height, width)};
    for (size_t i{0}; i < height; ++i)
    {
        for (size_t j{0}; j < width; j++)
        {
            matrix[i][j] = 10 * (i + 1) + j + 1;
        }
    }

    for (size_t i{0}; i < height; ++i)
    {
        for (size_t j{0}; j < width; j++)
        {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
    deallocate_2d_array_matrix(matrix, height);

    int * matrix1d{allocate_1d_array_matrix(height, width)};
    for (size_t i{0}; i < height; ++i)
    {
        for (size_t j{0}; j < width; j++)
        {
            element_at(matrix1d, width, i, j) = 10 * (i + 1) + j + 1;
        }
    }

    for (size_t i{0}; i < height; ++i)
    {
        for (size_t j{0}; j < width; j++)
        {
            std::cout << element_at(matrix1d, width, i, j) << ' ';
        }
        std::cout << '\n';
    }
    deallocate_1d_array_matrix(matrix1d);

    return 0;
}
