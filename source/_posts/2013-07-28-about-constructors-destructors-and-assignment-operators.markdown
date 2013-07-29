---
layout: post
title: "About Constructors Destructors and Assignment Operators"
date: 2013-07-28 18:32
comments: true
sharing: true
categories: C++
---

What functions C++ will silently write and call?
--------------------------------------------------

If we declare an empty class, the compiler will declare a constructor,
a copy constructor, a copy assignment operator and a destructor for us.

    class Girl {

    };

But the compiler is not foolish, it will only generate them when needed.

What do the generated functions do?

* For construtor, it will invoke the corresponding constructor and non-static
members of its base class.

* For destructor, it will invoke the corresponding destructor of its base class.
If its base class's destructor is virtual, the destructor will declare as
virtual.

* For copy constructor and copy assignment operator, they will copy each
non-static data member from the source object to the target object.

If the class has some members that are pointer, reference or constant, there
will be some trouble with the compiler.Therefore, always define the four
functions when we define our own class.

Disallow the use of generated functions you don't want
---------------------------------------------------------

Sometimes, we may not want the copy constructor or the copy assignment
operator because every member may be different with the other object's
members.Preventing the generation of these functions will make the
program more effecient.

If we don't declare these two functions, the compiler will generate them
for us.

So how can we do?

The prefer solution is **declare the copy constructor and copy assignment**
**operator as private and never implement them**.

If we implement them, the members and friends of the class can call them.But
if we don't implement them, the linker will complain at it.

In order to move the link-time error to the compile time, we should let the
members and the friends of the class cannot call them.One method is to define
a base class that can't be copied and inherited by the class that you don't
want it to be copyable.

    class Uncopyable {
	protected:
	    Uncopyable()
		{ }
		~Uncopyable()
		{ }
	private:
	    Uncopyable(const Uncopyable&);
		Uncopyable& operator=(const Uncopyable&);
	};

    class Person: private Uncopyable {

    };

The copy constructor and copy assignment operator of the class ``Uncopyable``
are declared as private, so the members and friends of class ``Person`` can't
call them.


Declare destructors virtual in polymorphic base classes
---------------------------------------------------------

I have met this problem in an interview.

Suppose the destructor of the base class is not virtual.

    class Dog {
	public:
	    Dog();
		~Dog();
	};

And there are two class inherited from it.

    class Whippet:public Dog {

    };

    class Spaniel:public Dog {

    };

We can use a base class pointer to handle the derived classes.

    Dog *aDog = new Whippet();
	...

Then you should delete the pointer when you want to quit.

    delete aDog;

Now, the problem appears.The C++ specifies that when a derived class
object is deleted through a pointer to a base class with a non-virtual
destructor, results are undefined.

That is, the destructor of the base class will be called typically, but
the destructor of the derived class may not be called.

I have written a simple program to test it.

    #include <cstdio>
    
    class Dog {
    public:
        Dog()
        { }
        ~Dog()
        {
    	    printf("Call Dog's destructor\n");
        }
    private:
        Dog(const Dog&);
        Dog&
        operator=(const Dog&);
    };
    
    class Whippet:public Dog {
    public:
        Whippet()
        { }
        ~Whippet()
        {
    	    printf("Call Whippet's destructor\n");
        }
    };
    
    int
    main(int argc, char **argv)
    {
        Dog *aDog = new Whippet();
        delete aDog;
    
        return 0;
    }
        
I run the program several times and the results are the same.

    ~/test $ ./test 
	Call Dog's destructor

Now, if I change the destrutor to ``virtual``, the result is:

    virtual ~Dog()
    {
	    printf("Call Dog's destructor\n");
    }

    ~/test $ ./test 
	Call Whippet's destructor
	Call Dog's destructor

Therefore, when the base class have virtual member functions, you should
always make the destructor virtual.

However, not every destructor of any class should be virtual.Making it
virtual will occupy some additional information(virtual table pointer)
that can increase the size of an object of that class.

