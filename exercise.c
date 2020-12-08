/**
 * In class exercise.
 *
 * - Déclarer référentiel GitHub exercice (4min)
 * - Déclarer un tableau de 128 float 32-bits (5min) -> 13h30
 * - Remplir ce tableau avec des valeurs aléatoires 0..255 (10min)
 * - Identifier la valeur max. du tableau et la valeur min. puis afficher (5min)
 * - Normaliser ce tableau à 1.0 (10min)
 * - Afficher le tableau sur la sortie standard (5min)
 */
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

void fill(float array[], size_t size) {
    for (int i = 0; i < size; i++) {
        array[i] = (float)rand() / RAND_MAX * 255;
    }
}

float min(float array[], size_t size) {
    float min = FLT_MAX;
    for (int i = 0; i < size; i++)
        if (array[i] < min) min = array[i];
    return min;
}

float max(float array[], size_t size) {
    float max = FLT_MIN;
    for (int i = 0; i < size; i++)
        if (array[i] > max) max = array[i];
    return max;
}

void normalize(float array[], size_t size) {
    float max_value = max(array, size);
    for (int i = 0; i < size; i++) {
        array[i] /= max_value;
        printf("array[%d] = %f\n", i, array[i]);
    }
}

void display(float array[], size_t size) {
    for (int i = 0; i < size; i++) {
        printf("array[%d] = %f\n", i, array[i]);
    }
}

int main(int argc, char *argv[]) {
    // Random seed from arguments
    srand(argc > 1 ? atoi(argv[1]) : 0);

    // Initialize array
    float array[128] = {0};
    const int size = sizeof(array) / sizeof(array[0]);

    fill(array, size);
    normalize(array, size);
    display(array, size);
    printf("max = %f\n", max(array, size));
    printf("min = %f\n", min(array, size));
}
