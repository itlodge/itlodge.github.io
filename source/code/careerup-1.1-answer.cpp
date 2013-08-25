#include <iostream>

bool
has_unique_char_array(const std::string& str);

bool
has_unique_char_bit(const std::string& str);

int
main(int argc, char *argv[])
{
    const std::string test_str1 = "abcd";
    const std::string test_str2 = "abca";

    if (has_unique_char_array(test_str1)) {
        std::cout << "Array unique" << std::endl;
    }
    if (!has_unique_char_array(test_str2)) {
        std::cout << "Array not unique" << std::endl;
    }
    if (has_unique_char_bit(test_str1)) {
        std::cout << "Bit unique" << std::endl;
    }
    if (!has_unique_char_bit(test_str2)) {
        std::cout << "Bit not unique" << std::endl;
    }
    
    return 0;
}

bool
has_unique_char_array(const std::string& str)
{
    bool has_char[256] = {false};

    for (int i = 0; i < str.length(); i++) {
        if (has_char[str[i]]) {
            return false;
        } else {
            has_char[str[i]] = true;
        }
    }
    return true;
}

bool
has_unique_char_bit(const std::string& str)
{
    int char_flag = 0;

    for (int i = 0; i < str.length(); i++) {
        if ((char_flag & (0x1 << (str[i] - 'a'))) == 0) {
            char_flag |= 0x1 << (str[i] - 'a');
        } else {
            return false;
        }
    }
    return true;
}
