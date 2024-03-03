// Program with various sorting algorithms.
// All algorithms are assumed to sort in-place.
#pragma once

#include <stdlib.h>

// Print an arbitrary array to stdout
void print_array(void * array, int len, size_t elem_size);

// Return true if char_a > char_b, false otherwise.
int char_compare(void * char_a, void * char_b);

// Perferm insertion sort in place on input array
void insertion_sort(void * array, size_t len, size_t elem_size, int (*compare_fn)(void * first, void * second));

// Malloc and fill an int array with random integers
int * init_random_int_array(size_t len);

// Malloc and fill a char array with random printable chars
char * init_random_char_array(size_t len);