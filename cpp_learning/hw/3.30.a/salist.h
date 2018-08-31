#ifndef SALIST_HPP__
#define SALIST_HPP__

template< typename Object >
class SelfAdjustList {
public:
    SelfAdjustList() : objects(new Object[INIT_CAPACITY]),
        theSize(0)
    {}

    ~SelfAdjustList()
    {
        delete[] objects;
    }

    const int find(const Object& val) const
    {
        for (int i = 0; i < theSize; ++i)
        {
            if (objects[i] == val)
            {
                Object temp = objects[i];
                for (int j = i; j < theSize - 1; ++j)
                    objects[i] = objects[i + 1];
                objects[theSize - 1] = temp;
                return i;
            }
        }
        return -1;
    }

    void add(const Object& val)
    {
        objects[theSize++] = val;
    }

    const Object top() const
    {
        return objects[theSize - 1];
    }
private:
    Object* objects;
    int theSize;
    enum { INIT_CAPACITY = 16 };
};

#endif