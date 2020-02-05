#include <iostream>

double average(const double * begin, const double * end)
{
    long size{end - begin};
    double sum{0};
    for (; begin != end; ++begin)
    {
	   sum += *begin;
    }

    return sum / size;
}

/*const*/ double * average(/*const*/ double A[][10], unsigned rows)
{
    double * averages{new double[rows]};
    for (unsigned i{0}; i < rows; ++i)
    {
        averages[i] = average(A[i], A[i] + 10);
    }

    return averages;
}

int main()
{
    double matrix[][10] {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 2, 1, 2, 1, 2, 1, 2, 1, 2},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
    };

    const double * averages{average(matrix, 3)};

    for (unsigned i{0}; i < 3; ++i)
    {
        std::cout << averages[i] << '\n';
    }

    delete [] averages;

    return 0;
}
