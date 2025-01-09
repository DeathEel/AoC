#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "day3.h"

int check_digits(char *ch, FILE **file, unsigned char *index)
{
	bool is_digit_found = false;
	int factor = 0;
	char *next_ch;

	// Initial screen for digits
	if (isdigit(*ch) != 0)
	{
		is_digit_found = true;
		factor *= 10;
		factor += (int)*ch - 48;
		printf("%c", *ch);
	}
	else
	{
		return 0;
	}

	if (*index == 4)
	{
		next_ch = ",";
	}
	else
	{
		next_ch = ")";
	}

	// Process rest of digits and return
	while ((*ch = (char)getc(*file)) != EOF)
	{
		if (*ch == *next_ch && is_digit_found == true)
		{
			printf("%c", *ch);
			return factor;
		}

		if (isdigit(*ch) != 0)
		{
			is_digit_found = true;
			factor *= 10;
			factor += (int)*ch - 48;
			printf("%c", *ch);
		}
		else
		{
			return 0;
		}
	}

	// Avoid control warning
	return 0;
}

void solve_day3()
{
	FILE *file = fopen(INPUT_FILE, "r");
	if (file == NULL)
	{
		perror("No input3.txt file found");
		return;
	}

	char ch;
	char *next_ch[] = {"m", "u", "l", "(", ",", ")"};
	unsigned char i = 0;
	int factor = 1, product = 1;
	unsigned long sum = 0;

	while ((ch = (char)getc(file)) != EOF)
	{
		// Check for "mul("
		if (ch == *next_ch[i] && i < 4)
		{
			printf("%c", ch);
			i++;
			continue;
		}
		else if (i < 4)
		{
			if (i != 0)
			{
				printf("\n");
			}

			i = 0;
			continue;
		}

		// Check for digits and ","
		if ((factor = check_digits(&ch, &file, &i)) == 0)
		{
			printf("\n");
			i = 0;
			factor = 1;
			product = 1;
			continue;
		}
		// Check for digits and ")"
		else if (i == 4)
		{
			i++;
			product *= factor;
			factor = 1;
			continue;
		}

		product *= factor;
		sum += product;
		printf(" is %d\n", product);
		i = 0;
		factor = 1;
		product = 1;
	}

	printf("Result for Day 3, Part 1: %ld\n", sum);
}
