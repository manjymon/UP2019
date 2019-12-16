#include <algorithm>
#include <iostream>

const unsigned max_size = 20;

int water_jugs(unsigned curr_1, unsigned max_1, unsigned curr_2, unsigned max_2, unsigned target, bool visited[max_size][max_size])
{
    if (curr_1 == target || curr_2 == target)
    {
        return 0;
    }

    if (visited[curr_1][curr_2] == true)
    {
        return 441;
    }
    
    visited[curr_1][curr_2] = true;
    
    int results[6]{0};

    results[0] = water_jugs(0     , max_1, curr_2, max_2, target, visited) + 1; // Empty 1
    results[1] = water_jugs(curr_1, max_1, 0     , max_2, target, visited) + 1; // Empty 2
    results[2] = water_jugs(max_1 , max_1, curr_2, max_2, target, visited) + 1; // Fill 1
    results[3] = water_jugs(curr_1, max_1, max_2 , max_2, target, visited) + 1; // Fill 2
    
    int move = std::min(max_2 - curr_2, curr_1);
    results[4] = water_jugs(curr_1 - move, max_1, curr_2 + move, max_2, target, visited) + 1; // Move from 1 to 2

    move = std::min(max_1 - curr_1, curr_2);
    results[5] = water_jugs(curr_1 + move, max_1, curr_2 - move, max_2, target, visited) + 1; /// Move from 2 to 1

    visited[curr_1][curr_2] = false;
    return *std::min_element(std::begin(results), std::end(results));
}

int water_jugs(unsigned max_1, unsigned max_2, unsigned target)
{
    bool visited[max_size][max_size]{false};
    return water_jugs(0, max_1, 0, max_2, target, visited);
}

int main()
{
    std::cout << water_jugs(4, 3, 2) << '\n';

    return 0;
}
