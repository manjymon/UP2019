# Ex01 - Types, Operators and Pure Functions

## Hello World / General structure of a program

The most complicated beginner program ever

```c++
#include <iostream>
// Preprocessing directive #include, finds the given file and inserts its code
// iostream - (input, output stream) - standard library that we can use to write in / read from the console

// using namespace std; // Bad Practice. Pollutes the namespace with unused things

int main() // Every program starts from the main function
// int means that it returns an int value
// () means that it takes 0 arguments
{
    std::cout << "Hello World" << '\n';
    // std:: something that belongs to the std namespace
    // cout - (standard character output, console by default), a stream object that can be used to write on the console
    // << - binary operator for adding data TO a stream

    // std::endl -> (endline), outputs a new line and flushes the buffer
    // '\n' -> char literal, outputs a new line without flushing the buffer

    // "Hello World" - string literal

    return 0;
    // Return value of the funtion
    // 0 usually means successful execution
}

```

## Notes

- Do not include entire namespaces
```c++
using namespace std; // BAD

using std::cout; // GOOD
std::cout << "..."; // GOOD
```
- Add an empty line at the end of the file
- Avoid writing multiple statements on the same line
```c++
std::cout << "text"; return 0; // BAD

std::cout << "text";
return 0; // GOOD
```
- Use either spaces (usually 4) or tabs for identation but be consistent
```c++
int main()
{
    statement1();
     statement2(); // BAD, different number of spaces
	statement3(); // BAD, mixed tabs and spaces

    return 0;
}
```
- main should be int and not void
https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#f46-int-is-the-return-type-for-main


## Variables

### Definitions

- value: A piece of data, stored in memory
- object: region of storage (usually memory) that has a value and other associated properties
- variable: a named object
- identifier: name of a variable

#### Notes

- Names can contains letters, underscores and digits (but cannot start with a digit)
- Names starting with underscores should be avoided most of the times (mostly used in the standard library)
- Names should begin with a lower case letter
```c++
int snake_case_example;
int camelCaseExample;
```
- Be consistent
```c++
int snake_case_name;
int camelCaseName; // BAD, mixed styles

int snake_case_name;
int another_snake_case_name; // GOOD

int camelCaseName;
int anotherCamelCaseName; // GOOD
```
- Names should make sense and give information, don't rely on comments
```c++
// s is salary
int s1 = 3000; // BAD, you didn't have to use a comment for this

int s2 = 3000; // WORSE, you didn't even use a comment

int salary = 3000; // GOOD, name expresses intent
```

### Declaration vs Initialization

```c++
// Declaration
int a; // Creates a new int variable named a. The initial value is NOT 0

// Initialization
// copy initialization
int b = 10;
// direct initialization
int c(10); // Same as above for primitive types, can be faster for more complext types
// uniform intialization
int d{10}; // Not every type supports direct initialization

// zero initialization
int e{}; // e is the 0 of the type (e.g. 0 for ints 0.0 for doubles, '\0' for chars ...)
```

#### Notes
- Only make one definition per line
```c++
int a, b; // BAD

int a;
int b; // GOOD, easier to read, easier to change the type of only 1 variable, cannot lead to confusion with pointers (later exercise)
```
- Prefer uniform initialization
https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md?fbclid=IwAR0QsjJ28rbBSLBmdqdZjayc67CODBHhEPHKCY3M_xHOOizl7qPnAUrYVGE#Res-list
- Always initialize variables upon creation
```c++
int a;
/* ... */
a = 10; // BAD, someone could use a before this line and break something

int a{10}; // GOOD, you cannot use a before this
```

## Basic Primitive Types

### int
- integer
- whole number
- Size is not specified in the standard but it is almost always 4 bytes
- You can check the size of a type using the sizeof operator
```c++
// BONUS:
std::cout << sizeof(int) << '\n'; // Should output 4 on your machine
```

### unsigned
- a non-negative integer
- size is usually the same as int

