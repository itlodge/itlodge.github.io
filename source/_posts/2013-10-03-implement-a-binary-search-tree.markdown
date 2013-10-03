---
layout: post
title: "Implement a binary search tree"
date: 2013-10-03 15:43
comments: true
sharing: true
categories: Interview Data_structure
---

A binary search tree is very useful in solving the real world problems. The
red-black tree is one kind of binary search tree. For more information about
binary search tree, please visit the [wikipedia](http://en.wikipedia.org/wiki/Binary_search_tree).

Here is the specification of my binary search tree.

* ``BinarySearchTree()``, Create an empty binary search tree.

* ``BinarySearchTree(const T& root_val)``, Create an binary search tree whose
root node is constructed from ``root_val``.

* ``BinarySearchTree(const T values[], const size_t& size)``, Create an binary
search tree from an array ``values``.

* ``BinarySearchTree(const BinarySearchTree<T>& tree)``, Create an binary search
tree from the other tree ``tree``.

* ``const BinarySearchTree& operator=(const BinarySearchTree& tree)``, Support
assignment between trees.

* ``~BinarySearchTree()``, free all the spaces.

* ``Node<T> * proot() const``, return the root pointer.

* ``void proot(Node<T> *root)``, set the root pointer to ``root``.

* ``const T& root() const``, return the data stored in the root node.

* ``bool is_empty() const``, return whether the tree is empty.

* ``void insert(const T& value)``, insert a node with ``value`` into the tree.

* ``std::string inorder_string() const``, return the inorder travel string.

* ``std::vector<T> retrieve(const T& key)``, return the search result of key
``key``, the result may contain more than one element.

* ``void remove(const T& key)``, delete the node with key ``key``.

Here is the code.

The class definition and implementation.

{% include_code binary-search-tree/binary-search-tree.hpp lang:cpp %}

Now this the test code(Using boost unit test framework).

{% include_code binary-search-tree/binary-search-tree-test.cpp %}

