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
#ifndef MY_FUNCTIONS_H
#define MY_FUNCTIONS_H

#include "my_putchar.h"

// j'ai pas créé de fonction putstr car dans le doute je sais pas si ils consiféraient un const char* comme un array, mais je suppose que oui

void my_print_alpha();
void my_print_revalpha();
void my_print_digits();
void my_isneg(int n);
void my_print_comb();
void my_print_comb2();
void my_print_nbr(int nb);
void my_print_combn(int n);

void util_print2digits(int val);
int util_pow(int val, int exp);
void util_print_combn_recurse(int n, int startingFrom, int number, int startingN);
int util_combn_isLast(int nb, int n);

#endif // MY_FUNCTIONS_H
