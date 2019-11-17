#include <iostream>

bool is_lower_case(char c)
{
    return c >= 'a' && c <= 'z';
}

bool is_upper_case(char c)
{
    return c >= 'A' && c <= 'Z';
}

bool lower_to_upper_char_cmp(char lower, char upper)
{
    return lower == upper - 'A' + 'a';
}

void separate_string(const char input[], char lower_output[], char upper_output[])
{
    unsigned lower_it{0};
    unsigned upper_it{0};

    for (unsigned input_it = 0; input[input_it]; ++input_it)
    {
        if (is_lower_case(input[input_it]))
        {
            lower_output[lower_it++] = input[input_it];
        }
        if (is_upper_case(input[input_it]))
        {
            upper_output[upper_it++] = input[input_it];
        }
    }

    lower_output[lower_it] = upper_output[upper_it] = '\0';
}

bool lower_to_upper_str_cmp(const char lower[], const char upper[])
{
    unsigned i{0};
    for (; lower[i] && upper[i]; ++i)
    {
        if (!lower_to_upper_char_cmp(lower[i], upper[i]))
        {
            return false;
        }
    }

    return lower[i] == upper[i];
}

int main()
{
    char input[256];
    char lower_case_input[256];
    char upper_case_input[256];

    std::cin.getline(input, 255);
    separate_string(input, lower_case_input, upper_case_input);

    std::cout << (lower_to_upper_str_cmp(lower_case_input, upper_case_input) ? "Yes" : "No") << '\n';
    return 0;
}
