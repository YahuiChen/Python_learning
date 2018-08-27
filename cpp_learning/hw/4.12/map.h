#ifndef MAP_HPP__
#define MAP_HPP__

#include <set>

template< typename KeyType, typename ValueType >
class Map {
public:
    class iterator {
    public:
        iterator() : it(0) {}

        ValueType& operator*()
        {
            return it.operator*().second;
        }

        iterator operator++()
        {
            return it.operator++();
        }

        iterator operator++(int)
        {
            return it.operator++(int);
        }

        iterator operator--()
        {
            return it.operator--();
        }

        iterator operator--(int)
        {
            return it.operator--(int);
        }

        bool operator==(const iterator& rhs)
        {
            return it == rhs.it;
        }

        bool operator!=(const iterator& rhs)
        {
            return !(*this == rhs);
        }

        std::pair<KeyType, ValueType>* operator->()
        {
            return &(*it);
        }

    private:
        iterator(typename std::set< std::pair< KeyType, ValueType > >::iterator& i)
            : it(i) {}

        typename std::set< std::pair< KeyType, ValueType > >::iterator it;
        friend class Map<KeyType, ValueType>;
    };

public:
    Map() : store(new std::set<std::pair<KeyType, ValueType> >())
    {}
    ~Map() { delete store; }

    iterator begin() const { return store->begin(); }
    iterator end() const { return store->end(); }
    size_t size() const { return store->size(); }
    bool empty() const { return store->empty(); }

    ValueType& operator[](const KeyType& key)
    {
        iterator it = iterator(store->begin());
        while (it != store->end())
        {
            if (it->first == key)
                return *it;
            ++it;
        }
        insert(key);
        return *(--it);
    }

    void insert(const KeyType& key, const ValueType& val = ValueType())
    {
        store->insert(std::pair<KeyType, ValueType>(key, val));
    }

    iterator insert(const iterator& it, const std::pair<KeyType, ValueType>& val)
    {
        return iterator(store->insert(it.it, val));
    }

    iterator find(const KeyType& key)
    {
        iterator it = store->begin();
        while (it != store->end())
        {
            if (*it == key)
                return it;
            ++it;
        }
        return it;
    }

    iterator erase(const iterator& it)
    {
        return iterator(store->erase(it.it));
    }

    iterator erase(const iterator& start, const iterator& end)

    {
        return iterator(store->erase(start.it, end.it));
    }

private:
    std::set<std::pair<KeyType, ValueType> >* store;
};

#endif