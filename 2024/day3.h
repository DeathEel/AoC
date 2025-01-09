#include <stdbool.h>

#ifndef DAY3_H
#define DAY3_H

#ifdef INPUT_FILE
#undef INPUT_FILE
#endif

#define INPUT_FILE "inputs/input3.txt"

void enable_disable_mul(char *ch, FILE **file, bool *is_mul);
int check_digits(char *ch, FILE **file, unsigned char *index);
void solve_day3();

#endif
