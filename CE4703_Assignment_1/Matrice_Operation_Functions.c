/**
 * @file Matrice_Operations_Header.c
 * @brief Implementation of array manipulation operations including clearing, sorting, and shuffling
 *
 * This file provides functions for basic array operations that handle both used and unused elements.
 * Operations include clearing arrays, sorting used elements, and random shuffling while maintaining
 * the distinction between used and unused elements.
 */

#include "Matrice_Operations_Header.h"
#include "Main_Header.h" // linking the main header definitions
#include "Simple_Operations_Header.h" // linking the simple operations header definitions
#include <stdlib.h>
#include <stdio.h>

 /**
  * @brief Initializes all elements of the array to UNUSED_MARKER
  *
  * This function resets the entire array by setting every element to the UNUSED_MARKER value.
  * It effectively clears the array and marks all positions as available for new data.
  *
  * @param[in,out] array Array to be cleared/modified
  * @param[in] capacity Total number of elements in the array
  *
  * @return void
  *
  * @note This function modifies the array in-place
  *
  * @code
  * int myArray[10];
  * Clear_Array(myArray, 10); // All elements now set to UNUSED_MARKER
  * @endcode
  */
void Clear_Array(int array[], int capacity) {
    /**
     * @brief Iterate through all array elements and set to UNUSED_MARKER
     *
     * The loop traverses from index 0 to capacity-1, marking each position
     * as unused by assigning the UNUSED_MARKER constant.
     */
    for (int i = 0; i < capacity; i++) {
        array[i] = UNUSED_MARKER; /**< Set current element to unused state */
    }
}

/**
 * @brief Sorts used elements in ascending order using bubble sort algorithm
 *
 * This function performs an in-place sort of the array, but only considers elements
 * marked as USED. The sorting preserves the relative positions of unused elements
 * while arranging used elements in ascending order.
 *
 * @param[in,out] array Array to be sorted
 * @param[in] capacity Total number of elements in the array
 *
 * @return void
 *
 * @note Uses bubble sort algorithm with O(n²) time complexity
 * @note Only compares and swaps elements that are both marked as USED
 *
 * @code
 * int arr[5] = {5, UNUSED, 3, 1, UNUSED};
 * Sort_Array(arr, 5); // Result: {1, UNUSED, 3, 5, UNUSED}
 * @endcode
 */
void Sort_Array(int array[], int capacity) {
    int i, j, temp; /**< Loop counters and temporary swap variable */

    /**
     * @brief Outer loop for bubble sort passes
     *
     * Performs capacity-1 passes through the array to ensure
     * complete sorting of all used elements.
     */
    for (i = 0; i < capacity - 1; i++) {
        /**
         * @brief Inner loop for element comparisons
         *
         * Compares adjacent elements and swaps them if they are both used
         * and out of order. The range decreases with each outer loop iteration
         * as the largest elements bubble to their correct positions.
         */
        for (j = 0; j < capacity - i - 1; j++) {
            /**
             * @brief Condition for swapping elements
             *
             * Checks if both current and next elements are used AND
             * if the current element is greater than the next element,
             * indicating they need to be swapped for ascending order.
             */
            if (IS_USED(array[j]) && IS_USED(array[j + 1]) && array[j] > array[j + 1]) {
                temp = array[j]; /**< Store current element temporarily */
                array[j] = array[j + 1]; /**< Move next element to current position */
                array[j + 1] = temp; /**< Complete the swap */
            }
        }
    }
}

/**
 * @brief Randomly shuffles used elements while maintaining unused elements
 *
 * This function performs a random shuffle of the array elements by swapping
 * random positions. The shuffling affects all elements regardless of their
 * used/unused status, but the random nature may help redistribute used elements.
 *
 * @param[in,out] array Array to be shuffled
 * @param[in] capacity Total number of elements in the array
 *
 * @return void
 *
 * @note Uses Fisher-Yates inspired shuffling with random swap operations
 * @note The number of swaps is determined by a random value between 1 and capacity
 *
 * @code
 * int arr[5] = {1, 2, 3, UNUSED, 4};
 * Shuffle_Array(arr, 5); // Elements randomly rearranged
 * @endcode
 */
void Shuffle_Array(int array[], int capacity) {
    /**
     * @brief Determine number of random swaps to perform
     *
     * Generates a random number between 1 and capacity to determine
     * how many swap operations will be performed during shuffling.
     */
    int random_size = Random_int(1, capacity);

    /**
     * @brief Perform random swap operations
     *
     * Executes a series of random swaps where two random indices
     * are selected and their elements are exchanged. This creates
     * a randomized permutation of the array elements.
     */
    for (int i = 0; i < random_size; i++) {
        int rand_index1 = Random_int(0, capacity - 1); /**< First random index */
        int rand_index2 = Random_int(0, capacity - 1); /**< Second random index */

        /**
         * @brief Swap elements at random indices
         *
         * Standard three-variable swap operation to exchange
         * elements between two randomly selected positions.
         */
        int temp = array[rand_index1];
        array[rand_index1] = array[rand_index2];
        array[rand_index2] = temp;
    }
}