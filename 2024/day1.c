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
		perror("No input1.txt file found");
		return;
	}

	int left[LINES];
	int right[LINES];
	int location;
	int count = 0;

	// Append location to left and right
	while (fscanf(file, "%d", &location) == 1)
	{
		if (count % 2)
		{
			left[count / 2] = location;
		}
		else
		{
			right[count / 2] = location;
		}
		count++;
	}
	
	fclose(file);

	// Sort arrays
	qsort(left, LINES, sizeof(int), compare);
	qsort(right, LINES, sizeof(int), compare);

	int total_diff = 0;

	for (int i = 0; i < LINES; i++)
	{
		total_diff += abs(left[i] - right[i]);
	}

	int sim_score = 0;
	int j_keep = 0;	// j_keep eliminates need to check backwards (lower-value locations)

	for (int i = 0; i < LINES; i++)
	{
		if (j_keep == LINES)
		{
			break;
		}

		for (int j = j_keep; j < LINES; j++)
		{
			// Add similar locations to sim_score
			if (left[i] == right[j])
			{
				sim_score += left[i];
			}
			// Stop when right passes left
			else if (left[i] < right[j])
			{
				break;
			}
			// Increase j_keep to keep track of right progress
			else
			{
				j_keep++;
			}
		}
	}

	printf("Result for Day 1, Part 1: %d\n", total_diff);
	printf("Result for Day 1, Part 2: %d\n", sim_score);
}
