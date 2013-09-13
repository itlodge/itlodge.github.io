#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE replace

#include <boost/test/unit_test.hpp>
#include <iostream>

void
replace(std::string& str);

BOOST_AUTO_TEST_CASE(replace_space)
{
    std::string test_str = "a b c";
    replace(test_str);
    BOOST_CHECK_EQUAL(test_str, "a%20b%20c");
}

void
replace(std::string& str)
{
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == ' ') {
            str.replace(i, 1, "%20", 3);
            i += 2;
        }
    }
}


