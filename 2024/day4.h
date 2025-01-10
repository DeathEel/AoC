#ifndef DAY4_H
#define DAY4_H

#ifdef INPUT_FILE
#undef INPUT_FILE
#endif

#define INPUT_FILE "inputs/input4.txt"

#ifdef HEIGHT
#undef HEIGHT
#endif

#define HEIGHT 140

#ifdef WIDTH
#undef WIDTH
#endif

#define WIDTH 140

bool find_next_letter(char (*word_search)[WIDTH], int i, int j, int v, int h, int *k);
int find_xmas(char (*word_search)[WIDTH], int i, int j);
int find_x_mas(char (*word_search)[WIDTH], int i, int j);
void solve_day4();

#endif
