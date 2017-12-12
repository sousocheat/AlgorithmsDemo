#include <stdio.h>
#include <stdlib.h>
#include "Helpers.h"
#include "Sorting/SortingFunc.h"

int dumb_arr[] = {12, 23, 2, 45, 1, 83, 24};


int main() {
    int ch;
    int so_ch;
    do {
        ClearScreen();
        print_main_menu();
        ch = get_input();
        switch (ch) {
            case '1': {
                do {
                    ClearScreen();
                    so_ch = print_sort_menu();
                    switch (so_ch) {
                        case '1': {
                            ClearScreen();
                            print_array_before(dumb_arr);
                            bubble_sort(dumb_arr);
                            print_array_after(dumb_arr);
                            print_back();
                            break;
                        }
                        case '2':
                            ClearScreen();
                            print_array_before(dumb_arr);
                            merge_sort(dumb_arr);
                            print_array_after(dumb_arr);
                            print_back();
                            break;
                        case '3':
                            ClearScreen();
                            print_array_before(dumb_arr);
                            selection_sort(dumb_arr);
                            print_array_after(dumb_arr);
                            print_back();
                            break;
                        case '4':
                            ClearScreen();
                            print_array_before(dumb_arr);
                            insertion_sort(dumb_arr);
                            print_array_after(dumb_arr);
                            print_back();
                            break;
                        case '5':
                            ClearScreen();
                            print_array_before(dumb_arr);
                            quick_sort(dumb_arr);
                            print_array_after(dumb_arr);
                            print_back();
                            break;
                        case '6':
                            break;
                        default:
                            printf("\n*** Try again later. ***\n");
                    }
                } while (so_ch != '6');
                break;
            }
            case '2': {
                print_search_menu();
                break;
            }
            case '3':
                exit(0);
            default:
                printf("\n*** Try again later. ***\n");
        }
    } while (1);
    return 0;
}