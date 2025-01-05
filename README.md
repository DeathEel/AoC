# Advent of Code
This project contains solutions for Advent of Code problems in C.

## Table of Contents
- [File Organization](#file-organization)
- [Installation](#installation)
- [Usage](#usage)

## File Organization
Each year has its own directory named `yyyy`.
Each year has a dedicated `inputs` directory to drop all input files. They are named `input#.txt`.
Each day has a header file named `day#.h` and a source file named `day#.c`.
Each year has a Makefile to compile all of the solutions together.

## Installation
1. Clone the repository:
```bash
git clone https://github.com/DeathEel/AoC.git
cd AoC
```

## Usage
1. Change the directory to the year desired.
```bash
cd 2024
```

2. Download the inputs from [Advent of Code](https://adventofcode.com/) to a `.txt` file and move them to the `inputs` directory.

3. Run the Makefile to generate the binary file.
```bash
make
```

4. Run the binary file for all days or for particular days.
```bash
./advent_of_code  # for all days
```
```bash
./advent_of_code 1 2 3  # for days 1, 2, and 3
```
