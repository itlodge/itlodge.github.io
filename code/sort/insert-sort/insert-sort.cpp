
template <typename T>
void
insert_sort(T list[], const int& len, bool is_ascending=true)
{
    for (int i = 1; i < len; ++i) {
        T tmp = list[i]; 
        int j;
        for (j = i - 1; j >= 0; --j) {
            if (is_ascending) {
                if (tmp < list[j]) {
                    list[j + 1] = list[j];
                } else {
                    break;
                }
            } else {
                if (tmp > list[j]) {
                    list[j + 1] = list[j];
                } else {
                    break;
                }
            }
        }
        list[j + 1] = tmp;
    }
}


        
