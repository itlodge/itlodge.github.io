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

Here is the code.

{% include_code sort/bubble-sort/bubble-sort.cpp %}

And the test code(Using boost unit test framework).

{% include_code sort/bubble-sort/bubble-sort-test.cpp %}

For this test cases, the average run time is **0.9s**.

Select Sort
--------------
Just like its name, select sort is to select the smallest or the biggest
element of the rest elements every pass. This algorithm is very easy and
I can write down it with an eyes on.

Here is the code.

{% include_code sort/select-sort/select-sort.cpp %}

And the test code(Using boost unit test framework).

{% include_code sort/select-sort/select-sort-test.cpp %}

For this test cases, the average run time is **0.4s**.




