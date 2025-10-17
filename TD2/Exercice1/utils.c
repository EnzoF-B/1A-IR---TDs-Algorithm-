#include "utils.h"

int is_sorted_nondecreasing(int *arr, int n) {
    for (int i=0;i<n-1;i++) {
        if(arr[i+1] < arr[i]) {
            return 0;
        }
    } 
    return 1;   
}  

int min_int(int a, int b) {
    if(a<=b) {
        return a;
    } 
    return b; 
}
