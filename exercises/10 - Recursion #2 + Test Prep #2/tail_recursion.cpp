#include <iostream>

/*
    We didn't have time for this, so we will go over it next time.
    This is a summary
*/

// Regular Recursion
unsigned factorial1(unsigned n)
{
    return n <= 1 ? 1 : n * factorial1(n - 1);
}

/*
    Evaluation:

    f(6) =
    = 6 * f(5) =
    = 6 * 5 * f(4) =
    = 6 * 5 * 4 * f(3) =
    = 6 * 5 * 4 * 3 * f(2) =
    = 6 * 5 * 4 * 3 * 2 * f(1) =
    = 6 * 5 * 4 * 3 * 2 * 1 =
    = 720

    We need to expand everything before calculating. This fills up the stack quickly.
*/

// Tail Recursion (The last thing that happens is the recursive call)
unsigned tail_factorial(unsigned n, unsigned result)
{
    return n <= 1 ? result : tail_factorial(n - 1, result * n);
}

/*
    Evaluation:

    f(6) =
    = tf(6, 1) =
    = tf(5, 6) =
    = tf(4, 30) =
    = tf(3, 120) =
    = tf(2, 360) =
    = tf(1, 720) =
    = 720

    Wastes less stack memory.
*/

unsigned factorial2(unsigned n)
{
    return tail_factorial(n, 1);
}

int main()
{
	std::cout << factorial1(6) << '\n';
	std::cout << factorial2(6) << '\n';
	return 0;
}
