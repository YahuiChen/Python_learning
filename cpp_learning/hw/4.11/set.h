#ifndef SET_HPP__
#define SET_HPP__

#include "bstree.h"

template< typename Object >
class Set {
public:
    class const_iterator {
    public:
        const Object& operator*()
        {
            return current->data;
        }

        const_iterator operator++()
        {
            if (current->lChild == Null && current->rChild != Null)
                return const_iterator(current = BSTree<Object>::findMin(current->rChild));
            else if (current->lChild == Null && current->rChild == Null
                && current->parent->rChild == current)
                return const_iterator(current = current->parent->parent);
            else if (current->lChild == Null && current->rChild == Null
                && current->parent->lChild == current)
                return const_iterator(current = current->parent);
            else if (current->lChild != Null && current->rChild != Null)
                return const_iterator(current = BSTree<Object>::findMin(current->rChild));
            else if (current->lChild != Null && current->rChild == Null
                && current->parent->lChild == current)
                return const_iterator(current = current->parent);
            else
                return const_iterator(current = current->rChild);
        }

        const_iterator operator++(int)
        {
            const_iterator old = *this;
            ++(*this);
            return old;
        }

        bool operator==(const const_iterator& rhs) const
        {
            return current == rhs.current;
        }

        bool operator!=(const const_iterator& rhs) const
        {
            return !(*this == rhs);
        }

    protected:
        const_iterator(typename BSTree<Object>::Node* p) : current(p) {}

        typename BSTree<Object>::Node* current;

        friend class Set<Object>;
    };

public:
    Set() : tree(new BSTree<Object>()) {}
    ~Set()
    {
        delete tree;
    }

    const_iterator begin() const
    {
        return const_iterator(BSTree<Object>::findMin(tree->root));
    }

    const_iterator end() const
    {
        return const_iterator(BSTree<Object>::findMax(tree->root));
    }

    bool empty() const
    {
        return tree->empty();
    }

    void insert(const Object& val)
    {
        tree->add(val);
    }

    int erase(const Object& val)
    {
        if (!tree->contains(val))
            return 0;

        tree->del(val);
        return 1;
    }

    const_iterator erase(const_iterator it)
    {
        const_iterator old = it;
        ++old;
        erase(it.current->data);
        return old;
    }

private:
    BSTree<Object>* tree;
};

#endif