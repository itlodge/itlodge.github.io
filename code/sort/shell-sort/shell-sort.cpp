
template <typename T>
void
shell_sort(T list[], const int& len, bool is_ascending=true)
{
    int gap = len >> 1;
    while (gap >= 1) {
        for (int i = gap; i < len; i += gap) {
            T tmp = list[i];
            T j;
            for (j = i - gap; j >= 0; j -= gap) {
                if (is_ascending) {
                    if (tmp < list[j]) {
                        list[j + gap] = list[j];
                    } else {
                        break;
                    }
                } else {
                    if (tmp > list[j]) {
                        list[j + gap] = list[j];
                    } else {
                        break;
                    }
                }
            }
            list[j + gap] = tmp;
        }
        gap >>= 1;
    }
}
