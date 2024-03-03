// Program with various sorting algorithms.
// All algorithms are assumed to sort in-place.
#pragma once

// C library files
#include <string.h>
#include <stdlib.h>

// User defined files
#include <sort/sort_algorithms.h>

// Perferm insertion sort in place on input array
void insertion_sort(void * array, size_t len, size_t elem_size, int (*compare_fn)(void * first, void * second)) {
    void * temp_var = malloc(elem_size);
    void * end_pt = array + (len * elem_size);
    for (void * i = array + elem_size; i < end_pt; i += elem_size) {
        memcpy(temp_var, i, elem_size);
        for (void * j = i - elem_size; j >= array; j -= elem_size) {
            if ((*compare_fn)(j + elem_size, j)) {
                break;
            }
            memcpy(j + elem_size, j, elem_size);
            memcpy(j, temp_var, elem_size);
        }
    }
    free(temp_var);
}
