// Utilities for working with arrays
#pragma once
#include <stdlib.h>

// Print an arbitrary array to stdout
void print_array(void * array, int len, size_t elem_size);

// Return true if int_a > int_b, false otherwise.
int int_compare(void * int_a, void * int_b); 

// Return true if char_a > char_b, false otherwise.
int char_compare(void * char_a, void * char_b); 

// Malloc and fill an int array with random integers
int * init_random_int_array(size_t len); 

// Malloc and fill a char array with random printable chars
char * init_random_char_array(size_t len); 



