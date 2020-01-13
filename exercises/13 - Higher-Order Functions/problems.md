# Higher-Order Functions

## Type definitions

```c++
using UnaryPredicate = bool(*)(int);
using Comparator = bool(*)(int, int);

using UnaryOperation = int(*)(int);
using BinaryOperation = int(*)(int, int);

using UnaryProcedure = void(*)(int);
```

## Problems

### 1

```c++
bool all_of(const int * begin, const int * end, UnaryPredicate p)
```

Return true if every element in the range [begin; end) statisfies the given predicate.

### 2

```c++
bool any_of(const int * begin, const int * end, UnaryPredicate p)
```

Return true if at least one element in the range [begin; end) statisfies the given predicate.

### 3

```c++
bool none_of(const int * begin, const int * end, UnaryPredicate p)
```

Return true if none of the elements in the range [begin; end) statisfy the given predicate.

### 4

```c++
void for_each(const int * begin, const int * end, UnaryProcedure p)
```

Call the given procedure for every element in the range.

### 5

```c++
int * transform(int * begin, int * end, UnaryOperation f)
```

Transform every element in the range by applying the given operation to it. Return pointer to the new end.

### 6

```c++
unsigned count_if(const int * begin, const int * end, UnaryPredicate p)
```

Count the number of elements in [begin, end) that statisfy the given predicate.

### 7

```c++
const int * find_if(const int * begin, const int * end, UnaryPredicate p)
```

### 8

```c++
int * remove_if(int * begin, int * end, UnaryPredicate p)
```

Remove every element in [begin; end) that statisfies the given predicate. Return a pointer to the new end.

### 9

```c++
int accumulate(int * begin, int * end, int init, BinaryOperation op)
```

Old accumulate but with a custom binary operation.

#### Usage

- Calculate the sum / product of the elements in the range

### 10

```c++
int inner_product(const int * begin1, const int * end1,
                  const int * begin2, int init,
                  BinaryOperation op1, BinaryOperation op2)
```

Old inner product with 2 custom operations.

#### Usage

- Count number of pairwise matches between 2 ranges using inner product.
- Return the sum of the largest number in each position.

#### 11

```c++
void sort(int * begin, int * end, Comparator cmp)
```

Sort the range [begin; end) using the comparator cmp. For every 2 consecutive elements x and y cmp(x, y) should be true.

### 12

```c++
int * stable_partition(int * begin, int * end, UnaryPredicate p)
```

Stable partition with a custom predicate.
