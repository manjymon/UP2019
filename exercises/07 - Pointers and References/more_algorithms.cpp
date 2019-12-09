#include <iostream>
#include "more_algorithms.h"

int main()
{
    const int arr2[]{0, 1, 2, 1, 2};
    const int seq2[]{1, 2};
    const int* s_begin2 = search(std::begin(arr2), std::end(arr2),
                                 std::begin(seq2), std::end(seq2));
    const int result2[]{1, 2, 1, 2};

    std::cout << "Search Test: " << std::boolalpha << equal(s_begin2, std::end(arr2),
                                                            std::begin(result2), std::end(result2)) << '\n';

    const int arr3[]{0, 1, 1, 2, 1, 1, 1};
    const int * s_begin3 = search_n(std::begin(arr3), std::end(arr3), 3, 1);
    const int result3[]{1, 1, 1};

    std::cout << "Search_n Test: " << std::boolalpha << equal(s_begin3, s_begin3 + 3,
                                                              std::begin(result3), std::end(result3)) << '\n';

    const int arr4[]{0, 1, 2, 1, 1, 2, 2};
    const int* adj_begin4 = adjacent_find(std::begin(arr4), std::end(arr4));
    const int result4[]{1, 1};

    std::cout << "Adjacent Find Test: " << std::boolalpha << equal(adj_begin4, adj_begin4 + 2,
                                                                   std::begin(result4), std::end(result4)) << '\n';

    const int arr5[]{0, 1, 2, 1, 2};
    const int seq5[]{1, 2};
    const int* s_begin5 = find_end(std::begin(arr5), std::end(arr5),
                                   std::begin(seq5), std::end(seq5));
    const int result5[]{1, 2};

    std::cout << "Find End Test: " << std::boolalpha << equal(s_begin5, std::end(arr5),
                                                              std::begin(result5), std::end(result5)) << '\n';

    const int arr6[]{0, 1, 2, 3, 4};
    const int seq6[]{2, 4};
    const int* found6 = find_first_of(std::begin(arr6), std::end(arr6),
                                      std::begin(seq6), std::end(seq6));

    std::cout << "Find First Of Test: " << std::boolalpha << (*found6 == 2) << '\n';

    int arr7A[]{1, 3, 5};
    int arr7B[]{2, 4, 6};
    swap_ranges(std::begin(arr7A), std::end(arr7A),
                std::begin(arr7B));
    const int result7A[]{2, 4, 6};
    const int result7B[]{1, 3, 5};

    std::cout << "Swap Ranges Test: " << std::boolalpha <<
        (equal(std::begin(arr7A), std::end(arr7A),
               std::begin(result7A), std::end(result7A)) &&
         equal(std::begin(arr7B), std::end(arr7B),
               std::begin(result7B), std::end(result7B))) << '\n';

    const int arr8[]{1, 2, 3};
    int backward_copy8[3]{};
    copy_backward(std::begin(arr8), std::end(arr8),
                  std::begin(backward_copy8));
    const int result8[]{3, 2, 1};

    std::cout << "Backward Copy Test: " << std::boolalpha << equal(std::begin(backward_copy8), std::end(backward_copy8),
                                                                   std::begin(result8), std::end(result8)) << '\n';

    int arr9[]{0, 1, 2, 1, 4, 1, 6};
    int* new_end9 = remove(std::begin(arr9), std::end(arr9), 1);
    const int result9[]{0, 2, 4, 6};

    std::cout << "Remove Test: " << std::boolalpha << equal(std::begin(arr9), new_end9,
                                                            std::begin(result9), std::end(result9)) << '\n';

    int arr10[]{0, 9, 2, 9, 3, 9};
    replace(std::begin(arr10), std::end(arr10), 9, 1);
    const int result10[]{0, 1, 2, 1, 3, 1};

    std::cout << "Replace Test: " << std::boolalpha << equal(std::begin(arr10), std::end(arr10),
                                                             std::begin(result10), std::end(result10)) << '\n';

    return 0;
}
