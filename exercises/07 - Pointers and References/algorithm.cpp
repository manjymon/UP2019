#include <iostream>

void swap(int& a, int& b)
{
    int c = a;
    a = b;
    b = c;
}

void iter_swap(int* a, int* b)
{
    swap(*a, *b);
}

void print(const int* begin, const int* end)
{
    for (; begin != end; ++begin)
    {
        std::cout << *begin << ' ';
    }

    std::cout << '\n';
}

void reverse(int* begin, int* end)
{
    for (; begin !=end && begin != --end; ++begin)
    {
        iter_swap(begin, end);
    }
}

int* copy(const int* input_begin, const int* input_end,
          int* output_begin)
{
    for (; input_begin != input_end; ++input_begin)
    {
        *(output_begin++) = *input_begin;
    }

    return output_begin;
}

int* rotate(int* begin, int* mid, int* end)
{
    reverse(begin, mid);
    reverse(mid, end);
    reverse(begin, end);

    return begin + (end - mid);
}

int* erase(int* begin, int* end, unsigned index)
{
    int* element_position = begin + index;
    return rotate(element_position, element_position + 1, end);
}

int* insert(int* begin, int* end, unsigned index, int element)
{
    int* element_position = begin + index;

    *end = element;
    rotate(element_position, end, end + 1);

    return end + 1;
}

const int* find(const int* begin, const int* end, int element)
{
    for (; begin != end; ++begin)
    {
        if (*begin == element)
        {
            return begin;
        }
    }

    return begin;
}

int* find(int* begin, int* end, int element)
{
    for (; begin != end; ++begin)
    {
        if (*begin == element)
        {
            return begin;
        }
    }

    return begin;
}

bool contains(const int* begin, const int* end, int element)
{
    return find(begin, end, element) != end;
}

int inner_product(const int* begin_1, const int* end_1,
                  const int* begin_2)
{
    int result{0};

    for (; begin_1 != end_1; ++begin_1, ++begin_2)
    {
        result += *begin_1 * *begin_2;
    }

    return result;
}

int* partial_sum(const int* input_begin, const int* input_end,
                 int* output_begin)
{
    int sum{0};

    for(; input_begin != input_end; ++input_begin)
    {
        *(output_begin++) = sum += *input_begin;
    }

    return output_begin;
}

int* adjacent_difference(const int* input_begin, const int* input_end,
                         int* output_begin)
{
    int last{0};

    for(; input_begin != input_end; ++input_begin)
    {
        int current = *input_begin;
        *(output_begin++) = current - last;
        last = current;
    }

    return output_begin;
}

const int* min_element(const int* begin, const int* end)
{
    const int* min_element{begin};
    int minimum(*begin);

    for (; begin != end; ++begin)
    {
        if (*begin < minimum)
        {
            minimum = *begin;
            min_element = begin;
        }
    }

    return min_element;
}

int* min_element(int* begin, int* end)
{
    int* min_element{begin};
    int minimum(*begin);

    for (; begin != end; ++begin)
    {
        if (*begin < minimum)
        {
            minimum = *begin;
            min_element = begin;
        }
    }

    return min_element;
}

void selection_sort(int* begin, int* end)
{
    for (; begin != end; ++begin)
    {
        iter_swap(begin, min_element(begin, end));
    }
}

int* merge(const int* input_begin_1, const int* input_end_1,
           const int* input_begin_2, const int* input_end_2,
           int* output_begin)
{
    while (input_begin_1 != input_end_1 && input_begin_2 != input_end_2)
    {
        if (*input_begin_1 <= *input_begin_2)
        {
            *(output_begin++) = *(input_begin_1++);
        }
        else
        {
            *(output_begin++) = *(input_begin_2++);
        }
    }

    output_begin = copy(input_begin_1, input_end_1, output_begin);
    return copy(input_begin_2, input_end_2, output_begin);
}

