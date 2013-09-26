---
layout: post
title: "Implement the sorting algorithms"
date: 2013-09-26 22:03
comments: true
sharing: true
categories: Algorithm Interview
---

The sorting algorithms are very important in programming interview. I have
to be able to write them on a paper without even an error.

Bubble Sort
---------------
The immediate thought of bubble sort is that swapping the ajacent elements
if they are of the wrong order in each pass until there are no swapping.
For example, consider the array ``[5, 1, 4, 2, 8]``,

First pass:

[5, 1, 4, 2, 8] => [1, 5, 4, 2, 8] => [1, 4, 5, 2, 8] => [1, 4, 2, 5, 8]
=> [1, 4, 2, 5, 8]

Second pass:

[1, 2, 4, 5, 8] => [1, 2, 4, 5, 8] => [1, 2, 4, 5, 8] => [1, 2, 4, 5, 8]
=> [1, 2, 4, 5, 8]

Third pass:

[1, 2, 4, 5, 8] => [1, 2, 4, 5, 8] => [1, 2, 4, 5, 8] => [1, 2, 4, 5, 8]
=> [1, 2, 4, 5, 8]

Here we found that the array has been sorted after the second pass, but we
have apply the third pass so that we can know the array has been sorted
because there are no swapping in that pass.

There is an optimization that can improve the performance. Observer that
in the second pass, there is no need to compare ``5`` to ``8``, since they
are in the right order in the first pass. Hence, there is no need to compare
the last ``ith`` element in the ``ith`` pass.

Select Sort
--------------


All the code
---------------

Here is the code of all this sort algorithms.

{% include_code sort/sort.cpp %}

And the test code(Using boost unit test framework).

{% include_code sort/sort-test.cpp %}
