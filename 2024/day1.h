#ifndef DAY1_H
#define DAY1_H

#ifdef INPUT_FILE
#undef INPUT_FILE
#endif

#define INPUT_FILE "inputs/input1.txt"

#ifdef LINES
#undef LINES
#endif

#define LINES 1000

int compare(const void *p, const void *q);
void solve_day1();

#endif
