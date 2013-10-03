#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>
#include "binary-search-tree.hpp"

BOOST_AUTO_TEST_SUITE(type)

BOOST_AUTO_TEST_CASE(empty)
{
    BinarySearchTree<int> tree;
    BOOST_CHECK(tree.is_empty());
    tree.insert(2);
    BOOST_CHECK(!tree.is_empty());
    BOOST_CHECK_EQUAL(tree.root(), 2);
}

BOOST_AUTO_TEST_CASE(one_node)
{
    BinarySearchTree<int> tree(2);
    BOOST_CHECK_EQUAL(tree.root(), 2);
    BOOST_CHECK(!tree.is_empty());
    tree.remove(2);
    BOOST_CHECK(tree.is_empty());
}

BOOST_AUTO_TEST_CASE(from_array)
{
    char nodes[10] = {'c', 'b', 'd', 'a', 'f', 'e', 'g', 'h', 'i', 'b'};
    BinarySearchTree<char> tree(nodes, 10);
    BOOST_CHECK(!tree.is_empty());
    BOOST_CHECK_EQUAL(tree.root(), 'c');
    std::string expect_inorder = "[a, b, b, c, d, e, f, g, h, i]";
    BOOST_CHECK_EQUAL(tree.inorder_string(), expect_inorder);

    std::vector<char> result = tree.retrieve('b');
    BOOST_CHECK_EQUAL(result.size(), 2);
    BOOST_CHECK_EQUAL(result[0], 'b');
    BOOST_CHECK_EQUAL(result[1], 'b');
    
    tree.remove('b');
    expect_inorder = "[a, c, d, e, f, g, h, i]";
    BOOST_CHECK_EQUAL(tree.inorder_string(), expect_inorder);
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
    BOOST_CHECK_EQUAL(t3.inorder_string(), expect_inorder);

    t3.remove(3);
    BOOST_CHECK_EQUAL(t3.inorder_string(), "[1, 2]");
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
    BOOST_CHECK_EQUAL(t1.inorder_string(), expect_inorder);

    t1.remove(3);
    BOOST_CHECK_EQUAL(t1.inorder_string(), "[1, 2, 4]");
}

BOOST_AUTO_TEST_CASE(remove)
{
    char nodes[10] = {'c', 'b', 'd', 'a', 'f', 'e', 'g', 'h', 'i', 'b'};
    BinarySearchTree<char> tree(nodes, 10);

    tree.remove('f');
    std::string expect_inorder = "[a, b, b, c, d, e, g, h, i]";
    BOOST_CHECK_EQUAL(tree.inorder_string(), expect_inorder);

    tree.remove('i');
    expect_inorder = "[a, b, b, c, d, e, g, h]";
    BOOST_CHECK_EQUAL(tree.inorder_string(), expect_inorder);

    tree.remove('a');
    expect_inorder = "[b, b, c, d, e, g, h]";
    BOOST_CHECK_EQUAL(tree.inorder_string(), expect_inorder);

    tree.remove('c');
    expect_inorder = "[b, b, d, e, g, h]";
    BOOST_CHECK_EQUAL(tree.inorder_string(), expect_inorder);

    tree.remove('g');
    expect_inorder = "[b, b, d, e, h]";
    BOOST_CHECK_EQUAL(tree.inorder_string(), expect_inorder);

    tree.remove('d');
    expect_inorder = "[b, b, e, h]";
    BOOST_CHECK_EQUAL(tree.inorder_string(), expect_inorder);

    tree.remove('h');
    expect_inorder = "[b, b, e]";
    BOOST_CHECK_EQUAL(tree.inorder_string(), expect_inorder);

    tree.remove('e');
    expect_inorder = "[b, b]";
    BOOST_CHECK_EQUAL(tree.inorder_string(), expect_inorder);

    tree.remove('b');
    expect_inorder = "[]";
    BOOST_CHECK_EQUAL(tree.inorder_string(), expect_inorder);
}


BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(record)

class Record {
public:
    explicit Record()
        :key_(0), value_("")
    { }

    explicit Record(int key, const std::string& value="")
        :key_(key), value_(value)
    { }

    explicit Record(const Record& record)
        :key_(record.key_), value_(record.value_)
    { }

    const Record&
    operator=(const Record& record)
    {
        this->key_ = record.key_;
        this->value_ = record.value_;

        return *this;
    }

    ~Record() { }

    friend bool
    operator<(const Record& left, const Record& right)
    { return left.key_ < right.key_; }

    friend bool
    operator<=(const Record& left, const Record& right)
    { return left.key_ <= right.key_; }

    friend bool
    operator==(const Record& left, const Record& right)
    { return left.key_ == right.key_; }

    friend bool
    operator>=(const Record& left, const Record& right)
    { return left.key_ >= right.key_; }

    friend bool
    operator>(const Record& left, const Record& right)
    { return left.key_ > right.key_; }

    void
    key(int k)
    { this->key_ = k; }

    void
    value(const std::string& v)
    { this->value_ = v; }

    const std::string&
    value() const
    { return this->value_; }
    
    friend std::ostream&
    operator<<(std::ostream& os, const Record& record)
    { return (os << record.value_); }
private:
    int key_;
    std::string value_;
};

std::string names[5] = {"Dennis Ritchie", "Bjarne Stroustrup", "Don Knuth",
                        "Linus Torvald", "Richard Stallman"};

BOOST_AUTO_TEST_CASE(search)
{
    BinarySearchTree<Record> tree;
    BOOST_CHECK(tree.is_empty());
    Record record(2, names[1]);
    tree.insert(record);
    BOOST_CHECK_EQUAL(tree.root(), record);
    record.key(3);
    record.value(names[2]);
    tree.insert(record);
    
    record.key(5);
    record.value(names[4]);
    tree.insert(record);

    record.key(1);
    record.value(names[0]);
    tree.insert(record);

    record.key(4);
    record.value(names[3]);
    tree.insert(record);

    std::string expect_inorder = "[Dennis Ritchie, Bjarne Stroustrup, "
        "Don Knuth, Linus Torvald, Richard Stallman]";
    BOOST_CHECK_EQUAL(tree.inorder_string(), expect_inorder);

    Record key(2);
    std::vector<Record> result = tree.retrieve(key);
    BOOST_CHECK_EQUAL(result.size(), 1);
    BOOST_CHECK_EQUAL(result[0].value(), "Bjarne Stroustrup");
}

BOOST_AUTO_TEST_SUITE_END()