### double
- floating point number
- usually 8 bytes
- not very precise, do not compare using ==
```c++
double a{/*...*/};
double b{/*...*/};
a == b; // BAD

#include <cmath> // Needed for abs (absolute value), more on this in a later exercies
double eps = 0.001;
std::abs(a - b) < eps; // GOOD
```
https://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/


### float
- same as double but 4 bytes => even less precision
- literals

### char
- always 1 byte
- contains a number between 0 and 255 that is mapped to a character using what's called an ASCII table
http://www.asciitable.com/
- literals
```c++
char a{'a'}; // one character in single quotes
char b{'\n'}; // special charactes are created using \
```

### bool
- always 1 byte
- either true or false (only 2 values so 7 wasted bits)
- 0 is false, every other value is true
- literals
```c++
bool a{true};
bool b{false};
```

### And more ...

## Operators

### Assignment Operator

- Assigns given value to a variable;

```c++
int f() { return 0; };

int main()
{
    int a{};
    int b{10};
    a = 10; // could assign a literal
    a = b; // or a variable
    a = f(); // or the result of a function

    return 0;
}

```
- Returns the variable we assigned to
```c++
int a{};
int b{};

a = b = 10;
// This is equivalent to: b = 10; a = b;
// Both a and b become 10
```

### Arithmetic Operators
```c++
// +, - and * are standard
int a{10};

int b{a + 10}; // b = 20; 
int c{a - 10}; // c = 0;
int d{a * 10}; // d = 100;

// For integers / is whole division and % is modulo

int e{a/3}; // e = 3
int f{a%3}; // f = 1
// a = 3 * e + f;

// For floats / is regular division

double g = a / 20.0; // g = 0.5

// all of these return a new number
```

### Shorthand Operators
```c++
int a{10};

a += 10; // equivalent to a = a + 10;
a -= 10; // equivalent to a = a - 10;
// ...

a++; // equivalent to a = a + 1; returns the old value
++a; // equivalent to the above but returns the new value

a--; // equivalent to a = a - 1; returns the old value
--a; // equivalent to the above but returns the new value
```

#### Notes
- For simple types the compiler will replace a++ with ++a when you don't need the return value
- For more complext types prefer ++a when possible
- Try to avoid using the return value of ++ and -- as it leads to confusion

### Comparasion Operators

Compare two values and return a bool.

```c++
int a{10};

// equality
bool cmp1{a == 10}; // !!! = is not ==; cmp1 = true

// The next 4 are the same as the math equivalents 
bool cmp2{a < 10}; // cmp2 = false
bool cmp3{a > 10}; // cmp3 = false
bool cmp4{a <= 10}; // cmp4 = true
bool cmp5{a >= 10}; // cmp5 = true

// inequality
bool cmp6{a != 10}; // cmp6 = false 
```
## Input & Output

This is actually a really hard topic that we will gloss over

### Reading data FROM the console

```c++
int a{};
std::cin >> a;

// cin -> standard character input stream object
// >> -> stream operator that takes data from a stream and puts it in an object
```

### Writing data TO the console
```c++
int a{20};
std::cout << a;

// cout -> standard character output stream object
// >> -> stream operator that takes an object and serializes it to a stream
```

### Notes

- Avoid flushing for no reason
```c++
std::cout << a << std::endl; // BAD, do we really need to flush here?
std::cout << a << '\n'; // GOOD, the compiler will print this when necessary
```
- Sometimes it is necessary
```c++
// Super simple and silly example

std::cout << "I am about to do something bad" << '\n';
something_terribly_misguided_that_crashes_the_program();

// There is no guarantee that the compiler will print the previous message before the program crashes

std::cout << "I am about to do something bad" << std::endl;
something_terribly_misguided_that_crashes_the_program();

// The message will be printed 100% before the crash
```
- BONUS: You can flush without adding a new line using std::flush
```c++
std::cout << "kappa123" << std::flush;
```

## Functions

- Reuse code
- Give a name to a piece of code
- That's all for now, wait for upcoming exercises

### Syntax

