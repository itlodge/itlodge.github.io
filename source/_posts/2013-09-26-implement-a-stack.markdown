---
layout: post
title: "Implement a stack"
date: 2013-09-26 21:10
comments: true
sharing: true
categories: Data_structure, Interview
---

A stack is based on the Linked List. The most explicit feature of a stack
is FILO(First in last out).

Here is the specification of my Stack.

* ``Stack()``, Create an empty stack.
* ``Stack(const T& value)``, Create a stack whose first element is ``value``.
* ``Stack(const T values[], const size_t& size)``, Create a stack from an
array ``values`` whose size is ``size``.
* ``Stack(const Stack<T>& stack)``, Create a stack from another stack.
* ``const Stack<T>& operator=(const Stack<T>& stack)``, Support stack
assignment.
* ``~Stack()``, Free all the spaces allocated by the stack.
* ``std::ostream& operator<< <> (std::ostream& os, const Stack<T>& stack)``,
Output the stack in the form **[1 | 2 | 3]**.
* ``const T& top() const``, return the head element of the stack.
* ``size_t size() const``, return the size of the stack.
* ``void push(const T& value)``, append the element ``value`` into the
back of the stack.
* ``const T pop()``, remove and return the first element of the stack.
* ``Node<T> * ptop() const``, return the top pointer.

Here is the code.

The class definition and Implementation.

{% include_code stack/stack.hpp lang:cpp %}

Now this the test code(Using boost unit test framework).

{% include_code stack/stack-test.cpp %}
