# Statistical 

This program reads a file containing a list of floating-point numbers and calculates various statistical measures, such as the mean, mode, geometric mean, harmonic mean, median, and standard deviation.

## Requirements

- A C compiler (e.g., GCC)

## Compilation

To compile the program, open a terminal and navigate to the directory containing the source file `basicstats.c `. Then run the following command:

gcc basicstats.c -o basicstats -lm

This command compiles the source file `basicstats.c` and creates an executable file called `stats`. The `-lm` flag is used to link the math library.

## Usage

To run the program, use the following command:

'basicstats <filename>'

Replace `<filename>` with the name of the file containing the list of floating-point numbers you want to analyze. The numbers in the file should be separated by whitespace or newlines.

For example, if the file is named `data.txt`, run the following command:

'basicstats test.txt'

The program will read the data from the file and print the calculated statistical measures.

## Example

Suppose the file `data.txt` contains the following numbers:

5.5
2.3
7.1
3.6

Running `./stats data.txt` will produce the following output:

Number of values: 4
Unused capacity: 16
Mean: 4.625000
Mode: -1.000000
Geometric Mean: 4.029516
Harmonic Mean: 3.610869
Median: 4.550000
Standard Deviation: 1.854814

