#ifndef DAY2_H
#define DAY2_H

#ifdef INPUT_FILE
#undef INPUT_FILE
#endif

#define INPUT_FILE "inputs/input2.txt"

#ifdef LINES
#undef LINES
#endif

#define LINES 1000

#ifdef ELEMS_MAX
#undef ELEMS_MAX
#endif

#define ELEMS_MAX 8


#ifdef ELEMS_MIN
#undef ELEMS_MIN
#endif

#define ELEMS_MIN 5

unsigned char dampen_problem(unsigned char *report, unsigned char level_count, unsigned char ignored_index);
unsigned char check_safety(unsigned char *report, unsigned char level_count);
unsigned char read_report(FILE *file, unsigned char *report);
void solve_day2();

#endif
