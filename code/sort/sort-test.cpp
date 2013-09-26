#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <boost/test/unit_test.hpp>
#include "sort.cpp"

int empty_list[0];

const int NORMAL_SIZE = 5;
int normal_list[NORMAL_SIZE] = {5, 1, 4, 2, 8};
int normal_list_sorted[NORMAL_SIZE] = {1, 2, 4, 5, 8};

const int RANDOM_SIZE = 9999;

BOOST_AUTO_TEST_SUITE(bubble)

BOOST_AUTO_TEST_CASE(empty)
{
    bubble_sort(empty_list, 0);
}

BOOST_AUTO_TEST_CASE(normal)
{
    bubble_sort(normal_list, NORMAL_SIZE);
    for (int i = 0; i < NORMAL_SIZE; ++i) {
        BOOST_CHECK_EQUAL(normal_list[i], normal_list_sorted[i]);
    }
}

BOOST_AUTO_TEST_CASE(random)
{
    int random_list[RANDOM_SIZE];
    int random_list_sorted[RANDOM_SIZE];
    srand(time(NULL));
    for (int i = 0; i < RANDOM_SIZE; ++i) {
        random_list[i] = random_list_sorted[i] = rand();
    }
    bubble_sort(random_list, RANDOM_SIZE);
    std::sort(random_list_sorted, random_list_sorted + RANDOM_SIZE);
    for (int i = 0; i < RANDOM_SIZE; ++i) {
        BOOST_CHECK_EQUAL(random_list[i], random_list_sorted[i]);
    }
}


BOOST_AUTO_TEST_SUITE_END()

