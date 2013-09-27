---
layout: post
title: "Implement a queue"
date: 2013-09-25 22:54
comments: true
sharing: true
categories: Data_structure, Interview
---

A queue is based on the Linked List. The most explicit feature of a queue
is FIFO(First in first out).

Here is the specification of my Queue.

* ``Queue()``, Create an empty queue.
* ``Queue(const T& value)``, Create a queue whose first element is
``value``.
* ``Queue(const T values[], const size_t& size)``, Create a queue from an
array ``values`` whose size is ``size``.
* ``Queue(const Queue<T>& queue)``, Create a queue from another queue.
* ``const Queue<T>& operator=(const Queue<T>& queue)``, Support queue
assignment.
* ``~Queue()``, Free all the spaces allocated by the queue.
* ``std::ostream& operator<< <> (std::ostream& os, const Queue<T>& queue)``,
Output the queue in the form **[1 | 2 | 3]**.
* ``const T& head() const``, return the head element of the queue.
* ``size_t size() const``, return the size of the queue.
* ``void enQueue(const T& value)``, append the element ``value`` into the
back of the queue.
* ``const T deQueue()``, remove and return the first element of the queue.

Here is the code.

The class definition and implementation.

{% include_code queue/queue.hpp lang:cpp %}

Now this the test code(Using boost unit test framework).

{% include_code queue/queue-test.cpp %}






