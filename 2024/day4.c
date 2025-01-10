#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "day4.h"

bool find_next_letter(char (*word_search)[WIDTH], int i, int j, int v, int h, int *k)
{
	char *ch_to_find[] = {"M", "A", "S"};

	// Avoid segfault
	int v_cont = v + *k * v, h_cont = h + *k * h;
	if (i + v_cont < 0 || i + v_cont > HEIGHT - 1 || j + h_cont < 0 || j + h_cont > WIDTH - 1)
	{
		*k = 0;
		return 0;
	}

	// Find "M" followed by "A" followed by "S"
	char next_ch = word_search[i + v_cont][j + h_cont];
	if (next_ch != *ch_to_find[*k])
	{
		*k = 0;
		return 0;
	}

	(*k)++;

	if (*k == 3 || find_next_letter(word_search, i, j, v, h, k) == 1)
	{
		return 1;
	}

	return 0;
}

int find_xmas(char (*word_search)[WIDTH], int i, int j)
{
	int xmas_count = 0;

	// Search letter by letter in word_search to find "X"
	if (word_search[i][j] != *"X")
	{
		return xmas_count;
	}

	// Pick a direction v (vertical) and h (horizontal)
	for (int v = -1; v < 2; v++)
	{
		for (int h = -1; h < 2; h++)
		{
			int k = 0;
			bool xmas_found = find_next_letter(word_search, i, j, v, h, &k);

			if (xmas_found == 1)
			{
				xmas_count++;
			}
		}
	}

	return xmas_count;
}

int find_x_mas(char (*word_search)[WIDTH], int i, int j)
{
	// Avoid segfault
	if (i - 1 < 0 || i + 1 > HEIGHT - 1 || j - 1 < 0 || j + 1 > WIDTH)
	{
		return 0;
	}

	// Search letter by letter in word_search to find "A"
	if (word_search[i][j] != *"A")
	{
		return 0;
	}

	for (int k = 0; k < 2; k++)
	{
		// Pick top corners and verify "M" or "S"
		// Bottom corners must have "S" or "M" (opposite of top corners)
		char top_corner = word_search[i - 1][j - 1 + 2 * k];
		char bottom_corner = word_search[i + 1][j + 1 - 2 * k];
	
		// Use ASCII to connect the two corners
		// Example: if top_left == 77 (M in ASCII), then bottom_right must be 83 (S in ASCII), and vice versa
		if ((top_corner != 77 && top_corner != 83) || top_corner + bottom_corner != 160)
		{
			return 0;
		}
	}

	char tl = word_search[i - 1][j - 1];
	char tr = word_search[i - 1][j + 1];
	char bl = word_search[i + 1][j - 1];
	char br = word_search[i + 1][j + 1];
	printf("%c %c\n %c\t at (%d, %d)\n%c %c\n\n", tl, tr, word_search[i][j], i, j, bl, br);

	return 1;
}

void solve_day4()
{
	FILE *file = fopen(INPUT_FILE, "r");
	if (file == NULL)
	{
		perror("No input4.txt file found");
		return;
	}

	char word_search[HEIGHT][WIDTH];
	int i = 0, j = 0;
	char ch;

	while ((ch = (char)getc(file)) != EOF)
	{
		if (ch == *"\n")
		{
			i++;
			j = 0;
			continue;
		}

		word_search[i][j++] = ch;
	}

	int xmas_count = 0;
	int x_mas_count = 0;
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			xmas_count += find_xmas(word_search, i, j);
			x_mas_count += find_x_mas(word_search, i, j);
		}
	}

	printf("Result for Day 4, Part 1: %d\n", xmas_count);
	printf("Result for Day 4, Part 2: %d\n", x_mas_count);
}
