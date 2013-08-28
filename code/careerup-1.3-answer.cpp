#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

void
rm_dup(char *str);

int
main(int argc, char *argv[])
{
    char test_str1[] = "abcd";
    rm_dup(test_str1);
    std::cout << test_str1 << std::endl;

    char test_str2[] = "aaaa";    
    rm_dup(test_str2);
    std::cout << test_str2 << std::endl;

    rm_dup(NULL);
    
    char test_str3[] = "";    
    rm_dup(test_str3);
    std::cout << test_str3 << std::endl;

    char test_str4[] = "aaabbb";    
    rm_dup(test_str4);
    std::cout << test_str4 << std::endl;

    char test_str5[] = "abababa";    
    rm_dup(test_str5);
    std::cout << test_str5 << std::endl;

    char test_str6[20];    
    srand(time(0));
    for (int i = 0; i < 20; i++) {
        test_str6[i] = 'a' + rand() % 26;
    }
    std::cout << test_str6 << std::endl;
    rm_dup(test_str6);
    std::cout << test_str6 << std::endl;
    
    return 0;
}

void
rm_dup(char *str)
{
    if (str == NULL) {
        return;
    }

    int tail = 1;
    for (int i = 1; i < strlen(str); i++) {
        int j;
        for (j = 0; j < tail; j++) {
            if (str[i] == str[j]) {
                break;
            }
        }
        if (j == tail) {
            str[tail] = str[i];
            tail++;
        }
    }
    str[tail] = '\0';
}

