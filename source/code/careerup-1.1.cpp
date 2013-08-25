#include <tr1/unordered_set>
#include <iostream>

bool
has_unique_char_normal(const std::string& str);

bool
has_unique_char_set(const std::string& str);

int
main(int argc, char *argv[])
{
    const std::string test_str1 = "abcd";
    const std::string test_str2 = "abca";

    if (has_unique_char_normal(test_str1)) {
        std::cout << "Normal unique" << std::endl;
    }
    if (!has_unique_char_normal(test_str2)) {
        std::cout << "Normal not unique" << std::endl;
    }
    if (has_unique_char_set(test_str1)) {
        std::cout << "Set unique" << std::endl;
    }
    if (!has_unique_char_set(test_str2)) {
        std::cout << "Set not unique" << std::endl;
    }

    return 0;
}

bool
has_unique_char_normal(const std::string& str)
{
    for (int i = 0; i < str.length(); i++) {
        for (int j = i + 1; j < str.length(); j++) {
            if (str[i] == str[j]) {
                return false;
            }
        }
    }
    return true;
}

bool
has_unique_char_set(const std::string& str)
{
    typedef std::tr1::unordered_set<char> Set;
    Set set;
    
    for (int i = 0; i < str.length(); i++) {
        if (set.count(str[i]) == 0) {
            set.insert(str[i]);
        } else {
            return false;
        }
    }
    return true;
}
