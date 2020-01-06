#include <fstream>
#include <iostream>

using std::ios;

char capitalize(char a)
{
    return a >= 'a' && a <= 'z' ? a + 'A' - 'a' : a;
}

void capitalize_words(const char * file_name)
{
    std::fstream file{file_name};

    while (file)
    {
        char c{};
        std::streampos pos{file.tellg()};
        file.get(c);
        file.seekg(-1, ios::cur);
        file.put(capitalize(c));
    }
}

int main()
{
    capitalize_words("capital.txt");
    return 0;
}