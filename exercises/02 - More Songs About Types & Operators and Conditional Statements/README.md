# Ex02 - More Songs About Types & Operators and Conditional Statements

## const type qualifer

Adding const during a variable declaration specifies that it should be constant and prevents people from changing it

- const variables must be initialized

```c++
const PI = 3.14; // GOOD
const PI2; // ERROR: Does not compile
```
- It's easier to reason about const variables (you don't need to worry about someone else changing the data)
- One popular approach to programming is making all data constant
- By default, make variables constant https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#con1-by-default-make-objects-immutable

## Definition: Integral Type

Any type that models a whole number (e.g. int, unsigned, long int, etc ...) + bool + different versions of char

Full list here: https://en.cppreference.com/w/cpp/types/is_integral

## enum

User defined type whose values are restricted to a subset of an integral type

```c++
enum class Status
{
    OK,
    NOT_OK,
    IN_QUEUE,
};

/* Values
OK == 0
NOT_OK = 1
IN_QUEUE = 2
*/

Status status = Status::OK; // You have to specify the type (Status) to which the value (OK) belongs
```

You can change the default values

```c++
enum class Permissions
{
    READ = 1,
    WRITE = 2,
    EXECUTE = 4,
};
```

The default underlying type is int but you can change it to any integral one to reduce the size

```c++
enum class E1
{
    OK,
    NOT_OK
};

// Default is int
sizeof(E1) == sizeof(int);

enum class E2 : bool
{
    OK,
    NOT_OK
};

sizeof(E2) == sizeof(bool); // We saved 3 bytes
```

### Guidelines

https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#enum-enumerations

All of these rules should be relevant to you except the macro ones.

ALL_CAPS should be ok as enum names

- Most languages use ALL_CAPS for enums and constants
- We won't be using macros during the course
- Macros should be generally avoided when possible

## Logical operators

### Disjunction ( || )

Binary operator that returns true iff either of the operands are true

```c++
false || false == false;
false || true  == true;
true  || false == true;
true  || true  == true;
```

### Conjuction ( && )

```c++
false && false == false;
false && true  == false;
true  && false == false;
true  && true  == true;
```
Binary operator that returns true iff both of the operands are true

### Negation ( ! )

Unary operator that returns the inverse of the operand

```c++
!true  == false
!false == true
```

## Conditional Statements

### if

```c++
if (statement)
{
    // This will execute iff statement is true
}
else if (other_statement)
{
    // This will execute iff statement is false and other_statement is true
}
else
{
    // This will execute iff both statement and other_statement are false
}
```

- else if must follow an if or an else if
- else must be the last thing in the chain

- You can nest ifs

```c++
if (statement1)
{
    // This will execute if statement1 is true
    if (statement2)
    {
        // This will execute if both statement1 and statement2 are true
    }
}
```

- In C++17 you can initilize variables in the condition to limit their scope

```c++
if (bool condition = get_value(); condition)
{
    std::cout << condition; // OK, condition is in scope
}
else if (bool another = get_another_value(); another)
{
    std::cout << condition << another; // OK, both are in scope. Condition was passed on from the if
}
else
{
    std::cout << condition << another; // OK, both are in scope. Condition was passed on from the if, another from the else if
}
std::cout << condition; // ERROR, condition is out of scope
std::cout << another; // ERROR, another is out of scope

```

- You can use early returns in functions instead of else

```c++
int f1(bool cond)
{
    if (cond)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

// is equivalent to

int f2(bool cond)
{
    if (cond)
    {
        return 1;
    }

    return 2;
}
```

## More to come ...