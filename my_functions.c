/*  my_functions %{Cpp:License:ClassName} - Yann BOUCHER (yann) 22/05/2017
**
**
**            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
**                    Version 2, December 2004
**
** Copyright (C) 2004 Sam Hocevar <sam@hocevar.net>
**
** Everyone is permitted to copy and distribute verbatim or modified
** copies of this license document, and changing it is allowed as long
** as the name is changed.
**
**            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
**   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
**
**  0. You just DO WHAT THE FUCK YOU WANT TO.
*/

#include "my_functions.h"

void my_print_alpha()
{
    for (char c = 'a'; c <= 'z'; ++c)
    {
        my_putchar(c);
    }
}

void my_print_digits()
{
    for (char c = '0'; c <= '9'; ++c)
    {
        my_putchar(c);
    }
}

void my_print_revalpha()
{
    for (char c = 'z'; c >= 'a'; --c)
    {
        my_putchar(c);
    }
}

void my_isneg(int n)
{
    if (n > 0)
    {
        my_putchar('P');
    }
    else if (n < 0)
    {
        my_putchar('N');
    }
    else
    {
        my_putchar('\0'); // c'est ça qu'ils voulaient dire par null ?
    }
}

void my_print_comb()
{
    for (char c0 = '0'; c0 <= '9'; ++c0)
    {
        for (char c1 = c0+1; c1 <= '9'; ++c1)
        {
            for (char c2 = c1+1; c2 <= '9'; ++c2)
            {
                my_putchar(c0);
                my_putchar(c1);
                my_putchar(c2);
                if (c0 != '7' || c1 != '8' || c2 != '9')
                {
                    my_putchar(',');
                    my_putchar(' ');
                }
            }
        }
    }
}

void my_print_comb2()
{
    for (unsigned val1 = 0; val1 < 100; ++val1)
    {
        for (unsigned val2 = val1+1; val2 < 100; ++val2)
        {
            util_print2digits(val1);
            my_putchar(' ');
            util_print2digits(val2);
            if (val1 != 98 || val2 != 99)
            {
                my_putchar(',');
                my_putchar(' ');
            }
        }
    }
}

void my_print_nbr(int nb)
{
    if (nb < 0)
    {
        my_putchar('-');
        nb = -nb;
    }

    unsigned factor = 1;
    for (unsigned temp = nb; temp > 10; temp /= 10)
    {
        factor *= 10;
    }

    unsigned currentVal = nb;

    while (factor > 0)
    {
        unsigned val = currentVal % factor;
        char digit = '0' + currentVal / factor;
        my_putchar(digit);
        currentVal = val;
        factor /= 10;
    }
}

void my_print_combn(int n)
{
    if (n < 10)
    {
        util_print_combn_recurse(n, 0, 0, n);
    }
}

//////////// Utils

void util_print2digits(int val) // pour my_print_comb2()
{
    if (val < 0)
    {
        my_putchar('-');
        val = -val;
    }
    int units = val % 10;
    int tenths = val / 10;

    my_putchar('0' + tenths);
    my_putchar('0' + units);
}

int util_pow(int val, int exp)
{
    if (exp == 0)
    {
        return 1;
    }

    int result = val;
    for (int i = 1; i < exp; ++i)
    {
        result *= val;
    }

    return result;
}

void util_print_combn_recurse(int n, int startingFrom, int number, int startingN)
{
    if (n == 0)
    {
        if (startingN > 1 && number < util_pow(10, startingN-1))
        {
            my_putchar('0');
        }
        my_print_nbr(number);
        if (!util_combn_isLast(number, startingN))
        {
            my_putchar(',');
            my_putchar(' ');
        }
        return;
    }

    for (unsigned i = startingFrom; i < 10; ++i)
    {
        int tempNumber = number + i * util_pow(10, n-1);
        util_print_combn_recurse(n - 1, i + 1, tempNumber, startingN);
    }
}

int util_combn_isLast(int nb, int n) // par ex pour n = 3, on check si le nombre vaut 789
{
    if (nb < 0)
    {
        nb = -nb;
    }

    unsigned factor = 1;
    for (unsigned temp = nb; temp > 10; temp /= 10)
    {
        factor *= 10;
    }

    unsigned currentVal = nb;

    while (factor > 0)
    {
        unsigned val = currentVal % factor;
        if (currentVal / factor != (10 - n))
        {
            return 0;
        }
        currentVal = val;
        factor /= 10;
        --n;
    }

    return 1;
}
