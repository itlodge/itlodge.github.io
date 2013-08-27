#include <iostream>

void
reverse(char *str);

int
main(int argc, char *argv[])
{
    char test_str[] = "abcd";
    
    std::cout << test_str << std::endl;
    reverse(test_str);
    std::cout << test_str << std::endl;
    
    return 0;
}

void
reverse(char *str)
{
    char *end = str;
    char tmp;
    
    if (str) {
        while (*end) {
            ++end;
        }
        --end;
        while (str < end) {
            tmp = *str;
            *str++ = *end;
            *end-- = tmp;
        }
    }
}
