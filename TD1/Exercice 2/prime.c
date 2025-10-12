#include <stdio.h>
#include <math.h>

//Algorithme naïf pour le comptage des nombres premiers

int naive_prime(int n) {
    int c=0;
    int rn = ceil(sqrt(n));         //radical de n arrondi au supérieur pour la boucle dans la suite
    if (n<=2) {
        return 0;
    }
    if (n==3){
        return 1;
    }
    if (n==4){
        return 2;
    }
    if (n==5){
        return 2;
    }
    if (n>5) {
        for (int i=1;i<=rn;i++ ) {
            if (n%i== 0) {              
            c++;
                }
            }
        }
    return c;
}

int prime(int n) {
    if (n==1){
        return 0;
    }
    for (int i=2;i<n;i++) {
        if(n%i==0) {
            return 0;
        }
        else {
            return 1;
        }
    }
    return 0;
}

//Algorithme plus optimal (crible d'Ératosthène)

int effi_prime(int n) {
    int P[n+1];
    for (int i=1;i<=n;i++) {
        P[i] = i;
    }
    int c=0;
    if (n<=2) {
        return 0;
    }
    if (n==3) {
        return 1;
    }
    for (int i=2;i<=n;i++) {
        if (prime(P[i])==1){
            c++;
            for(int j=i*i;j<=n;j+=i) {
                P[j] = 0;
            }
        }
    }
    return c+1;
}
    
/* 
3) On parcoure les n cases du tableau, on commence par enlever tous les multiples de deux car 2 est premier, 
on élimine n/2 éléments.
On élimine les multiples de 3 donc n/3.
On élimine les multiples de 5 car 4 est pair, donc n/5...
On somme le nombre de ces nombres éliminés afin d'obtenir la somme des 1/p où p représente un nombre premier.
À l'aide de l'inégalité de l'énoncé on peut prouver que la complexité est de O(nlog(log(n))) car il y a n éléments dans notre tableau.
*/
