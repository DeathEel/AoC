#include <stdio.h>
#include <stdlib.h>
#include "day1.h"

int compare(const void *p, const void *q)
{
	return (*(int *)p - *(int *)q);
}

void solve_day1()
{
	FILE *file = fopen(INPUT_FILE, "r");
	if (file == NULL)
	{
		perror("No input1.txt file found.\n");
		return;
	}

	int left[LINES];
	int right[LINES];
	int buf;
	int count = 0;

	while (fscanf(file, "%d", &buf) == 1)
	{
		if (count % 2)
		{
			left[count / 2] = buf;
		}
		else
		{
			right[count / 2] = buf;
		}
		count++;
	}
	
	fclose(file);

	qsort(left, LINES, sizeof(int), compare);
	qsort(right, LINES, sizeof(int), compare);

	int total_diff = 0;

	for (int i = 0; i < LINES; i++)
	{
		total_diff += abs(left[i] - right[i]);
	}

	int sim_score = 0, j_keep = 0;

	for (int i = 0; i < LINES; i++)
	{
		if (j_keep == LINES)
		{
			break;
		}

		for (int j = j_keep; j < LINES; j++)
		{
			if (left[i] == right[j])
			{
				sim_score += left[i];
			}
			else if (left[i] < right[j])
			{
				break;
			}
			else
			{
				j_keep++;
			}
		}
	}

	printf("Result for Day 1, Part 1: %d\n", total_diff);
	printf("Result for Day 1, Part 2: %d\n", sim_score);
}
