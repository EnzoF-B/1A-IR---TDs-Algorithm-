#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "utils.h"

int main(void) {
    int n = 234765;
    int* arr = malloc(4*n);
    int* dst = malloc(4*n);
    for (int i=0;i<n;i++) {
        arr[i] = n-i; 
    }
    double temps_ecoule1;
    double temps_ecoule2;
    double temps_ecoule3;
    double temps_ecoule4;
    double temps_ecoule5;
    clock_t start1, end1;
    clock_t start2, end2;
    clock_t start3, end3;
    clock_t start4, end4;
    clock_t start5, end5;
    printf("\n");
    start1 = clock();
    selection_sort(arr,n);
    end1 = clock();
    temps_ecoule1=((double)(end1-start1))/CLOCKS_PER_SEC;
    printf("Selection Sort done in %f\n",temps_ecoule1);
    printf("\n");
    start2 = clock();
    insertion_sort(arr,n);
    end2 = clock();
    temps_ecoule2=((double)(end2-start2))/CLOCKS_PER_SEC;
    printf("Insertion Sort done in %f\n",temps_ecoule2);
    printf("\n");
    start3 = clock();
    bubble_sort(arr,n);
    end3 = clock();
    temps_ecoule3=((double)(end3-start3))/CLOCKS_PER_SEC;
    printf("Bubble Sort done in %f\n",temps_ecoule3);
    printf("\n");
    start4 = clock();
    merge_sort(arr,n);
    end4 = clock();
    temps_ecoule4=((double)(end4-start4))/CLOCKS_PER_SEC;
    printf("Merge Sort done in %f\n",temps_ecoule4);
    printf("\n");
    start5 = clock();
    quick_sort(arr,n);
    end5 = clock();
    temps_ecoule5=((double)(end5-start5))/CLOCKS_PER_SEC;
    printf("Quick Sort done in %f\n",temps_ecoule5);
    printf("\n");
}
