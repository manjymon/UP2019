# Test Prep 2

```c++
const unsigned max_size = 100;
```

## 01 - Reversed Prefix

```c++
bool reversed_prefix(const char * word, const char * candidate)
```

Given 2 strings, check if reversing the second one will turn it into a prefix of the first one.

### Example

```c++
std::cout << std::boolalpha << reversed_prefix("abcdef", "cba") << '\n' // true
                            << reversed_prefix("abcdef", "abc");        // flase;
```

## 02 - Cyclical Palindrome

```c++
int cyclical_palindrome(const char* word)
```

Let's define a cyclical palindrome as a word that you can start reading from some posistion and circle back to the beginning of the word when you reach the end to get a palindrome. Write a function that returns that position or -1 if there isn't one.

### Example

```c++
std::cout << cyclical_palindrome("obi4amma4ibozaaz"); // -> 6
/*
    If you start reading from the 6th index you get
    az (end of the word, so we go back)
    obi4amma4iboza (rest of the world)
*/
```

## 03 - Valid Directions

```c++
bool valid_directions(const bool lab[max_size][max_size], unsigned height, unsigned width,
                      const char * directions)
```

You are given a matrix that represents a labyrinth, the value of each cell represents whether you could pass throught it or not. Check if a given series of directions (a string containing the characters W, E, S, N, that represent the 4 directions) is a valid path from any cell in the labyrinth to the bottom right corner.

### Example

```c++
const bool lab[max_size][max_size]{
    {1, 1, 1},
    {1, 1, 0},
    {1, 1, 1}
};
​
std::cout << std::boolalpha << valid_directions(lab, 3, 3, "SS") << '\n'     // false, you cannot go through 0s
                            << valid_directions(lab, 3, 3, "ESSW") << '\n'   // false, you cannot leave the lab
                            << valid_directions(lab, 3, 3, "WSSE") << '\n';  // true, start from [0, 2]
```

## 04 - Count Equal Rows / Columns

```c++
unsigned count_equal_rows_and_columns(const int matrix[max_size][max_size], unsigned size)
```

Given a square matrix, count the indexes i, such that the ith column is equal to the ith row.

### Example

```c++
const int matrix[max_size][max_size]{
    {1, 1, 0, 1},
    {1, 0, 1, 1},
    {0, 1, 1, 0},
    {1, 1, 1, 1}
};
​
std::cout << count_equal_rows_and_columns(matrix, 4) << '\n'; // 2, the indices are 0 and 1
```

## 05 - Alphacount

```c++
void alpha_count(const char* str)
```

Given a string output the number of occurences for every English letter. Treat lower and uppercase letters as the same. Do not output anything for letters that did not appear.

### Example

```c++
alpha_count("aBAbccD!Z");
/*
    a: 2
    b: 2
    c: 2
    d: 1
    z: 1
*/
```

## 06 - Logical Programming

Given a max_size X 2 table of strings where the first column represents a name of a person and the second - name of the parent, define the following 2 functions

```c++
const char* parent(const char* child, const char * const knowledge_base[max_size][2], unsigned size)
```
Given the name of a child and a table with names, return the name of his parent or "" if there isn't information about that.

```c++
bool inheritor(const char* predecessor, const char* ancestor,
               const char * const knowledge_base[max_size][2], unsigned size)
```

Given the name of 2 people, check if the second person is an ancestor of the first.

### Example

```c++
const char* kb[max_size][2]{
    {"Go6o", "Stavri"},
    {"Stavri", "Stamat"},
    {"Spartak", "Stamat"},
    {"Pe6o", "Go6o"}
};
​
std::cout << parent("Pe6o", kb, 4) << '\n'     // Go6o
          << parent("Stamat", kb, 4) << '\n';  // "", No info about Stamat's father
​
std::cout << std::boolalpha << inheritor("Pe6o", "Stamat", kb, 4) << '\n'   // true, Pe6o -> Go6o -> Stavri -> Stamat
                            << inheritor("Pe6o", "Spartak", kb, 4) << '\n'; // false
```

## 07 - Word Puzzle

```c++
bool can_read_word(const char table[max_size][max_size], unsigned size,
                   const char* word)
```

Given a matrix of characters and a word, check if you can form the word by starting at any point in the matrix and only reading diagonally.

### Example

```c++
const char table[max_size][max_size]{
    {'a', 'p', 'p', 'd'},
    {'k', 'a', 'x', 'p'},
    {'c', 'a', 'a', 'p'},
    {'a', 'k', 'e', 'r'},
};
​
std::cout << std::boolalpha << can_read_word(table, 4, "kappa") << '\n'; // true, start at [3,1] and go up-right, up-right, up-left, down-left
```
