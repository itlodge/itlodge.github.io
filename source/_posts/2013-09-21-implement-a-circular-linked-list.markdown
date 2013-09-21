---
layout: post
title: "Implement a circular linked list"
date: 2013-09-21 21:57
comments: true
sharing: true
categories: Data_structure Interview
---

A circular linked list is the same as a singular linked list except that
there last node points to the first node.

Here is the specification of my CiLinkedList.

* ``CiLinkedList()``, Create an empty CiLinkedList.
* ``CiLinkedList(const CiLinkedList& list)``, Create a CiLinkedList from another
CiLinkedList ``list``.
* ``CiLinkedList(const T& value)``, Create a CiLinkedList whose first element
is ``value``.
* ``CiLinkedList(const T values[], size_t size)``, Create a CiLinkedList from
an array ``values`` of size ``size``.
* ``const CiLinkedList& operator=(const CiLinkedList& list)``, Support
CiLinkedList assignment.
* ``~CiLinkedList()``, Free all the space requested by the CiLinkedList.
* ``std::ostream& operator<< <> (std::ostream&, const CiLinkedList<T>&);``,
Output the CiLinkedList in the form **[a, b, c ...]**.
* ``const T& operator[](size_t index)``, Access the element of the CiLinkedList,
but it's not random accessible.
* ``size_t size()``, Return the size of the CiLinkedList.
* ``rm_dup()``, Remove duplicate elements int the CiLinkedList.

Here is the code.

The class definition.

{% include_code circular-list/cilist.h lang:cpp %}

And the class implementation.

{% include_code circular-list/cilist.cpp %}

Now this the test code(Using boost unit test framework).

{% include_code circular-list/cilist_test.cpp %}
