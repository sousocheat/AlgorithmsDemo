//
// Created by souso on 12/12/2017.
//

#include <stdio.h>
#include "Helpers.h"


int Width = 80;
char *sort_methods[] = {"Bubble Sort", "Merge Sort", "Selection Sort", "Insertion Sort", "Quick Sort", "Back"};

void print_array(int *arr) {
    printf("\n[ ");
    for (int i = 0; i < sizeof(arr) - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void print_array_before(int *arr) {
    printf("\nProcessing\n");
    print_border(Width);
    printf("\nBefore: ");
    printf("\n[ ");
    for (int i = 0; i < sizeof(arr) - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void print_array_after(int *arr) {
    printf("\nAfter: ");
    printf("\n[ ");
    for (int i = 0; i < sizeof(arr) - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void print_main_menu() {
    print_border(Width);
    printf("\n1 - Sorting\n");
    printf("2 - Searching\n");
    printf("3 - Exit\n");
    print_border(Width);
}

int print_border(int n) {
    for (int i = 0; i < n; i++)printf("=");
}

int print_sort_menu() {
    printf("\nSorting demo\n");
    print_border(Width);
    printf("\n");
    for (int i = 0; i < sizeof(sort_methods) / sizeof(sort_methods[0]); ++i) {
        printf("%d - %s\n", i+1, sort_methods[i]);
    }
    print_border(Width);
    int ch = get_input();
    return ch;
}

void print_search_menu() {
    print_border(Width);
    printf("\n1 - Sorting\n");
    printf("2 - Searching\n");
    print_border(Width);
}

void swap(int *first, int *second) {
    int tmp;
    tmp = *first;
    *first = *second;
    *second = tmp;
}

int get_input() {
    char ch;
    printf("\nEnter a choice:\n> ");
    fflush(stdin);
    scanf(" %c", &ch);
    fflush(stdin);
    return ch;
}

void ClearScreen() {
    for (int i = 0; i < 120; ++i) {
        printf("\n");
    }
}

void print_back() {
    char ch;
    print_border(Width);
    printf("\nPress [b] to go back.");
    do {
        printf("\n> ");
        scanf(" %c", &ch);
        switch (ch) {
            case 13:
                break;
            default:
                printf("Try again!");
        }
    } while (ch != 'b');
}