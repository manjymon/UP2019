#include <iostream>
#include <fstream>

const unsigned max_size{100};

void write_to_file(const char * sentences[], unsigned size, const char * file_name)
{
    std::ofstream out{file_name};
    for (unsigned i{0}; i < size; ++i)
    {
        out << sentences[i] << '\n';
    }
}

void read_from_file(const char * file_name)
{
    std::ifstream in{file_name};
    char symbol{};

    while (in.get(symbol))
    {
        std::cout << symbol;
    }
}

bool is_letter(char c)
{
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

// Strings are made of letters and numbers
// Replace n consecutive appearences of a letter a with "na"
// e.g. "aaabbc" -> "3a2bc" 
void run_length_encode(const char * decoded_name, const char * encoded_name)
{
    std::ifstream decoded{decoded_name};
    std::ofstream encoded{encoded_name};
    char letter{};

    while (decoded.get(letter))
    {
        unsigned count{1};
        while (decoded.peek() == letter)
        {
            decoded.get();
            ++count;
        }

        if (count > 1)
        {
            encoded << count;
        }
        encoded.put(letter);
    }
}

// Decode the above
void run_length_decode(const char * encoded_name, const char * decoded_name)
{
    std::ifstream encoded{encoded_name};
    std::ofstream decoded{decoded_name};
    char letter{};

    while (!encoded.eof())
    {
        char letter = encoded.peek();
        if (is_letter(letter))
        {
            encoded.get(letter);
            decoded.put(letter);
        }
        else
        {
            unsigned count{};
            encoded >> count;
            encoded.get(letter);
            for (unsigned i{0}; i < count; ++i)
            {
                decoded.put(letter);
            }
        }
    }
}

int main()
{
    const char * sentences[]{
        "sent 1",
        "sent 2",
        "3rd sentence",
        "etc"
    };

    write_to_file(sentences, 4, "sentences.txt");

    read_from_file("sentences.txt");

    run_length_decode("run_length_encoded.txt", "run_length_decoded.txt");
    run_length_encode("run_length_decoded.txt", "run_length_encoded_2.txt");

    return 0;
}
