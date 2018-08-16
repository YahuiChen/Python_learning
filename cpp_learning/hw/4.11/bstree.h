#ifndef BSTREE_HPP__
#define BSTREE_HPP__

#include <iosfwd>

template< typename Object >
class Set;

const int Null = 0;

template< typename Object >
class BSTree {
private:
    class Node {
    public:
        Node(const Object& val = Object(), Node* l = Null, Node* r = Null,
            Node* p = Null) : parent(p), lChild(l),
            rChild(r), data(val)
        {}

    public:
        Object data;
        Node* lChild;
        Node* rChild;
        Node* parent;
    };

public:
    BSTree() : root(Null), parent(Null) {}
    ~BSTree() { clear(); }
    BSTree(const BSTree& rhs) {}
    BSTree& operator=(const BSTree& rhs) {}

public:
    bool contains(const Object& val) const
    {
        return contains(val, root);
    }
    bool empty() const
    {
        return root == Null;
    }
    void printTree(std::ostream& out)
    {
        if (empty())
            out << "empty tree/n";
        else
            printTree(root, out);
    }

    void clear()
    {
        clear(root);
    }
    void add(const Object& val)
    {
        insert(val, root, parent);
    }
    void del(const Object& val)
    {
        remove(val, root, parent);
    }

private:
    void insert(const Object& val, Node* &t, Node* &parent)
    {
        if (t == Null)
            t = new Node(val, Null, Null, parent);
        else if (val < t->data)
            insert(val, t->lChild, t);
        else if (t->data < val)
            insert(val, t->rChild, t);
        else
            return;
    }

    void remove(const Object& val, Node* &t, Node* &parent)
    {
        if (t == Null)
            return;

        if (val < t->data)
            remove(val, t->lChild, t);
        else if (t->data < val)
            remove(val, t->rChild, t);
        else if (t->lChild != Null && t->rChild != Null)
        {
            t->data = findMin(t->rChild)->data;
            remove(t->data, t->rChild, t);
        }
        else if ((t->lChild != Null && t->rChild == Null) ||
            (t->lChild == Null && t->rChild != Null))
        {
            Node* old = t;
            t = (t->lChild != Null) ? t->lChild : t->rChild;
            t->parent = old->parent;
            delete old;
        }
        else
        {
            t->parent->rChild == t ? t->parent->rChild = Null :
                t->parent->lChild = Null;
            delete t;
        }
    }

    bool contains(const Object& val, Node* t) const
    {
        if (t == Null)
            return false;
        else if (val < t->data)
            return contains(val, t->lChild);
        else if (t->data < val)
            return contains(val, t->rChild);
        else
            return true;
    }

    static Node* findMin(Node* t)
    {
        if (t != Null)
            while (t->lChild != Null)
                t = t->lChild;
        return t;
    }

    static Node* findMax(Node* t)
    {
        if (t != Null)
            while (t->rChild != Null)
                t = t->rChild;
        return t;
    }

    void clear(Node* &t)
    {
        if (t != Null)
        {
            clear(t->lChild);
            clear(t->rChild);
            delete t;
        }
        t = Null;
    }

    void printTree(Node* t, std::ostream& out)
    {
        if (t != Null)
        {
            printTree(t->lChild, out);
            out << t->data << "/n";
            printTree(t->rChild, out);
        }
    }

private:
    Node* root;
    Node* parent;

    friend class Set<Object>;
};

#endif