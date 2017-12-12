//
// Created by souso on 12/12/2017.
//

#include <stdio.h>
#include "SortingFunc.h"
#include "../Helpers.h"


void bubble_sort(int *arr) {
    printf("Sorting using Bubble Sort");
    int num = sizeof(arr) - 1;
    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void selection_sort(int *arr) {
    printf("Sorting using Selection Sort");
    int big, key;
    int n = sizeof(arr) - 1;
    for (key = n - 1; key >= 1; key--) {
        big = find_max(arr, key);
        swap(&arr[big], &arr[key]);
    }
}

int find_max(int *arr, int key) {
    int max = 0;
    for (int i = 0; i <= key; ++i) {
        if (arr[i] > arr[max]) max = i;
    }
    return max;
}

void merge_sort(int *arr) {
    printf("Sorting using Selection Sort");
    int curr_size;
    int left_start;
    int n = sizeof(arr) - 1;

    for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size) {
        for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            int mid = left_start + curr_size - 1;
            int right_end = min(left_start + 2 * curr_size - 1, n - 1);
            merge(arr, left_start, mid, right_end);
        }
    }
}

int min(int x, int y) {
    return (x < y) ? x : y;
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int n = 0; n < n1; ++n) {
        L[n] = arr[l + n];
    }
    for (int i1 = 0; i1 < n2; ++i1) {
        R[i1] = arr[m + 1 + i1];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void insertion_sort(int *arr) {
    printf("Sorting using Insertion Sort");
    int tmp, k, j;
    for (k = 0; k < sizeof(arr) - 1; ++k) {
        tmp = arr[k];
        j = k - 1;
        while (tmp < arr[j] && j >= 0) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = tmp;
    }
}

void quick_sort(int *arr) {
    printf("Sorting using Quick Sort");
    int low = 0, high = sizeof(arr) - 2;
    int stack[high - low + 1];
    int top = -1;

    stack[++top] = low;
    stack[++top] = high;
    while (top >= 0) {
        high = stack[top--];
        low = stack[top--];
        int p = partition(arr, low, high);
        if (p - 1 > low) {
            stack[++top] = low;
            stack[++top] = p - 1;
        }
        if (p + 1 < high) {
            stack[++top] = p + 1;
            stack[++top] = high;
        }
    }

}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