```c++
/*
<return type> <name>(<type_of_arg_1> <name_of_arg_1>, <type_of_arg_2> <name_of_arg_2>, ...)
{
    <body>;
    return <result>;
}
*/

// e.g.

int add(int a, int b) // 2 arguments
{
    return a + b;
}

int meaning_of_life() // 0 arguments
{
    return 42;
}
```

### Declaration

Declare functions before you use them

```c++
int add(int a, int b) { return a + b; }

int main()
{
    int a{add(10, 20)}; // GOOD
    int b{bad_add(10, 20)}; // BAD, bad_add has not been declared yet


}

int bad_add(int am int b) { return a + b; }

```

BONUS: You can declare a function before you define it (FORWARD DECLARATION)
```c++
int this_works();

int main()
{
    int a{this_works();} // GOOD, this_works has been declared before main

    return 0;
}

int this_works() { return 42; } // but the definition is here

// This is not super important now but a VERY powerful tool when we start to separate our code

```

You cannot define a function (in this fashion) inside another function
```c++
int main()
{
    int error() { return 0; } // ERROR: Does not compile
    return 0;
}
```

There are different ways to position the brackers

```c++
int simple() { return 42; } // GOOD for small functions
int more_complex() { int x; std::cin >> x; return x; } // BAD, multiple statements on the same line

int same_line() {
    int x;
    std::cin >> x;
    return x;
} // GOOD

int new_line()
{
    int x;
    std::cin >> x;
    return x;
} // also GOOD but don't mix the last 2, be consistent
```

Functions follow the same naming conventions as variables (see above)
```c++
int a(int x, int y) { return x + y; } // BAD, what does 'a' mean?
int add(int x, int y) { return x + y; } // GOOD
```

### Usage

```c++
// <name>(<argument1>, <argument2>, ...)

// e.g.

int a{add(10, 20)}; // you can pass literals

int arg1{10};
int arg2{20};
int b{add(arg1, arg2)}; // or variables

int c(add(5, 5), add(10, 10)); // or results of other functions to def
```

### Scope

The arguments passed to a function are COPIES (see pass-by-value pass-by-reference in a later exercise)

```c++
int increment(int a)
{
    return a++;
}

int main()
{
    int a{10}; // this a is not the a in increment
    int b = increment(a); // b is now 11, but a is still 10
    return 0;
}
```

The only variables you can in the body access are
- the passed arguments
- the ones declared in the body (but not inside {}, more on that next 2 weeks)
- global ones (next week)

```c++
int another_function()
{
    int in_another_function{};

    return 322;
}

int scope_check(int argument)
{
    int same_scope{};
    {
        int deeper_scope{};
        std::cout << deeper_scope; // GOOD
    }

    std::cout << argument; // GOOD
    std::cout << same_scope; // GOOD
    std::cout << deeper_scope; // ERROR: does not compile
    std::cout << in_another_function; // ERROR: does not compile

    return 0;
}

```

## Problems

### 01. Given 3 sides, calculate the perimeter of a triangle

```c++
double triangle_perimeter(double a, double b, double c)
{
    return a + b + c;
}
```

### 02. Given a 3-digit number, calculate the sum of its digits 
```c++
unsigned digits_sum(int number)
{
    unsigned ones = number % 10;
    unsigned tens = number / 10 % 10;
    unsigned hundreds = number / 100;

    return ones + tens + hundreds
}
```

## Bonus problems

- Try not to use material we haven't covered yet (e.g. branches and loops)
- Try to write as many functions as needed to make the code readable

### 01b. Given 3 sides, calculate the semi-perimeter of a triangle

HINT: Use the perimeter function to make it more readable 

### 02b. Given 3 sides, calculate the area of a triangle

HINT 1: Reuse the function in 01b \
HINT 2: Try to use the cmath library https://en.cppreference.com/w/cpp/header/cmath

### 03b. Given 2 3-digit numbers, check if the product of their digits is equal

HINT: Write as many functions as needed

### 04b. Given an integer and a divisor return the smallest integer equal to or bigger than the given one that is divisible by the divisor

e.g. round(10, 3) -> 12; round(12, 3) -> 12

HINT: Use the different kinds of division

### 05b (hard?). Given 2 integers return the bigger one
