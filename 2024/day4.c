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

	// Process for searching for "XMAS"
	int xmas_count = 0;
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			// Search letter by letter in word_search to find "X"
			if (word_search[i][j] != *"X")
			{
				continue;
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
		}
	}

	printf("Result for Day 4, Part 1: %d\n", xmas_count);
	printf("Result for Day 4, Part 2: %d\n", xmas_count);
}
