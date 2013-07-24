---
layout: post
title: "Const anyway!"
date: 2013-07-24 20:01
comments: true
sharing: true
categories: C++
---

``const`` is versatile.I am always confused by the following syntax.

    const char *str = "Hello";    // const data, non-const pointer
	char * const str = "Hello";    // const pointer, non-const data

Now there is a tip to remember it.

If ``const`` appears to the right of the asterisk, the pointer is
constant.If ``const`` appears to the left of the asterisk, the data
is constant.

So the following two statements are the same.

    const char *str = "Hello";
	char const *str = "Hello";

In STL, ``iterator`` is just like a ``T *`` pointer.
* ``const std::vector<int>::iterator iter`` is just like ``T * const iter``.
* ``std::vector<int>::const_iterator cIter`` is just like ``const T *iter``.

So, in a loop, if we don't want to modify the data, use ``const_iterator``.


