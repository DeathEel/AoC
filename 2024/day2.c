#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "day2.h"

int dampen_problem(int *problem_dampened, int *safe_flag_part1, int *safe_flag_part2)
{
	*safe_flag_part1 = 0;

	if (*problem_dampened == 0)
	{
		printf("Problem dampened.\n");
		*problem_dampened = 1;
		return 1;
	}

	if (*problem_dampened == 2)
	{
		return 1;
	}

	*safe_flag_part2 = 0;

	return 0;
}

void get_safe_count(int *report, int level_count, int *safe_count)
{
	int safe_flag_part1 = 1, safe_flag_part2 = 1, problem_dampened = 0, gradient = 0;
	int report_temp;

	for (int i = 1; i < level_count; i++)
	{
		if (problem_dampened == 2)
		{
			i = 2;
			report[i - 1] = report_temp;
			problem_dampened++;
			gradient = 0;
			printf("Swap levels.\n");
		}

		if (problem_dampened == 1)
		{
			if (report[i - 1] != report[i - 2])
			{
				report_temp = report[i - 1];
				report[i - 1] = report[i - 2];
			}
			else
			{
				problem_dampened = 3;
			}

			if (i == 2)
			{
				printf("Error in first 2 levels.\n");
				problem_dampened++;
				gradient = 0;
			}
		}

		int level_delta = report[i] - report[i - 1];

		if (level_delta == 0)
		{
			printf("Levels are same.\n");
			if (dampen_problem(&problem_dampened, &safe_flag_part1, &safe_flag_part2) == 1)
			{
				continue;
			}
			else
			{
				break;
			}
			
		}

		if (gradient == 0)
		{
			gradient = level_delta > 0 ? 1 : -1;
		}

		if ((gradient == -1 && level_delta >= -3 && level_delta < 0) || (gradient == 1 && level_delta <= 3 && level_delta > 0))
		{
			continue;
		}

		printf("level_delta is %d.\ngradient is %d.\n", level_delta, gradient);

		if (dampen_problem(&problem_dampened, &safe_flag_part1, &safe_flag_part2) == 1)
		{
			continue;
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

	printf("%d %d %d %d\n\n", safe_flag_part1, safe_flag_part2, safe_count[0], safe_count[1]);
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
		get_safe_count(report, level_count, safe_count);
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
