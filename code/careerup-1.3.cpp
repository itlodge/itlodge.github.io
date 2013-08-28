#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

void
rm_dup(char *str);

int
main(int argc, char *argv[])
{
    char test_str[20];

    srand(time(0));
    for (int i = 0; i < 20; i++) {
        test_str[i] = 'a' + rand() % 26;
    }
    std::cout << test_str << std::endl;
    rm_dup(test_str);
    std::cout << test_str << std::endl;
    
    return 0;
}

void
rm_dup(char *str)
{
    for (int i = 1; i < strlen(str); i++) {
        int j;
        for (j = 0; j < i; j++) {
            if (str[i] == str[j]) {
                break;
            }
        }
        if (j < i) {
            for (int k = i; k < strlen(str); k++) {
                str[k] = str[k + 1];
            }
            i--;
        }
    }
}

