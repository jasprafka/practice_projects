#include <stdio.h>
#include <time.h>

#include <utils/array_utils.h>
#include <sort/sort_algorithms.h>

#define ARRAYLENGTH 100

void demo_insertion_sort() {
    clock_t t_start, t_end;
    int * arry = init_random_int_array(ARRAYLENGTH);
    printf("Array before sorting: ");
    print_array(arry, ARRAYLENGTH, 4);
    t_start = clock();
    insertion_sort(arry, ARRAYLENGTH, sizeof(int), int_compare);
    t_end = clock();
    printf("Array after sorting: ");
    print_array(arry, ARRAYLENGTH, 4);
    printf("Sort time for %d elements = %f\n", ARRAYLENGTH, (double)(t_end - t_start) / CLOCKS_PER_SEC);
}

int main(int argc, char ** argv) {
    demo_insertion_sort();
    return 0;
}
