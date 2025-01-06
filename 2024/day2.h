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

int dampen_problem(int *problem_dampened, int *safe_flag_part1, int *safe_flag_part2);
void get_safe_count(int *report, int *safe_count);
void read_report(FILE *file, int *report, int *capacity);
void solve_day2();

#endif
