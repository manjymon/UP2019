# 08 - Matrices

```c++
const unsigned max_size{100};
```

## 01 - Factorial

```c++
unsigned factorial(int n)
```

Write a recursive function that calculatest n!

### Example

```c++
factorial(6); // 720
factorial(0); // 1
```

## 02 - Fibonacci

```c++
unsigned fib(n)
```

### Notes:
- This is worse than our previous implementation
- Next time (dynamic programming / memoization)

Write a recursive function that calculates the nth fibonacci number.

## 03 - Exponent

```c++
int exp(int a, unsigned n)
```

Write a recursive funtion that calculates a to the power of n.

### Bonus

- Fast (logn) exponent

### Example

```c++
exp(2, 10); // 1024
```

## 04 - Sum

```c++
int sum(const int* begin, const int* end)
```

Write a recursive function that sums the elements of a range

### Example

```c++
const int arr[]{1, 2, 3, 4, 5};
sum(std::begin(arr), std::end(arr)); // 15
```

## 05 - DFS

```c++
bool path(bool arr[][max_size], unsigned height, unsigned width, int x_source, int y_source, int x_target, int y_target)
```

Given a height x width boolean matrix that represents a labyrinth, where false means passable and true means unpassable. Check if their is a valid path between (x_source, y_source) and (x_target, y_targer).

- You can only move up, down, left and right.
- You cannot go through unpassable fields
- You cannot leave the grid

### Example

```c++
int grid[][max_size]{
    {0, 0, 0, 0},
    {0, 0, 1, 0},
    {1, 1, 1, 1},
    {0, 0, 0, 0}
};

path(grid, 4, 4, 0, 0, 1, 3); // true
path(grid, 4, 4, 0, 0, 3, 1); // false
```

## 06 - Flood Fill

```c++
void flood_fill(int screen[][max_size], unsigned height, unsigned width, unsigned x, unsigned y, unsigned new_color)
```

Given a height x width int matrix representing a screen in MS Paint, where a different number indicates a different color. Implement the paint bucket tool.


### Example

```c++
int screen[][max_size]{
    {0, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 0, 1, 0, 0},
    {1, 1, 1, 0, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 0, 1, 1, 1},
    {0, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 0, 1, 0, 0}
};

flood_fill(screen, 7, 7, 0, 3, 2);

/*
    {0, 0, 1, 2, 1, 0, 0},
    {0, 0, 1, 2, 1, 0, 0},
    {1, 1, 1, 2, 1, 1, 1},
    {2, 2, 2, 2, 2, 2, 2},
    {1, 1, 1, 2, 1, 1, 1},
    {0, 0, 1, 2, 1, 0, 0},
    {0, 0, 1, 2, 1, 0, 0}
*/

flood_fill(screen, 7, 7, 0, 5, 3);

/*
    {0, 0, 1, 2, 1, 3, 3},
    {0, 0, 1, 2, 1, 3, 3},
    {1, 1, 1, 2, 1, 1, 1},
    {2, 2, 2, 2, 2, 2, 2},
    {1, 1, 1, 2, 1, 1, 1},
    {0, 0, 1, 2, 1, 0, 0},
    {0, 0, 1, 2, 1, 0, 0}
*/
```

## 07 - Quick Sort

```c++
void quick_sort(int* begin, int* end);
```

Write a recursive quick sort algorithm

### Hints

- Use the partition algorithm from earlier.
- Divide and conquer

## 08 - Levenstein Distance

```c++
unsigned levenstein_distance(const char* source, const char* target)
```

Given 2 cstrings, calculate their Levenstein Distance

The Levensten Distance between 2 words is the minimal amount of changes needed to turn the first word into the second one.

The permitted changes are
- Adding one letter (e.g. Kapp -> Kappa)
- Removing one letter (e.g. Kappa -> Kapp)
- Changing one letter with another (e.g. Kappa -> Mappa)

### Example

```c++
levenstein_distance("kitten", "mitten"); // 1, swap k with m
levenstein_distance("bulgaria", "belgium"); /* 5
belgaria (swap u with e)
belgria (remove a)
belgia (remove r)
belgiu (swap a with u)
belgium (add m)

Note: this is not the only possible solution
*/
```

### Bonuses

- Implement a DP solution (for words with no more than 100 characters)
- Modify your solution to give the Damerau-Levenstein distance

Damerau-Levenstein also permits transposing adjacent characters:

e.g.

```c++
damerau_levenstein_distance('usnigned', 'unsigned'); // 1, swap the first n with the previous s, hardest word in CS btw
```
