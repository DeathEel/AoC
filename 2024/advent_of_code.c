#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <time.h>
#include <string.h>

#include "day1.h"
#include "day2.h"
#include "day3.h"
#include "day4.h"
#include "day5.h"
#include "day6.h"
#include "day7.h"
#include "day8.h"
#include "day9.h"
#include "day10.h"
#include "day11.h"
#include "day12.h"
#include "day13.h"
#include "day14.h"
#include "day15.h"
#include "day16.h"
#include "day17.h"
#include "day18.h"
#include "day19.h"
#include "day20.h"
#include "day21.h"
#include "day22.h"
#include "day23.h"
#include "day24.h"
#include "day25.h"

void solve_all_days()
{
	struct timespec start, end;

	clock_gettime(CLOCK_MONOTONIC, &start);

	solve_day1();
	solve_day2();
	solve_day3();
	solve_day4();
	solve_day5();
	solve_day6();
	solve_day7();
	solve_day8();
	solve_day9();
	solve_day10();
	solve_day11();
	solve_day12();
	solve_day13();
	solve_day14();
	solve_day15();
	solve_day16();
	solve_day17();
	solve_day18();
	solve_day19();
	solve_day20();
	solve_day21();
	solve_day22();
	solve_day23();
	solve_day24();
	solve_day25();

	clock_gettime(CLOCK_MONOTONIC, &end);

	printf("Total time taken for all days: %.6f ms\n", (double)((end.tv_sec - start.tv_sec) * 1e3 + (end.tv_nsec - start.tv_nsec) / 1e6));
}

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		printf("No day specified. Running all days...\n");
		solve_all_days();
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			struct timespec start, end;

			if (strcmp(argv[i], "1") == 0)
			{
				clock_gettime(CLOCK_MONOTONIC, &start);
				solve_day1();
				clock_gettime(CLOCK_MONOTONIC, &end);
				printf("Total time taken for Day 1: %.6f ms\n", (double)((end.tv_sec - start.tv_sec) * 1e3 + (end.tv_nsec - start.tv_nsec) / 1e6));
			}
			else if (strcmp(argv[i], "2") == 0)
			{
				clock_gettime(CLOCK_MONOTONIC, &start);
				solve_day2();
				clock_gettime(CLOCK_MONOTONIC, &end);
				printf("Total time taken for Day 2: %.6f ms\n", (double)((end.tv_sec - start.tv_sec) * 1e3 + (end.tv_nsec - start.tv_nsec) / 1e6));
			}
			else if (strcmp(argv[i], "3") == 0)
			{
				clock_gettime(CLOCK_MONOTONIC, &start);
				solve_day3();
				clock_gettime(CLOCK_MONOTONIC, &end);
				printf("Total time taken for Day 3: %.6f ms\n", (double)((end.tv_sec - start.tv_sec) * 1e3 + (end.tv_nsec - start.tv_nsec) / 1e6));
			}
			else if (strcmp(argv[i], "4") == 0)
			{
				clock_gettime(CLOCK_MONOTONIC, &start);
				solve_day4();
				clock_gettime(CLOCK_MONOTONIC, &end);
				printf("Total time taken for Day 4: %.6f ms\n", (double)((end.tv_sec - start.tv_sec) * 1e3 + (end.tv_nsec - start.tv_nsec) / 1e6));
			}
			else if (strcmp(argv[i], "5") == 0)
			{
				clock_gettime(CLOCK_MONOTONIC, &start);
				solve_day5();
				clock_gettime(CLOCK_MONOTONIC, &end);
				printf("Total time taken for Day 5: %.6f ms\n", (double)((end.tv_sec - start.tv_sec) * 1e3 + (end.tv_nsec - start.tv_nsec) / 1e6));
			}
			else if (strcmp(argv[i], "6") == 0)
			{
				clock_gettime(CLOCK_MONOTONIC, &start);
				solve_day6();
				clock_gettime(CLOCK_MONOTONIC, &end);
				printf("Total time taken for Day 6: %.6f ms\n", (double)((end.tv_sec - start.tv_sec) * 1e3 + (end.tv_nsec - start.tv_nsec) / 1e6));
			}
			else if (strcmp(argv[i], "7") == 0)
			{
				clock_gettime(CLOCK_MONOTONIC, &start);
				solve_day7();
				clock_gettime(CLOCK_MONOTONIC, &end);
				printf("Total time taken for Day 7: %.6f ms\n", (double)((end.tv_sec - start.tv_sec) * 1e3 + (end.tv_nsec - start.tv_nsec) / 1e6));
			}
			else if (strcmp(argv[i], "8") == 0)
			{
				clock_gettime(CLOCK_MONOTONIC, &start);
				solve_day8();
				clock_gettime(CLOCK_MONOTONIC, &end);
				printf("Total time taken for Day 8: %.6f ms\n", (double)((end.tv_sec - start.tv_sec) * 1e3 + (end.tv_nsec - start.tv_nsec) / 1e6));
			}
			else if (strcmp(argv[i], "9") == 0)
			{
				clock_gettime(CLOCK_MONOTONIC, &start);
				solve_day9();
				clock_gettime(CLOCK_MONOTONIC, &end);
				printf("Total time taken for Day 9: %.6f ms\n", (double)((end.tv_sec - start.tv_sec) * 1e3 + (end.tv_nsec - start.tv_nsec) / 1e6));
			}
			else if (strcmp(argv[i], "10") == 0)
			{
				clock_gettime(CLOCK_MONOTONIC, &start);
				solve_day10();
				clock_gettime(CLOCK_MONOTONIC, &end);
				printf("Total time taken for Day 10: %.6f ms\n", (double)((end.tv_sec - start.tv_sec) * 1e3 + (end.tv_nsec - start.tv_nsec) / 1e6));
			}
			else if (strcmp(argv[i], "11") == 0)
			{
				clock_gettime(CLOCK_MONOTONIC, &start);
				solve_day11();
				clock_gettime(CLOCK_MONOTONIC, &end);
				printf("Total time taken for Day 11: %.6f ms\n", (double)((end.tv_sec - start.tv_sec) * 1e3 + (end.tv_nsec - start.tv_nsec) / 1e6));
			}
			else if (strcmp(argv[i], "12") == 0)
			{
				clock_gettime(CLOCK_MONOTONIC, &start);
				solve_day12();
				clock_gettime(CLOCK_MONOTONIC, &end);
				printf("Total time taken for Day 12: %.6f ms\n", (double)((end.tv_sec - start.tv_sec) * 1e3 + (end.tv_nsec - start.tv_nsec) / 1e6));
			}
			else if (strcmp(argv[i], "13") == 0)
			{
				clock_gettime(CLOCK_MONOTONIC, &start);
				solve_day13();
				clock_gettime(CLOCK_MONOTONIC, &end);
				printf("Total time taken for Day 13: %.6f ms\n", (double)((end.tv_sec - start.tv_sec) * 1e3 + (end.tv_nsec - start.tv_nsec) / 1e6));
			}
			else if (strcmp(argv[i], "14") == 0)
			{
				clock_gettime(CLOCK_MONOTONIC, &start);
				solve_day14();
				clock_gettime(CLOCK_MONOTONIC, &end);
				printf("Total time taken for Day 14: %.6f ms\n", (double)((end.tv_sec - start.tv_sec) * 1e3 + (end.tv_nsec - start.tv_nsec) / 1e6));
			}
			else if (strcmp(argv[i], "15") == 0)
			{
				clock_gettime(CLOCK_MONOTONIC, &start);
				solve_day15();
				clock_gettime(CLOCK_MONOTONIC, &end);
				printf("Total time taken for Day 15: %.6f ms\n", (double)((end.tv_sec - start.tv_sec) * 1e3 + (end.tv_nsec - start.tv_nsec) / 1e6));
			}
			else if (strcmp(argv[i], "16") == 0)
			{
				clock_gettime(CLOCK_MONOTONIC, &start);
				solve_day16();
				clock_gettime(CLOCK_MONOTONIC, &end);
				printf("Total time taken for Day 16: %.6f ms\n", (double)((end.tv_sec - start.tv_sec) * 1e3 + (end.tv_nsec - start.tv_nsec) / 1e6));
			}
			else if (strcmp(argv[i], "17") == 0)
			{
				clock_gettime(CLOCK_MONOTONIC, &start);
				solve_day17();
				clock_gettime(CLOCK_MONOTONIC, &end);
				printf("Total time taken for Day 17: %.6f ms\n", (double)((end.tv_sec - start.tv_sec) * 1e3 + (end.tv_nsec - start.tv_nsec) / 1e6));
			}
			else if (strcmp(argv[i], "18") == 0)
			{
				clock_gettime(CLOCK_MONOTONIC, &start);
				solve_day18();
				clock_gettime(CLOCK_MONOTONIC, &end);
				printf("Total time taken for Day 18: %.6f ms\n", (double)((end.tv_sec - start.tv_sec) * 1e3 + (end.tv_nsec - start.tv_nsec) / 1e6));
			}
			else if (strcmp(argv[i], "19") == 0)
			{
				clock_gettime(CLOCK_MONOTONIC, &start);
				solve_day19();
				clock_gettime(CLOCK_MONOTONIC, &end);
				printf("Total time taken for Day 19: %.6f ms\n", (double)((end.tv_sec - start.tv_sec) * 1e3 + (end.tv_nsec - start.tv_nsec) / 1e6));
			}
			else if (strcmp(argv[i], "20") == 0)
			{
				clock_gettime(CLOCK_MONOTONIC, &start);
				solve_day20();
				clock_gettime(CLOCK_MONOTONIC, &end);
				printf("Total time taken for Day 20: %.6f ms\n", (double)((end.tv_sec - start.tv_sec) * 1e3 + (end.tv_nsec - start.tv_nsec) / 1e6));
			}
			else if (strcmp(argv[i], "21") == 0)
			{
				clock_gettime(CLOCK_MONOTONIC, &start);
				solve_day21();
				clock_gettime(CLOCK_MONOTONIC, &end);
				printf("Total time taken for Day 21: %.6f ms\n", (double)((end.tv_sec - start.tv_sec) * 1e3 + (end.tv_nsec - start.tv_nsec) / 1e6));
			}
			else if (strcmp(argv[i], "22") == 0)
			{
				clock_gettime(CLOCK_MONOTONIC, &start);
				solve_day22();
				clock_gettime(CLOCK_MONOTONIC, &end);
				printf("Total time taken for Day 22: %.6f ms\n", (double)((end.tv_sec - start.tv_sec) * 1e3 + (end.tv_nsec - start.tv_nsec) / 1e6));
			}
			else if (strcmp(argv[i], "23") == 0)
			{
				clock_gettime(CLOCK_MONOTONIC, &start);
				solve_day23();
				clock_gettime(CLOCK_MONOTONIC, &end);
				printf("Total time taken for Day 23: %.6f ms\n", (double)((end.tv_sec - start.tv_sec) * 1e3 + (end.tv_nsec - start.tv_nsec) / 1e6));
			}
			else if (strcmp(argv[i], "24") == 0)
			{
				clock_gettime(CLOCK_MONOTONIC, &start);
				solve_day24();
				clock_gettime(CLOCK_MONOTONIC, &end);
				printf("Total time taken for Day 24: %.6f ms\n", (double)((end.tv_sec - start.tv_sec) * 1e3 + (end.tv_nsec - start.tv_nsec) / 1e6));
			}
			else if (strcmp(argv[i], "25") == 0)
			{
				clock_gettime(CLOCK_MONOTONIC, &start);
				solve_day25();
				clock_gettime(CLOCK_MONOTONIC, &end);
				printf("Total time taken for Day 25: %.6f ms\n", (double)((end.tv_sec - start.tv_sec) * 1e3 + (end.tv_nsec - start.tv_nsec) / 1e6));
			}
			else
			{
				printf("Unknown argument: %s\n", argv[i]);
				return 1;
			}
		}
	}

	return 0;
}
