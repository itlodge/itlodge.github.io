---
layout: post
title: "Implement a queue using two stacks"
date: 2013-09-27 23:05
comments: true
sharing: true
categories: Data_structure Interview
---

A queue can be implemented using two stacks. One stack store the elements
appended to the queue. The other stack store the elements to be popped from
the queue.

Here is the specification of my Queue.

* ``StQueue()``, Create an empty queue.
* ``StQueue(const T& value)``, Create a queue whose first element is
``value``.
* ``StQueue(const T values[], const size_t& size)``, Create a queue from an
array ``values`` whose size is ``size``.
* ``StQueue(const StQueue<T>& queue)``, Create a queue from another queue.
* ``const StQueue<T>& operator=(const StQueue<T>& queue)``, Support queue
assignment.
* ``~StQueue()``, Free all the spaces allocated by the queue.
* ``std::ostream& operator<<(std::ostream& os, const StQueue<T>& queue)``,
Output the queue in the form **[1 | 2 | 3]**.
* ``const T& head() const``, return the head element of the queue.
* ``size_t size() const``, return the size of the queue.
* ``void enQueue(const T& value)``, append the element ``value`` into the
back of the queue.
* ``const T deQueue()``, remove and return the first element of the queue.

Here is the code.

The class definition and implementation.

{% include_code st-queue/st-queue.hpp lang:cpp %}

Now this the test code(Using boost unit test framework).

{% include_code st-queue/st-queue-test.cpp %}
