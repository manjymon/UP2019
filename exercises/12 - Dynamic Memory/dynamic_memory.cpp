#include <algorithm>
#include <iostream>

// ... no structs :(

void print(const int * begin, const int * end)
{
    for (; begin != end; ++begin)
    {
        std::cout << *begin << ' ';
    }

    std::cout << std::endl;
}

int * expand(int * begin, int *& size, int *& capacity)
{
    long memory_length{((capacity - begin) * 3 + 1) / 2};
    long data_length{size - begin};

    // Allocate more memory
    int * new_begin{new int[memory_length]};

    // Copy the old array into the newer, larger block
    std::copy(begin, size, new_begin);

    // Update sizes
    capacity = new_begin + memory_length;
    size = new_begin + data_length;

    // Delete the old block
    delete [] begin;

    return new_begin;
}

int * append(int * begin, int *& size, int *& capacity, int element)
{
    if (size == capacity)
    {
        std::cout << "Allocating\n";
        begin = expand(begin, size, capacity);
    }

    *size++ = element;

    return begin;
}

int main()
{
    int * vector{new int[1]{}};
    int * capacity{vector + 1};
    int * size{vector};

    for (int i{0}; i < 18; ++i)
    {
        vector = append(vector, size, capacity, i);
        print(vector, size);
    }

    return 0;
}
