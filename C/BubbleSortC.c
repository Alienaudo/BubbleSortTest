#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#include "arr.h"

static inline void swap(int *xElem, int *yElem)
{
    int temp = *xElem;
    *xElem = *yElem;
    *yElem = temp;
};

void bubbleSort(int array[], const int n)
{

    int i, j;
    bool swapped;

    for (i = 0; i < n - 1; i++) {

        swapped = false;

        for (j = 0; j < n - i - 1; j++) {

            if (array[j] > array[j+1]) {

                swap(&array[j], &array[j+1]);
                swapped = true;

            }

        }

        if (swapped == false) { break; }

    }

};

void printArray(int array[], const int n)
{
    printf("Sorted array: ");

    for (int i = 0; i < n; i++) {

        printf("%d ", array[i]);

    }

};

int main()
{

    const int n = sizeof(unsortedList) / sizeof(unsortedList[0]);

    clock_t start = clock();
    bubbleSort(unsortedList, n);
    clock_t end = clock();

    const double time = (double)(end - start) / CLOCKS_PER_SEC;

    printArray(unsortedList, n);
    printf("Execution time: %f seconds\n", time);


    return 0;

}
