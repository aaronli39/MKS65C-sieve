#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sieve.h"

int sieve0(int n) {
    char * arr = calloc(sizeof(char), ceil(1.15 * n * log(n)));
    int num = ceil(1.15 * n * log(n));
    int i, ret = 2;
    // printf("This is the size: %d\n", num);
    int count = 0;

    // printf("0: %d, 1: %d\n", * (arr + 0), * (arr + 1));
    for (i = 2; i < num; i++) {
        // if current index is not 1 (true)
        // printf("current val: %d\ncurrent index: %d\n\n", * (arr + i), i);
        if (! * (arr + i)) {
            // printf("bool worked\n");
            for (ret = 2; ret * i < num; ret++) { // make all multiples 1
                if (! * (arr + (ret * i))) {
                    int temp = ret * i;
                    * (arr + temp) = 1;
                    // printf("val at index %d: %d\n", 4, * (arr + 4));
                }
            }
        }
    } for (i = 2; count < n; i++) {
        if (! * (arr + i)) {
            count += 1;
            ret = i;
        }
    }

    // free(arr);
    return ret;
}

int sieve(int n) {
    char * arr = calloc(sizeof(char), ceil(1.15 * n * log(n)));
    int num = (ceil(1.15 * n * log(n)) / 2) + 3;
    int i, ret = 3;
    // printf("This is the size: %d\n", num);
    int count = 1;

    // printf("0: %d, 1: %d\n", * (arr + 0), * (arr + 1));
    for (i = 3; i < num; i++) {
        // if current index is not 1 (true)
        // printf("current val: %d\ncurrent index: %d\n\n", * (arr + i), i);
        if (! * (arr + i)) {
            // printf("%s\n", arr + i);
            // printf("bool worked\n");
            int current_val = 3 + (2 * (i - 3));
            for (ret = 3; ret * current_val <= 3 + (2 * (num - 3)); ret += 2) { // make all non-even multipltes 1
                // if (* (arr + (ret * i)) % 2 != 0) {
                //     printf("NOt true  \n");
                // }
                // value at index: 3 + (2 * (i - 3))
                int temp = (i + ((ret * (3 + (2 * (i - 3)))) - (3 + (2 * (i - 3)))) / 2);
                if (! * (arr + temp)) {
                    * (arr + temp) = 1;
                    // if (i < 5) printf("val of %d: %d\n", ret * (3 + (2 * (i - 3))), * (arr + temp));
                    // printf("val at index %d: %d\n", 4, * (arr + 4));
                }
            }
        }
    } for (i = 3; count < n; i++) {
        // printf("%d: %d\n", i, * (arr + i));
        if (! * (arr + i)) {
            count++;
            ret = 3 + (2 * (i - 3));
        }
    }

    // free(arr);
    return ret;
}
