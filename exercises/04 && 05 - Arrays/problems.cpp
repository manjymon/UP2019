#include <iostream>

void print(const int arr[], unsigned begin, unsigned end)
{
    for (; begin != end; ++begin)
    {
        std::cout << arr[begin] << ' ';
    }
    std::cout << '\n';
}

void reverse(int arr[], unsigned begin, unsigned end)
{
    for (; begin != end && begin != --end; ++begin)
    {
        std::swap(arr[begin], arr[end]);
    }
}

unsigned copy(const int input_arr[], unsigned input_begin, unsigned input_end,
              int output_arr[], unsigned output_begin)
{
    for (; input_begin != input_end; ++input_begin)
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
    for (; begin != end; ++begin)
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
    for (; begin_1 != end_1; ++begin_1, ++begin_2)
    {
        result += input_arr_1[begin_1] * input_arr_2[begin_2];
    }
    return result;
}

unsigned partial_sum(const int input_arr[], unsigned input_begin, unsigned input_end,
                     int output_arr[], unsigned output_begin)
{
    int sum{0};
    for(; input_begin != input_end; ++input_begin)
    {
        output_arr[output_begin++] = sum += input_arr[input_begin];
    }
    return output_begin;
}

unsigned adjacent_difference(const int input_arr[], unsigned input_begin, unsigned input_end,
                             int output_arr[], unsigned output_begin)
{
    int last{0};
    for(; input_begin != input_end; ++input_begin)
    {
        int current{input_arr[input_begin]};
        output_arr[output_begin++] = current - last;
        last = current;
    }
    return output_begin;
}

unsigned min_element(const int arr[], unsigned begin, unsigned end)
{
    unsigned min_element{begin};
    int minimum{arr[min_element]};

    for(; begin != end; ++begin)
    {
        if (arr[begin] < minimum)
        {
            minimum = arr[begin];
            min_element = begin;
        }
    }

    return min_element;
}

void selection_sort(int arr[], unsigned begin, unsigned end)
{
    for (; begin != end; begin++)
    {
        std::swap(arr[begin], arr[min_element(arr, begin, end)]);
    }
}

unsigned merge(const int input_1[], unsigned begin_1, unsigned end_1,
               const int input_2[], unsigned begin_2, unsigned end_2,
               int output[], unsigned output_begin)
{
    while(begin_1 != end_1 && begin_2 != end_2)
    {
        if (input_1[begin_1] <= input_2[begin_2])
        {
            output[output_begin++] = input_1[begin_1++];
        }
        else
        {
            output[output_begin++] = input_2[begin_2++];
        }
    }

    copy(input_1, begin_1, end_1, output, output_begin);
    return copy(input_2, begin_2, end_2,
                output, output_begin);
}

unsigned upper_bound(const int arr[], unsigned begin, unsigned end, int element)
{
    while (begin < end)
    {
        unsigned mid{(begin + end) / 2};

        if (element >= arr[mid])
        {
            begin = mid + 1;
        }
        else
        {
            end = mid;
        }
    }

    return begin;
}

bool binary_search(const int arr[], unsigned begin, unsigned end, int element)
{
    unsigned greater = upper_bound(arr, begin, end, element);
    return greater != begin && arr[greater - 1] == element;
}

void insertion_sort(int arr[], unsigned begin, unsigned end)
{
    for(unsigned i = begin; i != end; ++i)
    {
        rotate(arr, upper_bound(arr, begin, i, arr[i]), i, i + 1);
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

    std::cout << "sequence: ";
    print(sequence, 0, 4);

    partial_sum(sequence, 0, 4,
                sequence, 0);

    std::cout << "partial sums: ";
    print(sequence, 0, 4);

    adjacent_difference(sequence, 0, 4,
                        sequence, 0);

    std::cout << "adjacent difference: ";
    print(sequence, 0, 4);

    std::cout << "min in sequence: " << sequence[min_element(sequence, 0, 4)] << "\n\n";

    const int sort_example_size = 10;
    int sort_example_arr[]{ 1, 3, 4, 6, 2, 9, 0, 8, 7, 5 };

    std::cout << "unsorted arr: ";
    print(sort_example_arr, 0, sort_example_size);

    selection_sort(sort_example_arr, 0, sort_example_size);

    std::cout << "sorted arr: ";
    print(sort_example_arr, 0, sort_example_size);

    const int mergable_1_size = 3;
    const int mergable_2_size = 2;
    const int merged_size = mergable_1_size + mergable_2_size;

    const int mergable_1[mergable_1_size]{ 1, 3, 5 };
    const int mergable_2[mergable_2_size]{ 2, 6 };
    int merged[merged_size]{};

    merge(mergable_1, 0, mergable_1_size,
          mergable_2, 0, mergable_2_size,
          merged, 0);

    std::cout << "\nmergable 1: ";
    print(mergable_1, 0, mergable_1_size);
    std::cout << "mergable 2: ";
    print(mergable_2, 0, mergable_2_size);
    std::cout << "merged: ";
    print(merged, 0, merged_size);

    std::cout << "first element bigger than 4 -> " << merged[upper_bound(merged, 0, merged_size, 4)] << '\n';

    std::cout << "Has 0: " << binary_search(merged, 0, merged_size, 0) << '\n';
    std::cout << "Has 3: " << binary_search(merged, 0, merged_size, 3) << "\n\n";

    const int another_sort_example_size = 10;
    int another_sort_example_arr[another_sort_example_size]{ 1, 3, 4, 6, 2, 9, 0, 8, 7, 5 };

    std::cout << "unsorted arr: ";
    print(another_sort_example_arr, 0, another_sort_example_size);

    insertion_sort(another_sort_example_arr, 0, another_sort_example_size);

    std::cout << "insertion sorted arr: ";
    print(another_sort_example_arr, 0, another_sort_example_size);

    return 0;
}
