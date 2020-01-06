#include <fstream>
#include <iostream>

using std::ios;

std::streamoff get_size(std::istream& in)
{
    in.seekg(0, ios::end);
    std::streamoff size{in.tellg() / sizeof(int32_t)};

    in.seekg(0);
    return size;
}

int32_t read_int(std::istream& in)
{
    int32_t result{};
    in.read(reinterpret_cast<char*>(&result), sizeof(int32_t));
    return result;
}

int32_t read_at(std::istream& in, unsigned pos)
{
    in.seekg(pos * sizeof(int32_t));
    return read_int(in);
}

void write_int(std::ostream& out, int32_t number)
{
    out.write(reinterpret_cast<const char*>(&number), sizeof(int32_t));
}

void write_at(std::ostream& out, unsigned pos, int32_t number)
{
    out.seekp(pos * sizeof(int32_t));
    write_int(out, number);
}

void write_ints(const char * name, const int32_t * begin, const int32_t * end)
{
    std::ofstream out{name, ios::binary};

    for (; begin != end; ++begin)
    {
        write_int(out, *begin);
    }
}

void read_ints(const char * name, std::ostream& out)
{
    std::ifstream in{name, ios::binary};
    std::streamoff size{get_size(in)};

    for (std::streamoff i{0}; i < size; ++i)
    {
        out << read_int(in) << ' ';
    }
}

void copy(std::istream& in, unsigned pos, std::ostream& out)
{
    in.seekg(pos * sizeof(int32_t));
    int32_t buffer{};
    while (in.read(reinterpret_cast<char *>(&buffer), sizeof(int32_t)))
    {
        out.write(reinterpret_cast<const char *>(&buffer), sizeof(int32_t));
    }
    // out << in.rdbuf();
}

void merge(const char * input_name_1, const char * input_name_2, const char * output_name)
{
    std::ifstream in[2]{};
    in[0].open(input_name_1, ios::binary);
    in[1].open(input_name_2, ios::binary);

    std::ofstream out{output_name, ios::binary};

    std::streamoff sizes[2]{get_size(in[0]), get_size(in[1])};
    std::streamoff counters[2]{};
    while (counters[0] < sizes[0] && counters[1] < sizes[1])
    {
        int32_t numbers[2]{
            read_at(in[0], counters[0]),
            read_at(in[1], counters[1])
        };

        if (numbers[0] <= numbers[1])
        {
            ++counters[0];
            write_int(out, numbers[0]);
        }
        else
        {
            ++counters[1];
            write_int(out, numbers[1]);
        }
    }

    for (unsigned i{0}; i < 2; ++i)
    {
        if (counters[i] < sizes[i])
        {
            copy(in[i], counters[i], out);
        }
    }
}

int main()
{
    int32_t ints1[]{1, 3, 5};
    int32_t ints2[]{4, 6, 8, 10, 20};
    write_ints("ints1.bin", std::begin(ints1), std::end(ints1));
    write_ints("ints2.bin", std::begin(ints2), std::end(ints2));
    merge("ints1.bin", "ints2.bin", "merged.bin");
    read_ints("merged.bin", std::cout);
    return 0;
}
