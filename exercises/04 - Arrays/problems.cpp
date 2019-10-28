#include <iostream>

void print(const int arr[], unsigned begin, unsigned end)
{
    for (begin; begin != end; ++begin)
    {
        std::cout << arr[begin] << ' ';
    }
    std::cout << '\n';
}

void reverse(int arr[], unsigned begin, unsigned end)
{
    for (begin, end; begin != end && begin != --end; ++begin)
    {
        std::swap(arr[begin], arr[end]);
    }
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

unsigned rotate(int arr[], unsigned begin, unsigned mid, unsigned end)
{
    reverse(arr, begin, mid);
    reverse(arr, mid, end);
    reverse(arr, begin, end);

    return begin + end - mid;
}

unsigned erase(int arr[], unsigned size, unsigned index)
{
    return rotate(arr, index, index + 1, size); 
}

unsigned insert(int arr[], unsigned size, unsigned index, int element)
{
    arr[size] = element;
    rotate(arr, index, size, size + 1);
    return size + 1;
}

unsigned find(const int arr[], unsigned begin, unsigned end, int element)
{
    for (begin; begin != end; ++begin)
    {
        if (arr[begin] == element)
        {
            return begin;
        }
    }

    return begin;
}

bool contains(const int arr[], unsigned begin, unsigned end, int element)
{
    return find(arr, begin, end, element) != end;
}

int inner_product(const int input_arr_1[], unsigned begin_1, unsigned end_1,
                  const int input_arr_2[], unsigned begin_2)
{
    int result{0};
    for (begin_1; begin_1 != end_1; ++begin_1, ++begin_2)
    {
        result += input_arr_1[begin_1] * input_arr_2[begin_2];
    }
    return result;
}

unsigned min_index(const int arr[], unsigned begin, unsigned end)
{
    unsigned min_index{begin};
    int minimum{arr[min_index]};

    for(begin; begin != end; ++begin)
    {
        if (arr[begin] < minimum)
        {
            minimum = arr[begin];
            min_index = begin;
        }
    }

    return min_index;
}

void selection_sort(int arr[], unsigned begin, unsigned end)
{
    for (begin; begin != end; begin++)
    {
        std::swap(arr[begin], arr[min_index(arr, begin, end)]);
    }
}

int main()
{
    const unsigned arr_size = 5;
    int arr[]{ 1, 2, 3, 4, 5 };

    std::cout << "arr without first element: ";
    print(arr, 1, arr_size);

    reverse(arr, 0, arr_size);

    std::cout << "reversed arr: ";
    print(arr, 0, arr_size);

    int copied_arr[100]{};
    unsigned copy_size = copy(arr, 1, arr_size,
                              copied_arr, 0);

    std::cout << "copy reversed arr without first element: ";
    print(copied_arr, 0, copy_size);

    std::cout << "arr: ";
    print(arr, 0, arr_size);

    rotate(arr, 0, 2, arr_size);

    std::cout << "rotate around 2nd: ";
    print(arr, 0, arr_size);

    std::cout << "copied arr: ";
    print(copied_arr, 0, copy_size);

    copy_size = erase(copied_arr, copy_size, 2);

    std::cout << "remove the 2nd element: ";
    print(copied_arr, 0, copy_size);

    copy_size = insert(copied_arr, copy_size, 2, 22);

    std::cout << "add a 22 at the 2nd position: ";
    print(copied_arr, 0, copy_size);

    std::cout << "Has 2: " << std::boolalpha << contains(copied_arr, 0, copy_size, 2) << '\n';
    std::cout << "Has 22: " << std::boolalpha << contains(copied_arr, 0, copy_size, 22) << "\n\n";

    int ipa_1[]{ 0, 1, 2, 3, 4 };
    int ipa_2[]{ 5, 4, 2, 3, 1 };

    std::cout << "inner product of: ";
    print(ipa_1, 0, 5);
    std::cout << "and: ";
    print(ipa_2, 0, 5);
    std::cout << "is: ";
    std::cout << inner_product(ipa_1, 0, 5,
                               ipa_2, 0) << "\n\n";

    int sequence[]{ 1, 2, 3, 4 };

    std::cout << "min in sequence: " << sequence[min_index(sequence, 0, 4)] << "\n\n";

    const int sort_example_size = 10;
    int sort_example_arr[]{ 1, 3, 4, 6, 2, 9, 0, 8, 7, 5 };

    std::cout << "unsorted arr: ";
    print(sort_example_arr, 0, sort_example_size);

    selection_sort(sort_example_arr, 0, sort_example_size);

    std::cout << "sorted arr: ";
    print(sort_example_arr, 0, sort_example_size);

    return 0;
}
