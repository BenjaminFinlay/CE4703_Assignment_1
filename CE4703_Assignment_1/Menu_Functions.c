/**
 * @file Menu_Functions.c
 * @brief Implementation of menu functions for array operations demonstration
 *
 * This file contains three menu functions that demonstrate various array operations
 * including random generation, sorting, shuffling, and statistical calculations.
 */

#include "Menu_Header.h" // links to menu header file
#include "Simple_Operations_Header.h" // links to main header file
#include "Maths_Operations_Header.h" // links to maths header file
#include "Matrice_Operations_Header.h" // links to matrice header file
#include <stdlib.h>
#include <stdio.h>

 /**
  * @brief Menu Function 1 - Demonstrates basic array operations with capacity 10
  *
  * This function showcases a sequence of array operations including:
  * - Random number generation with WF3
  * - Array printing with WF7 and WF8
  * - Array clearing with WF4
  * - Array sorting with WF5
  * - Finding maximum and minimum values
  *
  * @param[in,out] array Array to operate on
  * @param[in] capacity Capacity of the array (10 for this function)
  * @return int Always returns 0 indicating successful execution
  *
  * @note Uses capacity of 10 as defined by capacity1 constant
  * @see Array_Random(), Print_Used(), Print_All(), Clear_Array(), Sort_Array(), Find_Max(), Find_Min()
  */
int MF1(int array[], int capacity) {
    printf("\n\n----------------------------- Menu Function 1 ----------------------------- \n");

    /** Fill array with 7 random numbers in range 10 to 20 using WF3 */
    printf("WF3 Fill array with 7 random numbers in range 10 to 20 :");
    Array_Random(array, 7, capacity, 10, 20);

    /** Print used elements using WF7 */
    printf("\n\nWF7 Print used elements of the array :");
    Print_Used(array, capacity);

    /** Print all elements using WF8 */
    printf("\n\nWF8 Print all elements in array :");
    Print_All(array, capacity);

    /** Clear the array using WF4 */
    printf("\n\nWF4 Clear the arrays :");
    Clear_Array(array, capacity);

    /** Print used elements after clearing using WF7 */
    printf("\n\nWF7 Print used elements of the array after clearing :");
    Print_Used(array, capacity);

    /** Print all elements after clearing using WF8 */
    printf("\n\nWF8 Print all elements in array after clearing :");
    Print_All(array, capacity);

    /** Fill array with 5 random numbers in range 20 to 30 using WF3 */
    printf("\n\nWF3 Fill array with 5 random numbers in range 20 to 30 :");
    Array_Random(array, 5, capacity, 20, 30);

    /** Sort array using WF5 */
    printf("\n\nWF5 to sort array :");
    Sort_Array(array, capacity);

    /** Print all elements after sorting using WF8 */
    printf("\n\nWF8 Print all elements in array :");
    Print_All(array, capacity);

    /** Display maximum and minimum values in the array */
    printf("\n\nThe max and min values in the array are [%d] and [%d]", Find_Max(array, capacity), Find_Min(array, capacity));

    return 0;
}

/**
 * @brief Menu Function 2 - Demonstrates array manipulation operations with capacity 20
 *
 * This function demonstrates array manipulation including:
 * - Random number generation with WF3
 * - Array sorting with WF5
 * - Array shuffling with WF6
 * - Multiple array printing operations
 *
 * @param[in,out] array Array to operate on
 * @param[in] capacity Capacity of the array (20 for this function)
 * @return int Always returns 0 indicating successful execution
 *
 * @note Uses capacity of 20 as defined by capacity2 constant
 * @see Array_Random(), Print_All(), Sort_Array(), Shuffle_Array()
 */
int MF2(int array[], int capacity) {
    printf("\n\n----------------------------- Menu Function 2 ----------------------------- \n");

    /** Fill array with 15 random numbers between 10 and 20 using WF3 */
    printf("Wf3 to fill array with 15 random numbers between 10 and 20");
    Array_Random(array, 15, capacity, 10, 20);

    /** Print all elements using WF8 */
    printf("\n\nWF8 Print all elements in array : ");
    Print_All(array, capacity);

    /** Sort array using WF5 */
    printf("\n\nWF5 to sort array : ");
    Sort_Array(array, capacity);

    /** Print all elements after sorting using WF8 */
    printf("\n\nWF8 Print all elements in array : ");
    Print_All(array, capacity);

    /** Randomize array using WF6 */
    printf("\n\nWF6 to randomize array : ");
    Shuffle_Array(array, capacity);

    /** Print all elements after shuffling using WF8 */
    printf("\n\nWF8 to print all elements : ");
    Print_All(array, capacity);

    return 0;
}

/**
 * @brief Menu Function 3 - Demonstrates statistical operations with capacity 100
 *
 * This function focuses on statistical calculations including:
 * - Keyboard input with WF2
 * - Maximum and minimum value detection
 * - Mean and median calculations
 * - Variance and standard deviation computations
 * - Used element counting
 *
 * @param[in,out] array Array to operate on
 * @param[in] capacity Capacity of the array (100 for this function)
 * @return int Always returns 0 indicating successful execution
 *
 * @note Uses capacity of 100 as defined by capacity3 constant
 * @see Keyboard_Input(), Find_Max(), Find_Min(), Mean_Average(), Median_Average(),
 *      Variance(), Standard_Deviation(), Num_of_Used_Elements()
 */
int MF3(int array[], int capacity) {
    printf("\n\n----------------------------- Menu Function 3 ----------------------------- \n");

    /** Read up to 100 non-negative integers from keyboard input using WF2 */
    printf("WF2 to read up to 100 non-negative integers from keyboard input : ");
    Keyboard_Input(array, capacity);

    /** Display maximum and minimum values in the array */
    printf("\n\nThe max and min values in the array are %d, %d ", Find_Max(array, capacity), Find_Min(array, capacity));

    /** Display mean average and median values */
    printf("\n\nArray has an average value of %.2f and a median value of %d", Mean_Average(array, capacity), Median_Average(array, capacity));

    /** Display variance and standard deviation with used element count */
    printf("\n\nArray with %d used elements has a variance of %.2f and a standard deviation of %.2f",
        Num_of_Used_Elements(array, capacity), Variance(array, capacity), Standard_Deviation(array, capacity));

    return 0;
}