#include <stdio.h>
#include <ctype.h>
#include "day3.h"

void enable_disable_mul(char *ch, FILE **file, bool *is_mul)
{
	bool is_mul_temp = true;
	unsigned char i = 0;
	char *next_ch[] = {"o", "(", ")", "n", "'", "t"};

	// Initial screen for "d"
	if (*ch != *"d")
	{
		return;
	}

	while ((*ch = (char)getc(*file)) != EOF)
	{
		// After ")" found, change status
		if (i == 3)
		{
			*is_mul = is_mul_temp;
			return;
		}
		// When "t" found, go back for "()"
		else if (i == 6)
		{
			i = 1;
		}

		// Find next in array
		if (*ch == *next_ch[i])
		{
			i++;
			continue;
		}
		// If "n" found in place of "(", find "'t" and set false flag
		else if (*ch == *next_ch[3] && i == 1)
		{
			i = 4;
			is_mul_temp = false;
			continue;
		}

		// "do()" or "don't()" interrupted.
		return;
	}
}

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
			return factor;
		}

		if (isdigit(*ch) != 0)
		{
			is_digit_found = true;
			factor *= 10;
			factor += (int)*ch - 48;
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
	unsigned long sum_part1 = 0, sum_part2 = 0;
	bool is_mul = true;

	while ((ch = (char)getc(file)) != EOF)
	{
		// Check for "do()" or "don't()"
		enable_disable_mul(&ch, &file, &is_mul);

		// Check for "mul("
		if (ch == *next_ch[i] && i < 4)
		{
			i++;
			continue;
		}
		else if (i < 4)
		{
			i = 0;
			continue;
		}

		// Check for digits and ","
		if ((factor = check_digits(&ch, &file, &i)) == 0)
		{
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
		sum_part1 += product;
		if (is_mul == true)
		{
			sum_part2 += product;
		}

		i = 0;
		factor = 1;
		product = 1;
	}

	printf("Result for Day 3, Part 1: %ld\n", sum_part1);
	printf("Result for Day 3, Part 2: %ld\n", sum_part2);
}
