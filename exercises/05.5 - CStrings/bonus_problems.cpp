#include <iostream>

unsigned find(const char arr[], unsigned begin, unsigned end, char element)
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

void reverse(char arr[], unsigned begin, unsigned end)
{
    for (; begin != end && begin != --end; ++begin)
    {
        std::swap(arr[begin], arr[end]);
    }
}

char * reverse_words(char sentence[])
{
    unsigned begin{0};
    unsigned end = strlen(sentence);

    while (begin < end)
    {
        unsigned next_space{find(sentence, begin, end, ' ')};
        reverse(sentence, begin, next_space);
        begin = next_space + 1;
    }
    
    return sentence;
}

int atoi(char integer[])
{
    unsigned i{0};
    int number{0};
    int sign{1};
    if (integer[i] == '-')
    {
        sign = -1;
        i++;
    }
    while (integer[i] >= '0' && integer[i] <= '9')
    {
        number = number * 10 + integer[i];
    }
    
    return number * sign;
}

char * run_length_decode(char dest[], const char src[])
{
    unsigned count{1};
    unsigned dest_i{0};
    for (unsigned src_i = 0; src[src_i]; ++src_i)
    {
        if (src[src_i] >= 'a' && src[src_i] <= 'z')
        {
            for (unsigned j = 0; j < count; j++)
            {
                dest[dest_i++] = src[src_i];
            }
            count = 1;
        }
        else if (count == 1)
        {
            count = atoi(src + src_i);
        }
    }
    
    dest[dest_i] = '\0';
    
    return dest;
}

int main()
{
    char sentence[100]{"Turn that frown upside down :("};
    std::cout << reverse_words(sentence) << '\n';
    
    std::cout << atoi("123filler") + atoi("-81morefiller") << '\n';

    char buffer[100]{};
    std::cout << run_length_decode(buffer, "a2b10c") << '\n';

    return 0;
}
