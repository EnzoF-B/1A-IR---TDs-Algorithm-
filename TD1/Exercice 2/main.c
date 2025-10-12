#include <stdio.h>
#include "prime.h"
#include <math.h>
#include <time.h>

int main() {
    int n = 6;
    double temps_ecoule1;
    double temps_ecoule2;
    clock_t debut, fin;
    clock_t start, end;
    debut = clock();
    printf("\n");
    printf("Le nombre de nombres premiers (naïf) avant %i est de %i\n", n, naive_prime(n));
    fin = clock();
    temps_ecoule1=((double)(fin - debut))/CLOCKS_PER_SEC;
    printf("et le temps écoulé est de %f secondes\n", temps_ecoule1);
    printf("\n");
    start = clock();
    printf("Le nombre de nombres premiers (crible) avant %i est de %i\n",n,effi_prime(n));
    end = clock();
    temps_ecoule2=((double)(end - start))/CLOCKS_PER_SEC;
    printf("et le temps écoulé est de %f secondes\n", temps_ecoule2);
    printf("\n");
    float delta_temps = temps_ecoule1 - temps_ecoule2;
    printf("La différence de temps est de %f", delta_temps);
    printf("\n")
}
