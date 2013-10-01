#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>
#include "binary-search-tree.hpp"

BOOST_AUTO_TEST_SUITE(create)

BOOST_AUTO_TEST_CASE(empty)
{
    BinarySearchTree<int> tree;
    BOOST_CHECK(tree.is_empty());
}

BOOST_AUTO_TEST_CASE(one_node)
{
    BinarySearchTree<int> tree(2);
    BOOST_CHECK_EQUAL(tree.root(), 2);
    BOOST_CHECK(!tree.is_empty());
}

BOOST_AUTO_TEST_CASE(from_array)
{
    char nodes[10] = {'c', 'b', 'd', 'a', 'f', 'e', 'g', 'h', 'i', 'j'};
    BinarySearchTree<char> tree(nodes, 10);
    BOOST_CHECK(!tree.is_empty());
    BOOST_CHECK_EQUAL(tree.root(), 'c');
    std::string expect_inorder = "[a, b, c, d, e, f, g, h, i, j]";
    BOOST_CHECK_EQUAL(tree.inorder_travel(), expect_inorder);
}

BOOST_AUTO_TEST_CASE(copy)
{
    BinarySearchTree<int> t1;
    BinarySearchTree<int> t2(t1);
    BOOST_CHECK(t2.is_empty());
    t2.insert(2);
    t2.insert(3);
    t2.insert(1);
    BinarySearchTree<int> t3 = t2;
    std::string expect_inorder = "[1, 2, 3]";
    BOOST_CHECK_EQUAL(t3.inorder_travel(), expect_inorder);
}

BOOST_AUTO_TEST_CASE(assign)
{
    BinarySearchTree<int> t1;
    BinarySearchTree<int> t2(t1);
    t2 = t1;
    BOOST_CHECK(t2.is_empty());
    t1.insert(2);
    t2 = t1;
    BOOST_CHECK(!t2.is_empty());
    BOOST_CHECK_EQUAL(t2.root(), 2);
    t2.insert(3);
    t2.insert(1);
    BinarySearchTree<int> t3 = t2;
    t3.insert(4);
    t1 = t2 = t3;
    std::string expect_inorder = "[1, 2, 3, 4]";
    BOOST_CHECK_EQUAL(t1.inorder_travel(), expect_inorder);
}

BOOST_AUTO_TEST_SUITE_END()

