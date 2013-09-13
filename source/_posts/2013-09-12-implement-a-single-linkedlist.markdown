---
layout: post
title: "Implement a single LinkedList"
date: 2013-09-12 09:56
comments: true
sharing: true
categories: C++ Interview
---

LinkedList is a very common data structure. Three years ago, I could write
a single LinkedList very quickly in C/C++. But the code is ugly and very
ineffecient. Now I am going to implement a single LinkedList in C++ in order
to cracking the interview.

Here is the specification of my LinkedList.

* ``LinkedList()``, Create an empty LinkedList.
* ``LinkedList(const LinkedList& list)``, Create a LinkedList from another
LinkedList ``list``.
* ``LinkedList(const T& value)``, Create a LinkedList whose first element
is ``value``.
* ``LinkedList(const T values[], size_t size)``, Create a LinkedList from
an array ``values`` of size ``size``.
* ``const LinkedList& operator=(const LinkedList& list)``, Support LinkedList
assignment.
* ``~LinkedList()``, Free all the space requested by the LinkedList.
* ``friend std::ostream& operator<< <> (std::ostream&, const LinkedList<T>&);``,
Output the LinkedList in the form **[a, b, c ...]**.
* ``void append(const T& value)``, Append an element ``value`` to the LinkedList.
* ``const T& operator[](size_t index)``, Access the element of the LinkedList,
but it's not random accessible.
* ``void insert(size_t index, const T& value)``, Insert an element ``value``
in the position ``index``.
* ``void remove(size_t index)``, Remove the element in the position ``index``.
* ``size_t size()``, Return the size of the LinkedList.
* ``void reverse()``, Reverse the whole LinkedList.
* ``void sort()``, Sort the whole LinkedList using merge sort.

Here is the code.

The class definition.

{% include_code careerup-list.h lang:cpp %}

And the class implementation.

{% include_code careerup-list.cpp %}

Now this the test code(Using boost unit test framework).

{% include_code careerup-list-test.cpp %}

