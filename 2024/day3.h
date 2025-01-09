#ifndef DAY3_H
#define DAY3_H

#ifdef INPUT_FILE
#undef INPUT_FILE
#endif

#define INPUT_FILE "inputs/input3.txt"

#ifdef LINES
#undef LINES
#endif

#define LINES 1000

int check_digits(char *ch, FILE **file, unsigned char *index);
void solve_day3();

#endif
