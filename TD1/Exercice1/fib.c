#include <stdio.h>
#include "fib.h"
#include <time.h>

//Algo naïf pour la suite de Fibonacci

long long int naive_fibo(int n) {
    if (n==0 || n==1) {
        return n;
    }
    else { 
        return naive_fibo(n-1) + naive_fibo(n-2);
    }
}

//Algo dynamique pour la suite de Fibonacci

long long int dynamic_fibo(int n, long long int DPFib[n+1]) {
    if (n<=1){
        return n;
    }
    if (DPFib[n]!= -1) {
        return DPFib[n];
    }
    else {
        DPFib[n] = dynamic_fibo(n-1,DPFib) + dynamic_fibo(n-2,DPFib);
    }
    return DPFib[n];
}
