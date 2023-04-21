#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Read numbers from a file and store them in an array.
void read_data(FILE *file, float **data, int *size, int *capacity) {
    *size = 0;
    *capacity = 20;

    // Allocate memory for the array using the initial capacity.
    *data = (float *)malloc(*capacity * sizeof(float));

    // Keep reading numbers from the file until there are no more left.
    while (fscanf(file, "%f", &((*data)[*size])) != EOF) {
        (*size)++; // Increase the size of the array by 1.

        // If the array is full, double its capacity.
        if (*size == *capacity) {
            *capacity *= 2; // Double the capacity.
            
            // Allocate memory for a new, bigger array.
            float *new_data = (float *)malloc(*capacity * sizeof(float));
            
            // Copy the data from the old array to the new one.
            for (int i = 0; i < *size; i++) {
                new_data[i] = (*data)[i];
            }

             // Free the memory occupied by the old array.
            free(*data);
            
            // Make the new array the main array.
            *data = new_data;
        }
    }
}

// Calculate the average of the numbers in the array.
double mean(float *data, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum / size;
}

// Find the number that appears most often in the array, if there is none, return -1.
float mode(float *data, int size) {
    float mode = -1;
    int max_count = 0;

    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (data[j] == data[i]) {
                count++;
            }
        }

        if (count > max_count && count > 1) {
            max_count = count;
            mode = data[i];
        }
    }

    return mode;
}

// Calculate the geometric mean of the numbers in the array.
float geometric_mean(float *data, int size) {
    double product = 1;
    for (int i = 0; i < size; i++) {
        product *= data[i];
    }
    return pow(product, 1.0 / size);
}

// Calculate the harmonic mean of the numbers in the array.
float harmonic_mean(float *data, int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += 1.0 / data[i];
    }
    return size / sum;
}

// Compare two numbers to help sort the array.
int compare_float(const void *a, const void *b) {
    float fa = *(const float *)a;
    float fb = *(const float *)b;
    return (fa > fb) - (fa < fb);
}

// Find the middle value in the sorted array.
float median(float *data, int size) {
    qsort(data, size, sizeof(float), compare_float);

    if (size % 2 == 0) {
        return (data[size / 2 - 1] + data[size / 2]) / 2.0;
    } else {
        return data[size / 2];
    }
}

// Calculate stdev.
double standard_deviation(float *data, int size) {
    double avg = mean(data, size);
    double sum = 0;
    for (int i = 0; i < size; i++) {
        double diff = data[i] - avg;
        sum += diff * diff;
    }
    return sqrt(sum / size);
}

int main(int argc, char *argv[]) {
    // Check if the user provided a filename as an argument
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open the input file
    const char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return 1;
    }

    float *data; // Declare a pointer to hold the array.
    int size, capacity; // Declare variables to store the size and capacity.
    
    // Read data from the file and store it in the array.
    read_data(file, &data, &size, &capacity);
    fclose(file); // Close the file after reading.

    // Print data stats about the numbers in the array.
    printf("Number of values: %d\n", size);
    printf("Unused capacity: %d\n", capacity - size);
    printf("Mean: %f\n", mean(data, size));
    printf("Mode: %f\n", mode(data, size));
    printf("Geometric Mean: %f\n", geometric_mean(data, size));
    printf("Harmonic Mean: %f\n", harmonic_mean(data, size));
    printf("Median: %f\n", median(data, size));
    printf("Standard Deviation: %f\n", standard_deviation(data, size));

    free(data); // Free the memory occupied by the array.

    return 0;
}