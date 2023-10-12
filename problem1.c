'''
Zachary Willingham
zwillingham04@ku.edu
10/13/2023
Lab 5 Problem 1

The programming lab assignment requires 12 monthly sales to be read and a sales report to be generated. The report should include (1) a title for the report, (2) a tabular report of the month and sales in two columns, one for the month (January, February, etc.) and one for the corresponding sales, (2) the sales summary, e.g., month with the lowest sales, month with the highest sales, and the average sales, (3) a six-month moving average also in a tabular format, and finally (4) a tabular listing of months and sales with the sales from the highest to the lowest.
'''
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> // Include math.h for math functions

// Function to calculate the average of a list of floats
float average(float list[], int size) {
    float total = 0;
    for (int i = 0; i < size; i++) {
        total += list[i];
    }
    return total / size; // Return the average
}

// Function to find the index of the maximum value in a list of floats
int get_max(float list[], int size) {
    int cur_max = 0;
    for (int i = 1; i < size; i++) {
        if (list[i] > list[cur_max]) {
            cur_max = i;
        }
    }
    return cur_max; // Return the index of the maximum value
}

// Function to find the index of the minimum value in a list of floats
int get_min(float list[], int size) {
    int cur_min = 0;
    for (int i = 1; i < size; i++) {
        if (list[i] < list[cur_min]) {
            cur_min = i;
        }
    }
    return cur_min; // Return the index of the minimum value
}

// Comparison function for qsort to sort floats in descending order
int compare(const void *a, const void *b) {
    return (*(float *)b - *(float *)a);
}

// Function to find the index of a specific value in a list of floats
int find_index(float list[], float value) {
    for (int i = 0; i < 12; i++) {
        if (list[i] == value) {
            return i;
        }
    }
    return -1;  // Value not found, return -1
}

int main() {
    // Array of sales and corresponding month names
    float sales[] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22};
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    // Printing the monthly sales report for 2022
    printf("Monthly sales report for 2022:\n");
    printf("Month       Sales\n");
    for (int i = 0; i < 12; i++) {
        printf("%-10s $%.2f\n", months[i], sales[i]); // Printing month names and corresponding sales values
    }
    printf("\n");

    // Finding the indices of minimum and maximum sales values
    int min_index = get_min(sales, 12);
    int max_index = get_max(sales, 12);

    // Printing sales summary including minimum, maximum, and average sales
    printf("Sales summary:\n");
    printf("Minimum sales:    $%-10.2f (%s)\n", sales[min_index], months[min_index]);
    printf("Maximum sales:    $%-10.2f (%s)\n", sales[max_index], months[max_index]);
    printf("Average sales:    $%.2f\n\n", average(sales, 12));

    // Printing six-month moving average report
    printf("Six-Month Moving Average Report:\n");
    int count = 0;
    for (int i = 0; i < 7; i++) {
        printf("%-10s - %-10s $%.2f\n", months[count], months[count + 5], average(sales + count, 6)); // Printing moving average for every six months
        count++;
    }

    // Sorting sales in descending order and printing the sales report
    printf("\nSales Report (Highest to Lowest):\n");
    printf("Month       Sales\n");
    float ordered_sales[12];
    memcpy(ordered_sales, sales, sizeof(sales));
    qsort(ordered_sales, 12, sizeof(float), compare); // Sorting sales array in descending order
    for (int i = 0; i < 12; i++) {
        printf("%-10s $%.2f\n", months[find_index(sales, ordered_sales[i])], ordered_sales[i]); // Printing sorted sales report
    }

    return 0; // Indicating successful execution of the program
}