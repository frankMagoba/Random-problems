#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#include "inputlib.h"

int input_parameters(unsigned long *restrict n,
                     unsigned long *restrict k,
                     unsigned long *restrict m) {
    char *buff = NULL;
    size_t buffSize = 0;
    if (cust_getline(&buff, &buffSize, stdin)) {
        char *beg = buff;
        char *end = NULL;
        errno = 0;
        *n = strtoul(beg, &end, 0);
        if (beg == end || errno == ERANGE || *n > 100000 || *n == 0) {
            free(buff);
            return -1;
        }

        beg = end;
        end = NULL;
        errno = 0;
        *k = strtoul(beg, &end, 0);
        if (beg == end || errno == ERANGE || *k > 10 || *k == 0 || *k > *n) {
            free(buff);
            return -1;
        }

        beg = end;
        end = NULL;
        errno = 0;
        *m = strtoul(beg, &end, 0);
        if (beg == end || errno == ERANGE || *m > 1000000000 || *m == 0) {
            free(buff);
            return -1;
        }
    } else
        return -1;

    free(buff);
    return 0;
}

int allocate_arrays(unsigned long n,
                    unsigned long (**permut)[n]) {
    if ((*permut = malloc(sizeof(**permut))) == NULL)
        return -1;

    return 0;
}

int input_permut(unsigned long n,
                 unsigned long permut[n]) {
    char *buff = NULL;
    size_t buffSize = 0;
    if (cust_getline(&buff, &buffSize, stdin)) {
        char *beg = buff;
        char *end = NULL;
        for (size_t i = 0; i < n; ++i) {
            errno = 0;
            permut[i] = strtoul(beg, &end, 0);
            if (beg == end || errno == ERANGE || permut[i] > n || permut[i] == 0) {
                free(buff);
                return -1;
            } else {
                beg = end;
                end = NULL;
            }
        }
    } else
        return -1;

    free(buff);
    return 0;
}

int check_permut(unsigned long n,
                 const unsigned long permut[n]) {
    bool (*found)[n] = calloc(1, sizeof(*found));
    for (size_t i = 0; i < n; ++i) {
        (*found)[permut[i] - 1] = true;
    }
    for (size_t i = 0; i < n; ++i) {
        if ((*found)[i] == false) {
            free(found);
            return -1;
        }
    }

    free(found);
    return 0;
}

void result(unsigned long prev,
            unsigned long n,
            const unsigned long permut[restrict n],
            unsigned long k,
            unsigned long *restrict answer) {
    if (k == 0)
        ++(*answer);
    else
        for (size_t i = 0; i < (n - k + 1); ++i)
            if (prev == 0 || prev > permut[i]) // prev == 0 is only true for the outermost iteration
                result(permut[i], n - (i + 1), permut + (i + 1), k - 1, answer);
}

void delete_arrays(unsigned long n,
                   unsigned long (**permut)[n]) {
    free(*permut);
    *permut = NULL;
}
