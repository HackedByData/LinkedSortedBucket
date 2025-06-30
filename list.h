#include "node.h"
#include <vector>
#include <iostream>
#ifndef LIST_H
#define LIST_H

template<typename T>
class List {
public:
    virtual ~List() = default;
    virtual void add (const T& item) = 0;
    virtual void remove (const T& item) = 0;
    virtual bool contains (const T& item) const = 0;
    virtual bool empty () const = 0;
    virtual void clear () = 0;
    virtual size_t getSize() { return size; }
    virtual size_t get(const T& item) const = 0;
    virtual std::vector<T> toVector() const = 0;
    virtual T& operator[](size_t index) = 0;
    virtual T& at(size_t index) = 0;
protected:
    Node<T>* head;
    Node<T>* tail;
    size_t size;
};

#endif //LIST_H