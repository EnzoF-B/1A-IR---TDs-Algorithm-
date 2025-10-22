#include <stdlib.h>
#include "sort.h"
#include "utils.h"

void selection_sort(int *arr, int n) {
    for (int i = 0;i<n-1;i++) {
        int min =i;
        for (int j=i+1;i<n;i++) {
            if (arr[j]<arr[min]) {
                min = j;
            }
        }
        swap_int(&arr[i],&arr[min]);
    }
}

void insertion_sort(int *arr, int n) {
    for (int i=1;i<n;i++) {
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j]>key) {
            arr[1+j] = arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void bubble_sort(int *arr, int n) {
    for (int i=0;i<n;i++) {
        for (int j=1;j<n-i;j++) {
            if (arr[j]<arr[j-1]) {
                swap_int(&arr[j],&arr[j-1]);
            }
        }
    }
}

void merge(int *arr, int *tmp, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int i;
    int j;
    int k;
    for (i = 0; i < n1; i++){
        tmp[i] = arr[l+i];
    }
    for  (j = 0; j < n2; j++){
        tmp[j+m+1] = arr[m+1+j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i<n1 && j<n2) {
        if (tmp[i+l] <= tmp[j+m+1]) {
            arr[k] = tmp[i+l];
            i++;
        }
        else { 
            arr[k] = tmp[j+m+1];
            j++;
        }
        k++;
    }
    while (i<n1) {
        arr[k] = tmp[l+i];
        i++;
        k++;
    }
    while (j<n2) {
        arr[k] = tmp[j+m+1];
        j++;
        k++;
    }
}



void mergesort_rec (int *arr, int *tmp, int l, int r) {
    // recursive steps of merge sort
    if (l<r){
        int mid = l + (r-l)/2;
        mergesort_rec(arr, tmp, l, mid);
        mergesort_rec(arr,tmp, mid+1,r);
        merge(arr,tmp,l,mid,r);
    }
}

void merge_sort(int *arr, int n) {
    if (!arr || n <= 1)
        return;
    int *tmp = (int *)malloc((size_t)n * sizeof(int));
    if (!tmp)
        return;
    mergesort_rec(arr, tmp, 0, n - 1);
    free(tmp);
}

int partition(int *arr, int l, int r) {
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j<= r - 1; j++){
        if (arr[j] < pivot){
            i++;
            swap_int(&arr[i], &arr[j]);
        }
    }
    swap_int(&arr[i+1], &arr[r]);
    return i+1;
}

void quick_sort_rec(int *arr, int l, int r) {
    if (l<r) {
        int part = partition(arr, l, r);
        quick_sort_rec(arr, l , part -1);
        quick_sort_rec(arr, part +1, r);
    }
}

void quick_sort(int *arr, int n) {
    if (!arr || n <= 1)
        return;
    quick_sort_rec(arr, 0, n - 1);
}