---
layout: post
title: "Some basic Ruby"
date: 2013-07-25 20:07
comments: true
sharing: true
categories: Ruby
---

String and name
------------------

When defining a function, the parentheses are not necessary.So this one

    def say_hello name
      "Hello " + name
    end
    
    puts say_hello "man"

is the same as this.

    def say_hello(name)
      "Hello " + name
    end
    
    puts(say_hello("man"))

However, when there are more than one parameters, it will be difficult to
know which argument goes with which method invocation.So it's recommended
using parentheses in all but the simplest cases.

We can use single-quote or double-quote to create a string.What's the
difference?

First, single-quoted string can't represent the escape character, and
double-quoted string can.

    puts '\nabc'
    puts "\nabc"

The above code will output this.

    \nabc

    abc

Second, double-quoted string can be expression interpolated.

    name = 'Tom'
    
    puts 'Hello #{name}'
    puts "Hello #{name}"

The above code will output this.

    ruby test.rb
    Hello #{name}
    Hello Tom

And we can even invoke methods.

    name = 'Tom'
    puts "Hello #{name.upcase}"

This will generate the following.

    Hello TOM

When the expression is a global, instance or class variable, there is no need
to use the braces.

    @h = "Hello"    # @ means instance
    $name = 'Tom'    # $ means global
    
    puts "#@h #$name"

This will generate the same output.

There are some conventions for the **name** in Ruby.

* Local variables, method parameters and method names *should* all start
with a lowercase letter or an underscore.

* Class names, module names and constants *must* start with an uppercase
letter.

* Global variables start with ``$``.

* Instance variables begin with ``@``.

* Class variables are prefixed with ``@@``.

Arrays and Hashes
------------------

In ruby, arrays and hashes can hold objects of different types.

    a = [1, 'abc', :sym]
    puts a

It will generate the following output.

    1
    abc
    sym

By the way, ``nil`` is an object, represent **nothing**.

If we want to create an array of string, we have to list all the strings.
And we have to type lots of quotes and commas.However, ``%w`` can do it
more easily.

    a = ['a', 'b', 'c']
    b = %w{a b c}
    
    puts a
    puts b

It will generate the following output.

    a
    b
    c
    a
    b
    c

The index of Array is integer, but the index of Hash is anything.

It has the following form.

    var = {
	  key1 => value1
	  key2 => value2
	  ...
	}

For example:

    girl = {
      :name => 'Mary',
      :age => 20
    }
    
    puts "#{girl[:name]} is #{girl[:age]} years old."

Output:

    Mary is 20 years old.

A new Hash can also be created in this way.

    decimal = Hash.new(0)
    puts decimal[:first]
    decimal[:first] = 1
    puts decimal[:first]

Ouput:

    0
    1

0 is the default value for all keys.

