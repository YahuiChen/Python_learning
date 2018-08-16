#ifndef STACK_HPP__
#define STACK_HPP__

template< typename Object >
class Stack {
public:
    Stack(const int size = 0)
    {
        init(size);
    }

    const int size() const { return theSize; }
    bool empty() const { return theSize == 0; }
    const int capacity() const { return theCapacity; }

    void push(const Object& val)
    {
        if (theSize == theCapacity)
            reserve(2 * theCapacity + 1);

        objects[theSize++] = val;
    }

    void pop()
    {
        if (theSize > 0)
            --theSize;
    }

    Object top()
    {
        return objects[size() - 1];
    }

private:
    void resize(const int newSize)
    {
        if (newSize > theCapacity)
            reserve(newSize * 2 + 1);
        theSize = newSize;
    }

    void reserve(const int newCapacity)
    {
        if (newCapacity < theSize)
            return;

        Object* old = objects;

        objects = new Object[newCapacity];

        for (int i = 0; i < theSize; ++i)
            objects[i] = old[i];

        theCapacity = newCapacity;

        delete[] old;
    }

    void init(const int size)
    {
        objects = new Object[size + SPARE_CAPACITY];
        theSize = 0;
        theCapacity = size + SPARE_CAPACITY;
    }

    Stack(const Stack&);
    Stack& operator=(const Stack&);

    Object* objects;
    int theSize;
    int theCapacity;
    enum { SPARE_CAPACITY = 16 };
};

#endif