#include <utils/array_utils.h>
#include <sort/sort_algorithms.h>

#define ARRAYLENGTH 10

int main(int argc, char ** argv) {
    int * arry = init_random_int_array(ARRAYLENGTH);
    print_array(arry, 10, 4);
    return 0;
}
