#include <stdio.h>
#include <time.h>
#include "fib.h"

int main() {
    int n = 30;                                        //test ici avec 30
    long long int DPFib[n+1];
    for (int i = 0; i <= n+1; i++) DPFib[i] = -1;
    printf("\n");
    double temps_ecoule1;
    double temps_ecoule2;
    clock_t debut, fin;
    clock_t start, end;
    debut = clock();
    long long int nf = naive_fibo(n);
    fin = clock();
    printf("Fibonacci(%i) (naïf) donne %lld\n", n, nf);
    temps_ecoule1=((double)(fin - debut))/CLOCKS_PER_SEC;
    printf("et le temps écoulé est de %f secondes\n", temps_ecoule1);
    printf("\n");
    start = clock();
    long long int df = dynamic_fibo(n,DPFib);                        
    end = clock();
    printf("Fibonaacci(%i) (dynamique) donne %lld\n", n, df);
    temps_ecoule2=((double)(end - start))/CLOCKS_PER_SEC;
    printf("et le temps écoulé est de %f secondes\n", temps_ecoule2);
    printf("\n");
    float delta_temps = temps_ecoule1 - temps_ecoule2;
    printf("La différence de temps est de %f", delta_temps);          //le delta_temps est pratiquement égal à temps_ecoule1
    printf("\n");
    printf("\n");
}
