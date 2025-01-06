#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "day2.h"

void is_safe_with_dampener(int *report, int level_count, int *safe count, int *problem_is_dampened)
{
	if (*problem_is_dampened == 0)
	{
		*problem_is_dampened = 1;
	}

	for (int i = 0; i < level_count; i++)
	{
		is_safe(report, level_count, safe_count, i);
	}
}

void is_safe(int *report, int level_count, int *safe_count, int ignored_index)
{
	int safe_flag_part1 = 1;
	int safe_flag_part2 = 1;
	int problem_is_dampened = 0;
	int gradient = 0;
	
	for (int i = 1; i < level_count; i++)
	{
		if (ignored_index == 0)
		{
			continue;
		}

		int level_delta = report[i] - report[i - 1];

		if (i == ignored_index)
		{
			level_delta = report[i + 1] - report[i - 1];
			i++;
		}

		if (level_delta == 0)
		{
			safe_flag_part1 = 0;

			if (problem_is_dampened == 0)
			{
				is_safe_with_dampener(report, level_count, safe_count, &problem_is_dampened);
			}

			break;
		}

		if (gradient == 0)
		{
			gradient = level_delta > 0 ? 1 : -1;
		}

		if ((gradient == -1 && level_delta >= -3 && level_delta < 0) || (gradient == 1 && level_delta <= 3 && level_delta > 0))
		{
			continue;
		}

		safe_flag_part1 = 0;

		if (problem_is_dampened == 0)
		{
			is_safe_with_dampener(report, level_count, safe_count, &problem_is_dampened);
		}

		break;
	}
	
	if (safe_flag_part1)
	{
		safe_count[0]++;
	}

	if (safe_flag_part2)
	{
		safe_count[1]++;
	}
}

int read_report(FILE *file, int **report, int *capacity)
{
	char buf[32];
	int size = 0;

	fgets(buf, sizeof(buf), file);
	printf("%s", buf);

	char *token = strtok(buf, " ");

	while (token != NULL)
	{
		if (size == *capacity)
		{
			*capacity *= 2;
			int *new_report = (int *)realloc(*report, *capacity * sizeof(int));
			if (new_report == NULL)
			{
				perror("Memory allocation failed.\n");
				free(*report);
				exit(1);
			}

			*report = new_report;
		}

		(*report)[size++] = atoi(token);
		token = strtok(NULL, " ");
	}

	return size;
}

void solve_day2()
{
	FILE *file = fopen(INPUT_FILE, "r");
	if (file == NULL)
	{
		perror("No input2.txt file found.\n");
		return;
	}

	int capacity = 5;
	int *report = (int *)malloc(capacity * sizeof(int));
	int *safe_count = (int *)calloc(2 * sizeof(int), sizeof(int));

	for (int i = 0; i < LINES; i++)
	{
		int level_count = read_report(file, &report, &capacity);
		is_safe(report, level_count, safe_count, -1);
	}

	fclose(file);

	int part1_result = safe_count[0];
	int part2_result = safe_count[1];

	free(report);
	report = NULL;
	free(safe_count);
	safe_count = NULL;

	printf("Result for Day 2, Part 1: %d\n", part1_result);
	printf("Result for Day 2, Part 2: %d\n", part2_result);
}
