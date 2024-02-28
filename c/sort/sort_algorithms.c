// Program with various sorting algorithms.
// All algorithms are assumed to sort in-place.


#include <stdio.h>
#include <string.h>
#include <time.h>  // Included to seed the RNG
#include <stdlib.h>

#include <sort/sort_algorithms.h>

#define LISTLENGTH 10

// Print an arbitrary array to stdout
void print_array(void * array, int len, size_t elem_size) {
    void * end_pt = array + (len * elem_size);
    for(void * i = array; i < end_pt; i+=elem_size){
        if (elem_size == 4) {
            printf("%d ", *((int*)i));
        } else if (elem_size == 1) {
            printf("%c ", *((char*)i));
        }
    }
    printf("\n");
}

// Return true if int_a > int_b, false otherwise.
int int_compare(void * int_a, void * int_b) {
    return *(int*)int_a > *(int*)int_b;
}

// Return true if char_a > char_b, false otherwise.
int char_compare(void * char_a, void * char_b) {
    return *(char*)char_a > *(char*)char_b;
}

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

// Malloc and fill an int array with random integers
int * init_random_int_array(size_t len) {
    int * array = malloc(len * sizeof(int));
    srandom(time(NULL));
    for (int i = 0; i < len; i++) {
        array[i] = rand() % 1024;
    }
    return array;
}

// Malloc and fill a char array with random printable chars
char * init_random_char_array(size_t len) {
    char * array = malloc(len * sizeof(char));
    srandom(time(NULL));
    for (int i = 0; i < len; i++) {
        array[i] = 0x40 + rand() % 0x3f;
    }
    return array;
}
