/**
 * @file Submain.c
 * @brief Implementation of array operations module
 *
 * This file contains implementations of various array operations including
 * random number generation, input handling, array manipulation, and analysis.
 * Each function performs specific operations on arrays with support for
 * used/unused element tracking.
 */

#include "Simple_Operations_Header.h" // linking the header definitions to 
#include "Main_Header.h" // linking the main header definitions
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

 /**
  * @brief Generates a random integer within specified range
  *
  * Uses standard rand() function to generate a pseudo-random number
  * between min and max (inclusive). The range is calculated using
  * modulo arithmetic to ensure uniform distribution within bounds.
  *
  * @param[in] min Minimum value of range (inclusive)
  * @param[in] max Maximum value of range (inclusive)
  * @return int Random integer in the range [min, max]
  *
  * @note Requires srand() to be called elsewhere for proper randomization
  * @warning Max must be greater than or equal to min
  */
int Random_int(int min, int max) {
    int random_num = min + rand() % (max - min + 1); /**< Generate random number in range */
    return random_num;
}

/**
 * @brief Reads non-negative integers from user input into array
 *
 * Continuously reads integer values from standard input until either
 * capacity is reached or a negative number is entered. Negative input
 * triggers early termination and remaining elements are marked unused.
 *
 * @param[out] array Array to store input values
 * @param[in] capacity Maximum number of elements to read
 *
 * @return void
 *
 * @note Uses scanf_s for secure input reading
 * @warning Input buffer should be cleared before calling this function
 */
void Keyboard_Input(int array[], int capacity) {
    int i;
    int input;
    printf("Enter up to %d non-negative integers (negative to stop):\n", capacity);
    for (i = 0; i < capacity; i++) {
        scanf_s("%d", &input);
        if (input < 0) {
            array[i] = UNUSED_MARKER; /**< Mark current position as unused */
            break;
        }
        array[i] = input; /**< Store valid input in array */
    }
}

/**
 * @brief Fills array with random numbers and marks unused positions
 *
 * Populates the first 'size' elements with random numbers within specified
 * range, and marks remaining positions up to capacity as unused.
 *
 * @param[out] array Array to be filled
 * @param[in] size Number of elements to fill with random values
 * @param[in] capacity Total capacity of the array
 * @param[in] min Minimum value for random numbers (inclusive)
 * @param[in] max Maximum value for random numbers (inclusive)
 *
 * @return void
 *
 * @see Random_int()
 */
void Array_Random(int array[], int size, int capacity, int min, int max) {
    int random_number = Random_int(min, max);
    /** Fill first 'size' elements with random numbers */
    for (int i = 0; i < size; i++) {
        array[i] = Random_int(min, max); /**< Assign random value to current index */
    }
    /** Mark remaining elements as unused */
    for (int j = size; j < capacity; j++) {
        if (j >= size) {
            array[j] = UNUSED_MARKER; /**< Set unused marker for remaining positions */
        }
    }
}

/**
 * @brief Prints only the used elements of the array
 *
 * Iterates through the array and displays only elements that are
 * marked as used, skipping unused elements entirely.
 *
 * @param[in] array Array to display
 * @param[in] capacity Total number of elements in array
 *
 * @return void
 *
 * @note Uses IS_USED macro to determine element status
 */
void Print_Used(int array[], int capacity) {
    for (int i = 0; i < capacity; i++) {
        if (IS_USED(array[i])) {
            printf("\nArray[%d] | %d", i, array[i]); /**< Display used element */
        }
    }
}

/**
 * @brief Prints all elements of the array including unused markers
 *
 * Displays every element in the array regardless of usage status,
 * showing both index and value for complete array representation.
 *
 * @param[in,out] array Array to display (may be modified for consistency)
 * @param[in] capacity Total number of elements in array
 *
 * @return void
 *
 * @note Ensures unused elements are properly marked before printing
 */
void Print_All(int array[], int capacity) {
    for (int i = 0; i < capacity; i++) {
        if (array[i] < 1) {
            array[i] = UNUSED_MARKER; /**< Ensure proper unused marking */
        }
        printf("\nArray[%d] | %d", i, array[i]); /**< Display all elements */
    }
}

/**
 * @brief Finds the minimum value among used elements in the array
 *
 * Scans through the array to locate the smallest value considering
 * only elements marked as used. Excludes unused and negative markers.
 *
 * @param[in] array Array to search
 * @param[in] capacity Total number of elements in array
 * @return int Minimum value found among used elements
 *
 * @note Returns first element if no valid minimum is found
 */
int Find_Min(int array[], int capacity) {
    int min = array[0]; /**< Initialize with first element */
    for (int i = 1; i < capacity; i++) {
        if ((array[i] < min) && array[i] > -1) {
            min = array[i]; /**< Update minimum when smaller valid value found */
        }
    }
    return min;
}

/**
 * @brief Finds the maximum value among used elements in the array
 *
 * Scans through the array to locate the largest value considering
 * all elements regardless of usage status.
 *
 * @param[in] array Array to search
 * @param[in] capacity Total number of elements in array
 * @return int Maximum value found in the array
 *
 * @note Returns first element if no larger value is found
 */
int Find_Max(int array[], int capacity) {
    int max = array[0]; /**< Initialize with first element */
    for (int i = 1; i < capacity; i++) {
        if (array[i] > max) {
            max = array[i]; /**< Update maximum when larger value found */
        }
    }
    return max;
}

/**
 * @brief Counts the number of used elements in the array
 *
 * Iterates through the entire array and counts how many elements
 * are marked as used using the IS_USED macro.
 *
 * @param[in] array Array to analyze
 * @param[in] capacity Total number of elements in array
 * @return int Number of used elements in the array
 *
 * @see IS_USED
 */
int Num_of_Used_Elements(int array[], int capacity) {
    int count = 0; /**< Counter for used elements */
    for (int x = 0; x < capacity; x++) {
        if (IS_USED(array[x])) {
            count++; /**< Increment counter for each used element */
        }
    }
    return count;
}



