/**
 * @file Maths_Operations_Header.c
 * @brief Implementation of mathematical operations for array analysis
 *
 * This file contains implementations of various mathematical operations
 * including mean, median, variance, and standard deviation calculations
 * for arrays with used/unused element tracking.
 */

#include "Maths_Operations_Header.h" // linking the header definitions
#include "Main_Header.h" // linking the main header definitions
#include <stdlib.h>
#include <stdio.h>
#include <math.h> // including native c header for math functions

 /**
  * @brief Calculates the arithmetic mean of used elements in the array
  *
  * Computes the average value by summing all used elements and dividing
  * by the count of used elements. Only elements marked as USED contribute
  * to the calculation.
  *
  * @param[in] array Array of integers to process
  * @param[in] capacity Total number of elements in the array
  * @return double Arithmetic mean of used elements, 0 if no used elements
  *
  * @note Uses IS_USED macro to determine which elements contribute to calculation
  *
  * @code
  * int arr[5] = {10, UNUSED, 20, 30, UNUSED};
  * double avg = Mean_Average(arr, 5); // Returns 20.0
  * @endcode
  */
double Mean_Average(int array[], int capacity) {
    double sum = 0.0; /**< Accumulator for sum of used elements */
    double count = 0.0; /**< Counter for number of used elements */

    for (int i = 0; i < capacity; i++) {
        if (IS_USED(array[i])) {
            sum += array[i]; /**< Add element value to running sum */
            count++; /**< Increment used element counter */
        }
    }

    /* Handle case with no used elements to prevent division by zero */
    if (count == 0) {
        return 0;
    }

    double average = sum / count; /**< Calculate mean average */
    return average; /**< Return computed average value */
}

/**
 * @brief Calculates the median value of used elements in the array
 *
 * Determines the median value by finding the middle element(s) in what
 * should be a sorted array. For even-sized arrays, returns the average
 * of the two middle values.
 *
 * @param[in] array Array of integers to process (should be sorted)
 * @param[in] capacity Total number of elements in the array
 * @return int Median value of used elements
 *
 * @note Assumes the input array is sorted in ascending order
 *
 * @todo Fix implementation to properly handle used elements and sorting
 */
int Median_Average(int array[], int capacity) {
    int median = 0; /**< Variable to store median result */

    for (int i = 0; i < capacity; i++) {
        if (IS_USED(array[i])) {
            /* Check if total capacity is even */
            if (capacity % 2 == 0) {
                int mid1 = capacity / 2 - 1; /**< First middle index */
                int mid2 = capacity / 2; /**< Second middle index */
                int median = (array[mid1] + array[mid2]) / 2; /**< Average of two middle values */
                return median;
            }
            /* Handle odd-sized arrays */
            else {
                int mid = (capacity + 1) / 2; /**< Middle index for odd count */
                return array[mid]; /**< Direct middle value */
            }
        }
    }
    return median; /**< Return median (default 0 if no used elements) */
}

/**
 * @brief Calculates the population variance of used elements
 *
 * Computes variance using the formula sumof(ni-avg)^2 / N
 * where avg is the mean and N is the count of used elements.
 *
 * @param[in] array Array of integers to process
 * @param[in] capacity Total number of elements in the array
 * @return double Variance of used elements
 *
 * @note Uses Mean_Average() function to obtain the mean value
 *
 * @bug Variance calculation logic needs review and correction
 */
double Variance(int array[], int capacity) {
    double count = 0; /**< Counter for number of used elements */
    double sum = 0.0; /**< Accumulator for sum of used elements */
    double average = Mean_Average(array, capacity); /**< Mean value from Mean_Average() */

    for (int i = 0; i < capacity; i++) {
        if (IS_USED(array[i])) {
            count += 1.0; /**< Increment used element counter */
            sum += array[i]; /**< Add to sum of elements */
        }
    }

    /* Calculate variance using population formula */
    double variance = ((sum) * (sum)) / (count); /**< Variance calculation */
    return variance; /**< Return computed variance */
}

/**
 * @brief Calculates the standard deviation of used elements
 *
 * Computes standard deviation as the square root of variance.
 * Standard deviation measures the dispersion of data points
 * from the mean.
 *
 * @param[in] array Array of integers to process
 * @param[in] capacity Total number of elements in the array
 * @return double Standard deviation of used elements
 *
 * @note Uses Variance() function and sqrt() from math.h
 *
 * @code
 * int arr[4] = {10, 20, 30, 40};
 * double std_dev = Standard_Deviation(arr, 4);
 * @endcode
 */
double Standard_Deviation(int array[], int capacity) {
    double variance = Variance(array, capacity); /**< Get variance from Variance() */
    double standard_deviation = sqrt(variance); /**< Calculate square root of variance */
    return standard_deviation; /**< Return standard deviation */
}

