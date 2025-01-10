#include <stdio.h>
#include <stdlib.h>
#include "day4.h"

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

			printf("\nX found at (%d, %d), ", i, j);
			unsigned char k = 0;
			char *ch_to_find[] = {"M", "A", "S"};
			// Pick a direction v (vertical) and h (horizontal)
			for (int v = -1; v < 2; v++)
			{
				for (int h = -1; h < 2; h++)
				{
					// Avoid segfault
					int v_cont = v + k * v, h_cont = h + k * h;
					if (i + v_cont < 0 || i + v_cont > HEIGHT - 1 || j + h_cont < 0 || j + h_cont > WIDTH - 1)
					{
						continue;
					}

					// Find "M" followed by "A" followed by "S"
					char next_ch = word_search[i + v_cont][j + h_cont];
					if (next_ch != *ch_to_find[k])
					{
						k = 0;
						continue;
					}

					printf("%c found at (%d, %d), ", *ch_to_find[k], i + v_cont, j + h_cont);
					k++;

					if (k == 3)
					{
						xmas_count++;
						k = 0;
						printf("xmas_count: %d ", xmas_count);
						continue;	// Avoid next line
					}

					h--;	// Keep h the same next iteration to keep picked direction
				}
			}
		}
	}

	printf("Result for Day 4, Part 1: %d\n", xmas_count);
	printf("Result for Day 4, Part 2: %d\n", xmas_count);
}
