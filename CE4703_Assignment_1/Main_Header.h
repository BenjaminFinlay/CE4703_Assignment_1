#ifndef MAIN_HEADER_H
#define MAIN_HEADER_H // include guard

// Preprocessor macros
#define UNUSED_MARKER -1 // marker for unused elements setting them to -1
#define IS_USED(value) ((value) >= 0) // marker if value is used (non-negative)
#define ARRAY_FULL(used, capacity) ((used) >= (capacity)) // marker if array is full


#endif // MAIN_HEADER_H