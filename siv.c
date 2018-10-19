#include <stdio.h>
#include <math.h>

int find_nth_prime(int n) {
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

int main() {
    printf("Searching for: 1,000,000th prime: %d\n", find_nth_prime(1000000));
    return 0;
}
