#include <cstring>
#include <iostream>

// Returning owning pointers to the heap is no bueno
const char * copy_string(const char * str)
{
    char * result = new char [strlen(str) + 1];

    strcpy(result, str);

    return result;
}

int main()
{
    char name1[10]{"Go6o"};
    const char * name2{copy_string(name1)};

    std::cout << name1 << ' ' << name2 << '\n';

    strcpy(name1, "Pe6o");

    std::cout << name1 << ' ' << name2 << '\n';

    delete [] name2;

    return 0;
}
