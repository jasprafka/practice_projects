// Program with various sorting algorithms.
// All algorithms are assumed to sort in-place.


#include <stdio.h>
#include <time.h>  // Included to seed the RNG
#include <stdlib.h>

#define LISTLENGTH 10
#define MAXRANDOM 100

void print_array(int * list, int list_len) {
    for(int i = 0; i < list_len; i++){
        printf(" %d ", list[i]);
    }
}

// Perferm insertion sort in place on input array
void insertion_sort(int * list, int list_len) {
    int temp_int;
    for (int i = 1; i < list_len; i++) {
        temp_int = list[i];
        for (int j = i-1; j >= 0; j--) {
            if (temp_int >= list[j]) {
                break;
            }
            list[j + 1] = list[j];
            list[j] = temp_int;
        }
    }
}

// Test arbitrary sorting method with list and list_len as args.
void test_sort_method(int * list, int list_len, void (*func_ptr)(int*, int)) {
    printf("Array elements before sorting: ");
    print_array(list, list_len);
    printf("\n");
    func_ptr(list, list_len);
    printf("Array elements after sorting:  ");
    print_array(list, list_len);
    printf("\n");
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
    test_sort_method(rand_list, LISTLENGTH, &insertion_sort);
    printf("Size of int = %lu\n", sizeof(int));
    return 0;
}