const int* upper_bound(const int* begin, const int* end, int element)
{
    while (begin < end)
    {
        const int* mid{begin + (end - begin) / 2};

        if (element >= *mid)
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

int* upper_bound(int* begin, int* end, int element)
{
    while (begin < end)
    {
        int* mid{begin + (end - begin) / 2};

        if (element >= *mid)
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

bool binary_search(const int* begin, const int* end, int element)
{
    const int* greater = upper_bound(begin, end, element);
    return greater != begin && *(greater - 1) == element;
}

void insertion_sort(int* begin, int* end)
{
    for (int* i = begin; i != end; ++i)
    {
        rotate(upper_bound(begin, i, *i), i, i + 1);
    }
}

int main()
{
    int arr[]{ 1, 2, 3, 4, 5 };

    std::cout << "arr without first element: ";
    print(arr + 1, std::end(arr));

    reverse(arr, std::end(arr));

    std::cout << "reversed arr: ";
    print(arr, std::end(arr));

    int copied_arr[100]{};
    int* copy_end = copy(arr + 1, std::end(arr),
                         copied_arr);

    std::cout << "copy reversed arr without first element: ";
    print(copied_arr, copy_end);

    std::cout << "arr: ";
    print(arr, std::end(arr));

    rotate(arr, arr + 2, std::end(arr));

    std::cout << "rotate around 2nd: ";
    print(arr, std::end(arr));

    std::cout << "copied arr: ";
    print(copied_arr, copy_end);

    copy_end = erase(copied_arr, copy_end, 2);

    std::cout << "remove the 2nd element: ";
    print(copied_arr, copy_end);

    copy_end = insert(copied_arr, copy_end, 2, 22);

    std::cout << "add a 22 at the 2nd position: ";
    print(copied_arr, copy_end);

    std::cout << "Has 2: " << std::boolalpha << contains(copied_arr, copy_end, 2) << '\n';
    std::cout << "Has 22: " << std::boolalpha << contains(copied_arr, copy_end, 22) << "\n\n";

    int ipa_1[]{ 0, 1, 2, 3, 4 };
    int ipa_2[]{ 5, 4, 2, 3, 1 };

    std::cout << "inner product of: ";
    print(ipa_1, ipa_1 + 5);
    std::cout << "and: ";
    print(ipa_2, ipa_2 + 5);
    std::cout << "is: ";
    std::cout << inner_product(ipa_1, ipa_1 + 5,
                               ipa_2) << "\n\n";

    int sequence[]{ 1, 2, 3, 4 };

    std::cout << "sequence: ";
    print(sequence, sequence + 4);

    partial_sum(sequence, sequence + 4,
                sequence);

    std::cout << "partial sums: ";
    print(sequence, sequence + 4);

    adjacent_difference(sequence, sequence + 4,
                        sequence);

    std::cout << "adjacent difference: ";
    print(sequence, sequence + 4);

    std::cout << "min in sequence: " << *min_element(sequence, sequence + 4) << "\n\n";

    int sort_example_arr[]{ 1, 3, 4, 6, 2, 9, 0, 8, 7, 5 };

    std::cout << "unsorted arr: ";
    print(sort_example_arr, std::end(sort_example_arr));

    selection_sort(sort_example_arr, std::end(sort_example_arr));

    std::cout << "sorted arr: ";
    print(sort_example_arr, std::end(sort_example_arr));

    const int mergable_1[]{ 1, 3, 5 };
    const int mergable_2[]{ 2, 6 };
    int merged[10]{};

    int* merged_end = merge(mergable_1, std::end(mergable_1),
                            mergable_2, std::end(mergable_2),
                            merged);

    std::cout << "\nmergable 1: ";
    print(mergable_1, std::end(mergable_1));
    std::cout << "mergable 2: ";
    print(mergable_2, std::end(mergable_2));
    std::cout << "merged: ";
    print(merged, merged_end);

    std::cout << "first element bigger than 4 -> " << *upper_bound(merged, merged_end, 4) << '\n';

    std::cout << "Has 0: " << binary_search(merged, merged_end, 0) << '\n';
    std::cout << "Has 3: " << binary_search(merged, merged_end, 3) << "\n\n";

    int another_sort_example_arr[]{ 1, 3, 4, 6, 2, 9, 0, 8, 7, 5 };

    std::cout << "unsorted arr: ";
    print(another_sort_example_arr, std::end(another_sort_example_arr));

    insertion_sort(another_sort_example_arr, std::end(another_sort_example_arr));

    std::cout << "insertion sorted arr: ";
    print(another_sort_example_arr, std::end(another_sort_example_arr));

    return 0;
}
