# Ex05.05 - C-Strings

An array of characters ending with a null terminator ('\0')

## Differences with regular arrays

- No need to pass an end / size to use them. Just look for the null terminator.

```c++
char word[]{"kappa"};
std::cout << sizeof(word); // 6: 5 letters + \0
```

- Overloaded operator<<

```c++
int arr[] = {1, 2, 3};
std::cout << arr; // arr decays to a pointer and this prints the adress of the first element

char word[]{"kappa"};
std::cout << word; // Prints: kappa
```

- Overloaded operator>>

```c++
char word[100];
std::cin >> word; // Input: kappa
std::cout << word; // kappa

// >> ignores white space
std::cin >> word; // input: kappa 123
std::cout << word; // kappa

// Use getline to also read the white space

std::cin.getline(word, 100); // kappa 123
std::cout << word; // kappa 123

// You can also pass a delimiter that stops the reading
std::cin.getline(word, 100, '!'); // kappa!123
std::cout << word; // kappa
```

- Never remove the null terminator

```c++
char word[]{'kappa'};
word[5] = '!';
std::cout << word; // Undefined behaviour
```

- cstring library https://en.cppreference.com/w/cpp/header/cstring
