#include <fstream>
#include <iostream>

const size_t max_size{100};

size_t word_count(const char * file_name)
{
    std::ifstream in{file_name};
    size_t count{0};
    char word[max_size]{};

    while (in >> word)
    {
        ++count;
    }

    return count;
}

int main()
{
    std::cout << word_count("words.txt");

    return 0;
}
