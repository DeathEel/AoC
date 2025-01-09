#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "day2.h"

unsigned char dampen_problem(unsigned char *report, unsigned char level_count, unsigned char ignored_index)
{
	char gradient = 0;

	// Copy of check_safety with returns instead of breaks
	for (unsigned char i = 1; i < level_count; i++)
	{
		char level_delta;

		// Skip the ignored index and calculate level_delta from two indices behind
		if (i == ignored_index)
		{
			i++;

			// Break at the end of report
			if (i == level_count)
			{
				break;
			}

			level_delta = report[i] - report[i - 2];
		}
		// Index from directly behind normally
		else
		{
			// If the ignored index is 0, calculate level_delta from indices 2 and 1 instead
			if (i == 1 && ignored_index == 0)
			{
				i++;
			}

			level_delta = report[i] - report[i - 1];
		}

		if (level_delta == 0)
		{
			return 0;
		}

		if (gradient == 0)
		{
			gradient = level_delta > 0 ? 1 : -1;
		}

		if (gradient * level_delta < 1 || gradient * level_delta > 3)
		{
			return 0;
		}
	}
	
	return 2;
}

unsigned char check_safety(unsigned char *report, unsigned char level_count)
{
	bool is_dampened = false;
	char gradient = 0;
	
	for (unsigned char i = 1; i < level_count; i++)
	{
		char level_delta = report[i] - report[i - 1];

		// Early break if level_delta is zero (no need to calculate gradient)
		if (level_delta == 0)
		{
			is_dampened = true;

			break;
		}

		// Assign gradient if not assigned
		if (gradient == 0)
		{
			gradient = level_delta > 0 ? 1 : -1;
		}

		// Map level_delta to a positive value
		if (gradient * level_delta < 1 || gradient * level_delta > 3)
		{
			is_dampened = true;

			break;
		}
	}
	
	if (is_dampened == true)
	{
		for (int i = 0; i < level_count; i++)
		{
			if (dampen_problem(report, level_count, i) == 2)
			{
				return 2;
			}
		}
		
		return 0;
	}

	return 1;
}

unsigned char read_report(FILE *file, unsigned char *report)
{
	size_t buf_size = ELEMS_MAX * 3 + 2;	// Mulitply by 3 for the spaces and the null character
						// Add 2 for the carriage return and new line
	char *buf = (char *)calloc(buf_size, sizeof(char));
	unsigned char size = 0;

	// Clear end of report
	for (unsigned char i = ELEMS_MAX - 1; i > ELEMS_MIN - 1; i--)
	{
		report[i] = 0;
	}

	// fgets reads until newline
	fgets(buf, buf_size, file);

	// strtok separates string into tokens delimited by " "
	char *token = strtok(buf, " ");

	while (token != NULL)
	{
		report[size++] = (unsigned char)atoi(token);
		token = strtok(NULL, " ");	// Additional calls to strtok return the next token
	}

	free(buf);

	return size;
}

void solve_day2()
{
	FILE *file = fopen(INPUT_FILE, "r");
	if (file == NULL)
	{
		perror("No input2.txt file found");
		return;
	}

	unsigned char *report = (unsigned char *)malloc(ELEMS_MAX * sizeof(unsigned char));
	int safe_reports[2] = {0};

	for (int i = 0; i < LINES; i++)
	{
		unsigned char levels = read_report(file, report);
		unsigned char safety_status = check_safety(report, levels);

		switch (safety_status)
		{
			case 1:
				safe_reports[0]++;
				// Fall through intended
			case 2:
				safe_reports[1]++;
				break;
			default:
				break;
		}
	}

	fclose(file);

	free(report);

	int part1_result = safe_reports[0];
	int part2_result = safe_reports[1];

	printf("Result for Day 2, Part 1: %d\n", part1_result);
	printf("Result for Day 2, Part 2: %d\n", part2_result);
}
