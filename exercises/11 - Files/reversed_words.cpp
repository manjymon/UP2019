#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>

const size_t max_size{100};

void reverse_words(const char * name)
{
    std::fstream file{name};
    while (file)
    {
        char word[max_size];
        long long pos{file.tellg()};

        file >> word;
        bool last{file.eof()};

        std::reverse(word, word + strlen(word));

        file.seekg(pos);
        file << word;

        if (last)
        {
            return;
        }
        else
        {
            file << ' ';
        }
    }
}

int main()
{
    reverse_words("reversed_words.txt");
    return 0;
}
