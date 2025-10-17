#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"
#include "utils.h"

int main(void) {
    int n = 100000;
    int target = 2301;
    int* arr = malloc(4*n);
    for (int i=0;i<n;i++) {
        arr[i] = i;
    }
    double temps_ecoule1;
    double temps_ecoule2;
    float delta_temps;
    clock_t debut, fin;
    clock_t start, end;
    printf("\n");
    debut = clock();
    int js = jump_search(arr,n,target); 
    fin = clock();
    printf("Pour jump_search:%i\n", js);
    temps_ecoule1 = ((double)(fin - debut))/CLOCKS_PER_SEC;
    printf("et le temps écoulé pour ce Jump Search est de %f secondes\n",temps_ecoule1);
    printf("\n");
    start = clock();
    int bs = binary_search(arr,n,target);
    end = clock();
    printf("Pour binary_search:%i\n",bs);
    temps_ecoule2 = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("et le temps écoulé pour ce Binary Search est de %f secondes\n",temps_ecoule2);
    printf("\n");
    delta_temps = temps_ecoule1 - temps_ecoule2;
    printf("La différence de temps est de %f\n",delta_temps);
    printf("\n");
    return 0;
}
