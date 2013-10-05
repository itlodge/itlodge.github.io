#include <iostream>

template <typename T>
void
swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
void
bubble_sort(T list[], const int& size, bool is_ascending=true)
{
    int pass = 1;
    while (true) {
        bool is_swapped = false;    
        for (int i = 0; i < size - pass; ++i) {
            if (is_ascending) {
                if (list[i] > list[i + 1]) {
                    swap(list[i], list[i + 1]);
                    is_swapped = true;
                }
            } else {
                if (list[i] < list[i + 1]) {
                    swap(list[i], list[i + 1]);
                    is_swapped = true;
                }
            }
        }
        ++pass;
        if (!is_swapped) {
            break;
        }
    }
}

            
