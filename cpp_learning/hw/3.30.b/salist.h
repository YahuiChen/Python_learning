#ifndef SALSelfAdjustLList_HPP__
#define SALSelfAdjustLList_HPP__

#include <iostream>
#include <cassert>

template<typename Object>
class SelfAdjustLList {
private:
    class Node {
    public:
        Node(const Object& d = Object(), Node* p = 0, Node* n = 0) : data(d), next(n), prev(p) {}

    public:
        Object data;
        Node* next;
        Node* prev;
    };

public:
    class Const_Iterator {
    public:
        Const_Iterator() : current(0) {}

        const Object& operator* () const { return retrieve(); }

        Const_Iterator& operator++()
        {
            current = current->next;
            return *this;
        }

        Const_Iterator& operator++(int)
        {
            Const_Iterator old = *this;
            ++(*this);
            return old;
        }

        Const_Iterator& operator--()
        {
            current = current->prev;
            return *this;
        }

        Const_Iterator& operator--(int)
        {
            Const_Iterator old = *this;
            --(*this);
            return old;
        }

        bool operator==(const Const_Iterator& rhs) const
        {
            return current == rhs.current;
        }

        bool operator!=(const Const_Iterator& rhs) const
        {
            return !(*this == rhs);
        }
    protected:
        Node* current;

        Object& retrieve() const { return current->data; }

        Const_Iterator(const SelfAdjustLList<Object> &lst, Node* p) : theSelfAdjustLList(&lst), current(p) {}

        void assertValid()
        {
            assert(theSelfAdjustLList != 0 || current != 0 || current != theSelfAdjustLList->head);
        }

        const SelfAdjustLList<Object> *theSelfAdjustLList;

        friend class SelfAdjustLList<Object>;
    };

    class Iterator : public Const_Iterator {
    public:
        Iterator() {}

        Object& operator*() { return retrieve(); }
        Object& operator*() const { return retrieve(); }

        Iterator& operator++()
        {
            current = current->next;
            return *this;
        }

        Iterator& operator++(int)
        {
            Node old = *this;
            ++(*this);
            return old;
        }

        Iterator& operator--()
        {
            current = current->prev;
            return *this;
        }

        Iterator& operator--(int)
        {
            Node old = *this;
            --(*this);
            return old;
        }

        bool operator==(const Iterator& rhs) const
        {
            return current == rhs.current;
        }

        bool operator!=(const Iterator& rhs) const
        {
            return !(*this == rhs);
        }

    private:
        Iterator(SelfAdjustLList<Object> &lst, Node *p) : Const_Iterator(lst, p) {}

        friend class SelfAdjustLList<Object>;
    };

public:
    SelfAdjustLList()
    {
        init();
    }
    SelfAdjustLList(const SelfAdjustLList& rhs)
    {
        init();
        *this = rhs;
    }
    ~SelfAdjustLList()
    {
        Clear();
        delete head;
        delete tail;
    }
    SelfAdjustLList& operator=(const SelfAdjustLList& rhs)
    {
        if (rhs == *this)
            return *this;

        Clear();
        for (Const_Iterator it = rhs.Begin(); it != rhs.End(); ++it)
            Push_Back(*it);

        return *this;
    }

    Iterator Begin() { return Iterator(*this, head->next); }
    Const_Iterator Begin() const { return Const_Iterator(*this, head->next); }

    Iterator End() { return Iterator(*this, tail); }
    Const_Iterator End() const { return Const_Iterator(*this, tail); }

    unsigned int Size() const { return theSize; }
    bool Empty() const { return theSize == 0; }

    void Clear()
    {
        while (!Empty())
            Pop_Front();
    }

    Object& Front() { return *Begin(); }
    const Object& Front() const { return *Begin(); }

    Object& Back() { return *(--End()); }
    const Object& Back() const { return *(--End()); }

    void Push_Front(const Object& ob)
    {
        Insert(Begin(), ob);
    }

    /*void Push_Back(const Object& ob)
    {
    Insert(End(), ob);
    }*/

    void Pop_Front() { Erase(Begin()); }
    /*void Pop_Back() { Erase(--End()); }*/

    Iterator Insert(Iterator it, const Object& ob)
    {
        it.assertValid();
        if (it.theSelfAdjustLList != this)
            std::cerr << "Not the same SelfAdjustLList/n";
        else
        {
            Node* p = it.current;
            ++theSize;
            return Iterator(*this, p->prev = p->prev->next = new Node(ob, p->prev, p));
        }
    }
    Iterator Erase(Iterator it)
    {
        Node* p = it.current;
        Iterator retVal(*this, p->next);
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        --theSize;

        return retVal;
    }

    Iterator Erase(Iterator start, Iterator end)
    {
        for (Iterator it = start; it != end; )
            it = Erase(it);

        return end;
    }

    Const_Iterator find(const Object& val)
    {
        Const_Iterator it = Begin();
        while (it != End())
        {
            if (val == *it)
            {
                it.current->next->prev = it.current->prev;
                it.current->prev->next = it.current->next;

                it.current->next = head->next;
                it.current->prev = head;

                head->next->prev = it.current;
                head->next = it.current;

                return it;
            }
            ++it;
        }
        return End();
    }

private:
    unsigned int theSize;
    Node* head;
    Node* tail;

    void init()
    {
        theSize = 0;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
};

#endif