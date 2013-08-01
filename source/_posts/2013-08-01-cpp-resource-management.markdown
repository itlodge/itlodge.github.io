---
layout: post
title: "Cpp Resource Management"
date: 2013-08-01 22:16
comments: true
sharing: true
categories: C++
---

I always forget freeing a memory that allocated from the heap.And I always
forget closing the file handler.

Resources include file descriptors, mutex locks, fonts, brushes, database
connections and network sockets.

I think less programmers can remember closing a file handler, especially
in a large project.

Nowadays, many programming languages have the garbage collection function.
In C++, since the destructor will be automatically called, we can release
the resources automatically if we put the resource into an object.

How can do that?Use the *smart pointer*:``std::auto_ptr``.

    #include <cstdio>
    #include <memory>
    
    int
    main(int argc, char **argv)
    {
        int *num = NULL;
        {
    	    num = new int();
    		std::auto_ptr<int> ap(num);
        }
        // delete num;
        
        return 0;
    }
        
If trying to delete num after the block, that will be a double free error.

Reference from [cplusplus.com](http://www.cplusplus.com/reference/memory/auto_ptr/), ``auto_ptr`` is deprecated in C++11 and is replaced by ``unique_ptr``.
But they are similar.

However, multiple ``auto_ptr`` cannot contain the same object.

Here is the test program.

    #include <cstdio>
    #include <memory>
    
    int
    main(int argc, char **argv)
    {
        int *num = NULL;
        {
    	    num = new int();
    		std::auto_ptr<int> ap1(num);
    		std::auto_ptr<int> ap2(ap1);
    
            printf("%p\n", &ap1);
    		ap1 = ap2;
    		printf("%p\n", &ap2);
        }
        // delete num;
        
        return 0;
    }

And here is the gdb debug output information.

    Temporary breakpoint 1, main (argc=1, argv=0x7fffffffe6e8) at test.cpp:7
    7	    int *num = NULL;
    (gdb) n
    9		num = new int();
    (gdb) n
    10		std::auto_ptr<int> ap1(num);
    (gdb) n
    11		std::auto_ptr<int> ap2(ap1);
    (gdb) p ap1
    $1 = {_M_ptr = 0x601010}
    (gdb) p ap2
    $2 = {_M_ptr = 0x7fff00000001}
    (gdb) n
    13		printf("%p\n", &ap1);
    (gdb) p ap1
    $3 = {_M_ptr = 0x0}
    (gdb) p ap2
    $4 = {_M_ptr = 0x601010}
    (gdb) n
    0x7fffffffe5e0
    14		ap1 = ap2;
    (gdb) p ap1
    $5 = {_M_ptr = 0x0}
    (gdb) p ap2
    $6 = {_M_ptr = 0x601010}
    (gdb) n
    15		printf("%p\n", &ap2);
    (gdb) p ap1
    $7 = {_M_ptr = 0x601010}
    (gdb) p ap2
    $8 = {_M_ptr = 0x0}
    (gdb) 

But there are another smart pointer that can do this.It's the
``std::tr1::shared_ptr``.Mutiple shared_ptr can contain the same object.

The testing program is as follow.

    #include <cstdio>
    #include <tr1/memory>
    
    int
    main(int argc, char **argv)
    {
        int *num = NULL;
        {
    	    num = new int();
    		std::tr1::shared_ptr<int> ap1(num);
    		std::tr1::shared_ptr<int> ap2(ap1);
    
    	    printf("%p\n", &ap1);
    		ap1 = ap2;
    		printf("%p\n", &ap2);
        }
        
        return 0;
    }
        
And the gdb debug information is:

    Temporary breakpoint 1, main (argc=1, argv=0x7fffffffe6e8) at test.cpp:7
    7	    int *num = NULL;
    (gdb) n
    9		num = new int();
    (gdb) n
    10		std::tr1::shared_ptr<int> ap1(num);
    (gdb) n
    11		std::tr1::shared_ptr<int> ap2(ap1);
    (gdb) n
    13		printf("%p\n", &ap1);
    (gdb) p ap1
    $1 = std::tr1::shared_ptr (count 2, weak 0) 0x602010
    (gdb) p ap2
    $2 = std::tr1::shared_ptr (count 2, weak 0) 0x602010
    (gdb) n
    0x7fffffffe5d0
    14		ap1 = ap2;
    (gdb) n
    15		printf("%p\n", &ap2);
    (gdb) p ap1
    $3 = std::tr1::shared_ptr (count 2, weak 0) 0x602010
    (gdb) p ap2
    $4 = std::tr1::shared_ptr (count 2, weak 0) 0x602010

We can see that both of ``ap1`` and ``ap2`` point to the same object.

The ``auto_ptr`` and ``shared_ptr`` use ``delete`` but not ``delete[]``,
so they don't support array.But the ``unique_ptr`` support.

