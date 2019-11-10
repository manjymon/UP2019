#include <iostream>

void print(const int arr[], unsigned begin, unsigned end)
{
    for (begin; begin != end; ++begin)
    {
        std::cout << arr[begin] << ' ';
    }
    std::cout << '\n';
}

unsigned copy(const int input_arr[], unsigned input_begin, unsigned input_end,
              int output_arr[], unsigned output_begin)
{
    for (input_begin; input_begin != input_end; ++input_begin)
    {
        output_arr[output_begin++] = input_arr[input_begin];
    }

    return output_begin;
}

bool is_set(const int arr[], unsigned begin, unsigned end)
{
    if (end - begin < 2)
    {
        return true;
    }

    for (begin; begin != end - 1; ++begin)
    {
        if (arr[begin] >= arr[begin + 1])
        {
            return false;
        }
    }

    return true;
}

unsigned set_union(const int input_arr_1[], unsigned input_begin_1, unsigned input_end_1,
                   const int input_arr_2[], unsigned input_begin_2, unsigned input_end_2,
                   int output_arr[], unsigned output_begin)
{
    while(input_begin_1 != input_end_1)
    {
        if (input_begin_2 == input_end_2)
        {
            return copy(input_arr_1, input_begin_1, input_end_1,
                        output_arr, output_begin);
        }
        if (input_arr_1[input_begin_1] < input_arr_2[input_begin_2])
        {
            output_arr[output_begin++] = input_arr_1[input_begin_1++];
        }
        else if (input_arr_1[input_begin_1] > input_arr_1[input_begin_1])
        {
            output_arr[output_begin++] = input_arr_2[input_begin_2++];
        }
        else
        {
            ++input_begin_1;
        }
    }

    return copy(input_arr_2, input_begin_2, input_end_2,
                output_arr, output_begin);
}

unsigned set_intersection(const int input_arr_1[], unsigned input_begin_1, unsigned input_end_1,
                          const int input_arr_2[], unsigned input_begin_2, unsigned input_end_2,
                          int output_arr[], unsigned output_begin)
{
    while(input_begin_1 != input_end_1 && input_begin_2 != input_end_2)
    {
        if (input_arr_1[input_begin_1] < input_arr_2[input_begin_2])
        {
            ++input_begin_1;
        }
        else if (input_arr_1[input_begin_1] > input_arr_1[input_begin_1])
        {
            ++input_begin_2;
        }
        else
        {
            output_arr[output_begin++] = input_arr_1[input_begin_1++];
            ++input_begin_2;
        }
    }

    return output_begin;
}

unsigned set_difference(const int input_arr_1[], unsigned input_begin_1, unsigned input_end_1,
                        const int input_arr_2[], unsigned input_begin_2, unsigned input_end_2,
                        int output_arr[], unsigned output_begin)
{
    while(input_begin_1 != input_end_1)
    {
        if (input_begin_2 == input_end_2)
        {
            return copy(input_arr_1, input_begin_1, input_end_1,
                        output_arr, output_begin);
        }
        if (input_arr_1[input_begin_1] < input_arr_2[input_begin_2])
        {
            output_arr[output_begin++] = input_arr_1[input_begin_1++];
        }
        else if (input_arr_1[input_begin_1] > input_arr_1[input_begin_1])
        {
            ++input_begin_2;
        }
        else
        {
            ++input_begin_1;
            ++input_begin_2;
        }
    }

    return output_begin;
}

unsigned set_symmetric_difference(const int input_arr_1[], unsigned input_begin_1, unsigned input_end_1,
                                  const int input_arr_2[], unsigned input_begin_2, unsigned input_end_2,
                                  int output_arr[], unsigned output_begin)
{
    while(input_begin_1 != input_end_1)
    {
        if (input_begin_2 == input_end_2)
        {
            return copy(input_arr_1, input_begin_1, input_end_1,
                        output_arr, output_begin);
        }
        if (input_arr_1[input_begin_1] < input_arr_2[input_begin_2])
        {
            output_arr[output_begin++] = input_arr_1[input_begin_1++];
        }
        else if (input_arr_1[input_begin_1] > input_arr_1[input_begin_1])
        {
            output_arr[output_begin++] = input_arr_2[input_begin_2++];
        }
        else
        {
            ++input_begin_1;
            ++input_begin_2;
        }
    }

    return copy(input_arr_2, input_begin_2, input_end_2,
                output_arr, output_begin);
}

bool includes(const int arr_1[], unsigned begin_1, unsigned end_1,
              const int arr_2[], unsigned begin_2, unsigned end_2)
{
    while (begin_2 != end_2)
    {
        if (begin_1 == end_1 || arr_2[begin_2] < arr_1[begin_1])
        {
            return false;
        }

        if (arr_1[begin_1] == arr_2[begin_2])
        {
            ++begin_2;
        }

        ++begin_1;
    }
}


int main()
{
    int set_1[]{1,2,3};
    int set_2[]{2,3,4};
    int res[6]{};

    unsigned end{set_difference(set_1, 0, 3,
                                set_2, 0, 3,
                                res, 0)};

    print(res, 0, end);

    return 0;
}
