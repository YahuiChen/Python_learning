#ifndef BSTREE_HPP__
#define BSTREE_HPP__

//#include <iosfwd>

template< typename Object >
class Set;

const int Null = 0;

template< typename Object >
class BSTree
{
private:
    class Node
    {
    public:
        Node(const Object& val = Object(), Node* l = Null, Node* r = Null,
            Node* p = Null) : parent(p), lChild(l), rChild(r), data(val)
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
    void clear()
    {
        clear(root);
    }
    void add(const Object& val)
    {
        insert(val, root, parent);
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

private:
    Node* root;
    Node* parent;

    friend class Set<Object>;
};

#endif