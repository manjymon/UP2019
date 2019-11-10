# 06 - Test Prep

## 01

Given a positive integer, check if the sum of its even digits is equal to the sum of its odd digits

### Example

```c++
equal_sums(1223); // -> true
equal_sums(1234); // -> false
```

## 02

Given a positive integer n, output the first n numbers that statisfy the following predicates
- The difference between the smallest and the largest digit in the number is 3
- The sum of the digits of the number is prime

### Example
```c++
std::cout << sum_1(5) << "\n-------\n";
std::cout << sum_2(10) << '\n';

/* Output
14
25
30
36
41
146
-------
2
4
5
7
11
12
14
16
20
21
111
*/
```

## 03

Find the largest palindrome that is a product of two 3-digit numbers

### Example

```c++
largest_palindrome(); // 906609
```

## 04

Given a positive epsilon and a x, calculate the following sum
cos^3(x) = 1/4 Σ|from k=1 to inf| (-1)^k (3^(2k) + 3) / (2k)! * x ^ (2k)

The summation must stop after 2 consecutive members of the sequence with difference <= eps have been added. 

### Example

```c++
cos3(1, 0.001); // -0.842271  
```

## 05

Given 2 arrays representing the x and y coordinates of n points, find the position (in the arrays) of the point that is furthest away from the center (0, 0);

### Example

```c++
int x_coords[]{1, 2, 3};
int y_coords[]{3, 2, 2};

furthest_point(x_coords, y_coords, 3); // 2 (point (3, 2))
```

## 06

Given a positive integer, check if its digits form an increasing sequence.

### Example

```c++
increasing_digits(1123); // true
increasing_digits(1232); // false
```

## 07

Given 2 positive integers p and q, check if the interval [p; q] contains a number where:

- The least significant digit is bigger than the 2nd least siginifant one
- The 2nd least significant digit is smaller than the 3rd least significant one
- The 3rd least significant digit is bigger than the 4th one
- ...

Example: 1324 -> 1 < 3 > 2 < 4

### Example

```c++
alternating_number_in_range(1300, 1400); // true -> 1301
alternating_number_in_range(1350, 1355); // false
```

## 08

Given 2 natural numbers p and k, Find the smallest natural number, bigger than p, that can be represented as the sum of the cubes of 2 natural numbers a and b where b = a + k;

### Example

```c++
find_smallest_cube_sum(100, 1); // 188
```

## 09

Given a positive integer, check if it contains duplicate digits

### Example

```c++
duplicate_digits(123); // false
duplicate_digits(1231); // true
```

## 10 

Given a positive integer n, return the sum of the first n positive integers who have a prime number of divisors smaller than n

### Example

```c++
// Input: 5
// Output: 23 (2 + 3 + 4 + 6 + 8)
```

## 11

Given a positive integer, output the number of occurences of every even digit. Don't output anything for digits that were not present.

### Example

```c++
even_digits_occurences(3242726);
/* Output:
2: 3
4: 1
6: 1
*/
```

## 12

Given an array of positive integers, return the largest one that is a power of 2 or 1 if there are none.

### Example

```c++
unsigned arr1[]{4, 1, 3, 4, 16, 9, 9};
largest_power_of_2(arr1, 7); // -> 16
unsigned arr2[]{3, 6, 12, 5, 5};
largest_power_of_2(arr2, 5); // -> 1
```
