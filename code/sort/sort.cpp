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
compare_swap(T& a, T& b, bool is_ascending)
{
    
    if (is_ascending) {
        if (a > b) {
            swap(a, b);
        }
    } else {
        if (a < b) {
            swap(a, b);
        }
    }
}

template <typename T>
void
bubble_sort(T list[], const int& size, bool is_ascending=true)
{
    int pass = 1;
    while (true) {
        bool is_swapped = false;    
        for (int i = 0; i < size - pass; ++i) {
            compare_swap(list[i], list[i + 1], is_ascending);
            is_swapped = true;
        }
        ++pass;
        if (!is_swapped) {
            break;
        }
    }
}

            
