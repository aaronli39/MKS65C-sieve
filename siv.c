#include <stdio.h>
#include <math.h>

double find_nth_prime(double n) {
    double arr[1.15 * n * log(n)];
    double i, temp, count;
    arr[0] = 1;
    arr[1] = 1;
    for (i = 0; i < n; i++) {
        if (! arr[i]) {
            count += 1;
            for (temp = i; temp < n; temp += arr[i]) {
                arr[temp] = 1;
            }
        }
    }

}
