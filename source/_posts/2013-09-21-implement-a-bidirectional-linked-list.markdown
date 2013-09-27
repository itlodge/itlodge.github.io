---
layout: post
title: "Implement a bidirectional linked list"
date: 2013-09-21 12:11
comments: true
sharing: true
categories: Data_structure Interview
---

A bidirectional linked list is the same as a singular linked list except that
there are two links between two nodes.

Here is the specification of my BiLinkedList.

* ``BiLinkedList()``, Create an empty BiLinkedList.
* ``BiLinkedList(const BiLinkedList& list)``, Create a BiLinkedList from another
BiLinkedList ``list``.
* ``BiLinkedList(const T& value)``, Create a BiLinkedList whose first element
is ``value``.
* ``BiLinkedList(const T values[], size_t size)``, Create a BiLinkedList from
an array ``values`` of size ``size``.
* ``const BiLinkedList& operator=(const BiLinkedList& list)``, Support
BiLinkedList assignment.
* ``~BiLinkedList()``, Free all the space requested by the BiLinkedList.
* ``std::ostream& operator<<(std::ostream&, const BiLinkedList<T>&);``,
Output the BiLinkedList in the form **[a, b, c ...]**.
* ``void append(const T& value)``, Append an element ``value`` to the
BiLinkedList.
* ``const T& operator[](size_t index)``, Access the element of the BiLinkedList,
but it's not random accessible.
* ``void insert(size_t index, const T& value)``, Insert an element ``value``
in the position ``index``.
* ``void remove(size_t index)``, Remove the element in the position ``index``.
* ``size_t size()``, Return the size of the BiLinkedList.

Here is the code.

The class definition and implementation.

{% include_code bidirectional-list/bilist.hpp lang:cpp %}

Now this the test code(Using boost unit test framework).

{% include_code bidirectional-list/bilist-test.cpp %}
