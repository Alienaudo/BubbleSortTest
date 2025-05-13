#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static inline void swap(int *xElem, int *yElem)
{

    int temp = *xElem;
    *xElem = *yElem;
    *yElem = temp;

};

void bubbleSort(int *array, const int n)
{

    int i, j;
    int externLoop = n - 1;
    bool swapped;

    for (i = 0; i < externLoop; ++i) {

        int interLoop = externLoop - i;
        swapped = false;

        for (j = 0; j < interLoop; ++j) {

        if (array[j] > array[j + 1]) {

            swap(&array[j], &array[j + 1]);
            swapped = true;

        }

        }

        if (swapped == false) break;

    }

};

inline static void printArray(const int *array, const int n)
{

    FILE *file = fopen("sortedArray.txt", "w");

    fprintf(file, "%s", "Sorted array: \n");

    for (int i = 0; i < n; ++i) {

        fprintf(file, "%d", array[i]);

    }

};

int main(void) {

    FILE *file = fopen("arr.txt", "r");

    if (file == NULL) {

        perror("Error opening file");
        return 1;

    }

    int numberList[100000];
    int i = 0;

    while (fscanf(file, "%d", &numberList[i]) == 1 && i < 100000) {
        ++i;
    }

    fclose(file);

    const int n = i;

    clock_t start = clock();
    bubbleSort(numberList, n);
    clock_t end = clock();

    const double time = (double)(end - start) / CLOCKS_PER_SEC;

    printArray(numberList, n);
    printf("Execution time: %f seconds\n", time);

    return 0;

}