/**
 * @file Main.c
 * @brief Main program with menu-driven interface for testing different array operations
 *
 * This program provides a menu-driven interface to test various array operations
 * with different capacities. It includes input validation and buffer management
 * to ensure robust user interaction.
 */

#include <stdlib.h>
#include <stdio.h>
#include "Simple_Operations_Header.h"
#include "Menu_Header.h"

 /**
  * @brief Clears the input buffer to prevent infinite loops from invalid input
  *
  * This helper function reads and discards any remaining characters in the input
  * buffer, including the newline character. This prevents scanf failures from
  * affecting subsequent input operations.
  *
  * @note This function handles both EOF conditions and buffer overflow scenarios
  */
static void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * @brief Main function implementing menu-driven testing interface
 *
 * Provides a continuous menu system that allows users to test different menu
 * functions with arrays of varying capacities. The program includes robust
 * input validation and error handling to manage user input effectively.
 *
 * Menu Options:
 * - Option 1: Test Menu Function 1 with capacity1 (10 elements)
 * - Option 2: Test Menu Function 2 with capacity2 (20 elements)
 * - Option 3: Test Menu Function 3 with capacity3 (100 elements)
 * - Option 4: Exit the program gracefully
 *
 * @return int Program exit status (EXIT_SUCCESS upon normal termination)
 *
 * @note The function uses local array declarations within case blocks to
 *       ensure proper scope and memory management
 * @warning Input validation is performed to prevent buffer overflow and
 *          infinite loops from invalid user input
 */

int main() {
    int option = 0; /**< User-selected menu option */

    do {
        /* Display main menu interface */
        printf("\n\n----------------------------- Main Menu -----------------------------\n");
        printf("1. Test Menu Function 1 (Capacity 10)\n");
        printf("2. Test Menu Function 2 (Capacity 20)\n");
        printf("3. Test Menu Function 3 (Capacity 100)\n");
        printf("4. Exit\n");
        printf("Enter your option: ");

        /* Validate user input */
        if (scanf_s("%d", &option) != 1) {
            printf("Invalid option. Please try again.\n");
            clearInputBuffer(); /* Flush invalid input to prevent infinite loop */
            option = 0;         /* Reset option to remain in menu */
            continue;
        }
        clearInputBuffer(); /* Clear any extra characters after valid input */

        /* Process user selection */
        switch (option) {
        case 1: {
            int arr1[capacity1]; /**< Array for Menu Function 1 testing */
            MF1(arr1, capacity1);
            break;
        }
        case 2: {
            int arr2[capacity2]; /**< Array for Menu Function 2 testing */
            MF2(arr2, capacity2);
            break;
        }
        case 3: {
            int arr3[capacity3]; /**< Array for Menu Function 3 testing */
            MF3(arr3, capacity3);
            break;
        }
        case 4:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid option. Please try again.\n");
        }
	} while (option != 4); // Continue until user chooses to exit

	return EXIT_SUCCESS; // Indicates successful program termination
}