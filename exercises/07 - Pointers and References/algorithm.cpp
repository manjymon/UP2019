#include <iostream>
#include "algorithm.h"

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
