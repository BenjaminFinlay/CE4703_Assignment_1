#ifndef HEADER_H
#define HEADER_H // header guard

#include "Main_Header.h" // include main header for macros


// function data type though process
// wf1 -- int as it just returns a random number
// wf2, wf3, wf4, wf5, wf6, wf8
// wf9,wf10 -- int as they both return min and max

// Declaring each Function
int Random_int(int min, int max); // returns random number with limits
void Keyboard_Input(int array[], int capacity); // array values read from keyboard input, a negative value will terminate input, and remaining values become -1
void Array_Random(int array[], int size, int capacity, int min, int max); // fills array with random numbers
void Print_Used(int array[], int capacity); // Prints only used elements of the array into an array and separates unused elements into a separate array
void Print_All(int array[], int capacity); // Searches for a value in the array and returns its index or -1 if not found
int Find_Min(int array[], int capacity); // Returns the minimum values in the array
int Find_Max(int array[], int capacity); // Returns the maximum values in the array
int Num_of_Used_Elements(int array[], int capacity); // Returns the number of used elements in the array

#endif // HEADER_H