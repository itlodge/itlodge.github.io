#include <iostream>

char *
reverse_str(char *str);

int
main(int argc, char *argv[])
{
    char test_str[] = "abcd";
    
    std::cout << test_str << std::endl;
    std::cout << reverse_str(test_str) << std::endl;
    
    return 0;
}

char *
reverse_str(char *str)
{
    if (str == NULL) {
        return str;
    }

    int len = 0;

    while (*(str + len)) {
        len++;
    }

    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }

    return str;
}
