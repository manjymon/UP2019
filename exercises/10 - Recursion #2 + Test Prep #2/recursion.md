# Recursion 2

## 00 - Levenstein Distance

See last exercise

## 01 - Tail Recursion

Demonstrate tail recursion with a simple recursive function (e.g. factorial)

## 02 - Merge Sort

### 02a

```c++
void inplace_merge(int * begin, int * mid, int * end)
```

Given 2 consecutive sorted ranges [begin; mid) and [mid; end) with no more than 100 elements, merge them in a one sorted range [begin; end)

### 02b

```c++
void merge_sort(int * begin, int * end)
```

Sort given range (no more than 200 elements) using merge sort.

## 03 - Stable Partition

```c++
int * stable_partition_parity(int * begin, int * end)
```

Given a range, partitition it so that:
- Every even element is before every odd element
- The relative positions of every 2 even elements remains the same (e.g [2, 1, 4] must become [2 4 1] and NOT [4 2 1]) 
- The relative positions of every 2 odd elements remains the same
- Return the position of the first odd element (or end if there are none)
- You can use std::algorithms that we have implemented before

### Example

```c++
int arr[]{1, 3, 5, 2, 6, 8, 7, 10, 9, 11, 12, 20, 13, 15};

int * pivot = stable_partition_parity(std::begin(arr), std::end(arr));

for (int * i = std::begin(arr); i != pivot; ++i)
{
    std::cout << *i << ' ';
}

std::cout << '\n';

for (int * i = pivot; i != std::end(arr); ++i)
{
    std::cout << *i << ' ';
}

/*
    2 6 8 10 12 20
    1 3 5 7 9 11 13 15
*/
```

## 	04 - Water Jugs Problem

```c++
int water_jugs(unsigned max_1, unsigned max_2, unsigned target)
```

Given the maximum capacity of 2 jugs and a given target (max 20 litres), return the minimal number of operations needed to get the targetted amount of water in one of the jugs.

The operations are:
- Completetly remove all the water from eithe of the jugs.
- Fill up one of the jugs to its full capacity
- Move water from one jug to the other until either the one being filled is completely full or the other is completely empty

### Example

```c++
std::cout << water_jugs(4, 3, 2); // 4
/*
    0/4, 0/3 (1: Fill up the second one)
    0/4, 3/3 (2: Move the water from 2 to 1)
    3/4, 0/3 (3: FIll up the second one)
    3/4, 3/3 (4: Move the water from 2 to 1)
    4/4, 2/3 (DONE! There are 2 litres in the second jug)
*/
```

## 05 - N-Queens

```c++
void n_queens(unsigned n)
```

Given a number n (max 20) output a n x n chess boards with n queens placed where none of the queens can take another one in one move if such a configuration exists. Use Q for queens and _ for empty fields

### Example

```c++
n_queens(3); // Nothing
n_queens(4);

/*
  _  _  Q  _ 
  Q  _  _  _ 
  _  _  _  Q 
  _  Q  _  _ 
*/
```







