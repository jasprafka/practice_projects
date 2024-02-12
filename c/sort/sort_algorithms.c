// Program with various sorting algorithms.
// All algorithms are assumed to sort in-place.


#include <stdio.h>
#include <time.h>  // Included to seed the RNG
#include <stdlib.h>

#define LISTLENGTH 10
#define MAXRANDOM 100

void insertion_sort(int * list, int list_len) {
    int temp_val, compare_index;
    for(int i = 1; i < list_len; i++){
        temp_val = list[i];
        compare_index = i - 1;
    }
}

void test_insertion_sort(int * list, int list_len) {
    for(int i = 0; i < list_len; i++){
        printf("Array element at %d is %d\n", i, list[i]);
    }
}

void init_random_list(int * list, int list_len) {
    for(int i = 0; i < list_len; i++) {
        list[i] = random() % MAXRANDOM;
    }
}

int main() {
    srandom(time(NULL));
    int rand_list[LISTLENGTH];
    init_random_list(rand_list, LISTLENGTH);
    test_insertion_sort(rand_list, LISTLENGTH);
    return 0;
}
