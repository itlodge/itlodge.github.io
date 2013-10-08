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
=================
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
==================
Just like its name, select sort is to select the smallest or the biggest
element of the rest elements every pass. This algorithm is very easy and
I can write down it with an eyes on.

Here is the code.

{% include_code sort/select-sort/select-sort.cpp %}

And the test code(Using boost unit test framework).

{% include_code sort/select-sort/select-sort-test.cpp %}

For this test cases, the average run time is **0.4s**.

Insert sort
=================
Just like playing poker, insert-sort will insert an element in a position
of a sorted subsequence by moving the not-match elements backward. In the
worst case, the time complexity is O(n^2). However, if the list is already
sorted, it requires only O(n) time complexity.

Here is the code.

{% include_code sort/insert-sort/insert-sort.cpp %}

And the test code(Using boost unit test framework).

{% include_code sort/insert-sort/insert-sort-test.cpp %}

For this test cases, the average run time is also **0.22s**.

Shell sort
=================
Shell sort is one kind of insert sort. The idea that relatively sorted list can
be sorted more easy is used in shell sort. It will sort the list for several
times and each time with some of the elements. These elements is divided by
a fixed **gap** and the gap will decrease until becoming 1. If the gap is 1,
it's the same as the insert sort. But now it will be more fast than the original
insert sort.

Here is the code.

{% include_code sort/shell-sort/shell-sort.cpp %}

And the test code(Using boost unit test framework).

{% include_code sort/shell-sort/shell-sort-test.cpp %}

For this test cases, the average run time is also **0.18s**.

Quick Sort
=================
This is the most important algorithm in the interview. I must learn to write
it on a paper with an eye on.

Recursive version
---------------------
Select an element as the one to be compared(so-called **pivot**), and then put
it at the end of the list. Iterate the whole list and let those elements that
are smaller(larger) than the pivot in a part, the others in another part. Do
the same work recursively in the two parts.

{% include_code sort/quick-sort/quick-sort.cpp %}

And the test code(Using boost unit test framework).

{% include_code sort/quick-sort/quick-sort-test.cpp %}

For this test cases, the average run time is **0.07s**.

Iterate version
---------------------
The recursive version is just the depth-first search, so we can change it
into stack operation.

{% include_code sort/quick-sort/quick-sort-iter.cpp %}

And the test code(Using boost unit test framework).

{% include_code sort/quick-sort/quick-sort-iter-test.cpp %}

For this test cases, the average run time is also **0.07s**.

Summary
=================
Here is the running time of these sorting algorithm with the same test cases.

<table>
  <th><tr>
    <td>Algorithm</td><td>Best time complexity</td>
    <td>Average time complexity</td><td>Worst time complexity</td>
    <td>Running time</td>
  </tr></th>
  <tr>
    <td>Bubble Sort</td><td>O(n)</td><td>O(n^2)</td><td>O(n^2)</td>
    <td>0.9s</td>
  </tr>
  <tr>
    <td>Select Sort</td><td>O(n^2)</td><td>O(n^2)</td><td>O(n^2)</td>
    <td>0.4s</td>
  </tr>
  <tr>
    <td>Insert Sort</td><td>O(n)</td><td>O(n^2)</td><td>O(n^2)</td>
    <td>0.22s</td>
  </tr>
  <tr>
    <td>Shell Sort</td><td>O(n)</td><td>O(n^2)</td><td>O(n^2)</td>
    <td>0.18s</td>
  </tr>
  <tr>
    <td>Quick Sort</td><td>O(nlog(n))</td><td>O(nlog(n))</td><td>O(n^2)</td>
    <td>0.07s</td>
  </tr>
</table>

  
