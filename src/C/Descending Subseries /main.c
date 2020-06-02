#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    unsigned long n;
    unsigned long k;
    unsigned long m;
    if (input_parameters(&n, &k, &m) != 0)
        return EXIT_FAILURE;
    unsigned long (*permut)[n] = NULL;
    if (allocate_arrays(n, &permut) != 0) {
        delete_arrays(n, &permut);
        return EXIT_FAILURE;
    }
    if (input_permut(n, *permut) != 0) {
        delete_arrays(n, &permut);
        return EXIT_FAILURE;
    }
    if (check_permut(n, *permut) != 0) {
        delete_arrays(n, &permut);
        return EXIT_FAILURE;
    }

    unsigned long answer = 0;
    result(0, n, *permut, k, &answer);
    printf("%lu\n", answer % m);

    delete_arrays(n, &permut);
    return EXIT_SUCCESS;
}
