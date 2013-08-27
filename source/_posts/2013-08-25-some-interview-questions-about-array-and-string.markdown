---
layout: post
title: "Some interview questions about array and string"
date: 2013-08-25 08:43
comments: true
sharing: true
categories: interview, C++
---

Hash Table
------------
In C++, the namespace``std::tr1`` contains lots of hash tables. We can play
with it.

{% include_code careerup-hash.cpp %}

Questions
-----------
**1.1.** Implement an algorithm to determine if a string has all unique
characters. What if you can not use additional data structures?

I have come up with 2 methods.

* Iterate the string and compare each character to other character. This is the
common way to solve this problem. It will cost (O ^ 2) time.

* Use the ``std::tr1::unordered_set`` data structure so that we can only iterate
the string once.

Here is the code.

{% include_code careerup-1.1.cpp %}

However, there are two more effecient methods.

* If the string contains only ASCII(Ask the interviewer!), we can use an array
of size 256 to mark every character. The time complexity is O(n). But this is
to sacrifice space for time, just as the unordered_set method.

* If the string contains only letters, we can use a 4-bytes integer to mark the
characters in the string.

Here is the code.

{% include_code careerup-1.1-answer.cpp %}

**1.2.** Write code to reverse a C-Style String(C-String means that "abcd" is
represented as five characters, including the null character)

The approach I come up with is described as follows.

1. Get the length of the string, which needs iterate the whole string.

2. According to the property of continuing, we can manipulate the string
from the end. So we can swap the first character with the last character,
and swap the second character with the last but not least character, ...
This needs iterate half of the string.

In sumary, this will need O(1.5n) -> O(n) time complexity. Here is the code.

{% include_code careerup-1.2.cpp %}

However, the answer is using pointer instead of index. But the algorithm and
the time complexity are the same. Here is the code.

{% include_code careerup-1.2-answer.cpp %}

This code has several problems. First, the variable ``end`` and ``tmp`` should
be defined in the ``if`` block. Otherwise, if ``str`` is ``NULL``, the
definition of the two variables will be wasteful. Second, using the pointer with
the ``++`` and ``--`` is error-prone.




