#include <stdio.h>
#include <stdlib.h>
#include <float.h>

void sizeof_example() {
    int i[10];
    printf("sizeof(i)=%ld\n", sizeof(i));
    printf("sizeof(i[0])=%ld\n", sizeof(i[0]));

    printf("sizeof(long double)=%ld\n", sizeof(long double));
    printf("sizeof(double)=%ld\n", sizeof(double));
    printf("sizeof(float)=%ld\n", sizeof(float));
    printf("sizeof(int)=%ld\n", sizeof(int));
    printf("sizeof(short)=%ld\n", sizeof(short));
    printf("sizeof(char)=%ld\n", sizeof(char));
}

int main() {
    float array[128] = {0};
    const int size = sizeof(array) / sizeof(array[0]);

    float max = FLT_MIN, min = FLT_MAX;

    for (int i = 0; i < size; i++) {
        array[i] = rand() % 256;
        if (array[i] > max) max = array[i];
        if (array[i] < min) min = array[i];
        printf("array[%d] = %f\n", i, array[i]);
    }

    printf("max = %f\n", max);
    printf("min = %f\n", min);


}
