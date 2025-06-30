#include "list.h"
#include "exceptions.h"
#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H

template<typename T>
struct OrderedList : public List<T>
{
    OrderedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }

    ~OrderedList() { clear(); }

    void add (const T& item) override
    {
        Node<T>* node = new Node<T>{item, nullptr, nullptr};
        if(empty()) this->head = this->tail = node;
        else if(node->value <= this->head->value) {
            this->head->prev = node;
            node->next = this->head;
            this->head = node;
        }
        else if(node->value >= this->tail->value) {
            this->tail->next = node;
            node->prev = this->tail;
            this->tail = node;
        }
        else {
            Node<T>* tmp = this->head;
            while(tmp->next != nullptr &&  node->value > tmp->next->value) { tmp = tmp->next; }
            node->next = tmp->next;
            node->prev = tmp;
            if(tmp->next != nullptr) tmp->next->prev = node;
            tmp->next = node;
        }
        ++this->size;
    }

    void remove (const T& item) override //removes first instance of an item
    {
        Node<T>* tmp = this->head;
        while(tmp != nullptr)
        {
            if(tmp->value == item)
            {
                if(tmp->next != nullptr) tmp->next->prev = tmp->prev;
                else this->tail = tmp->prev;
                if(tmp->prev != nullptr) tmp->prev->next = tmp->next;
                else this->head = tmp->next;
                delete tmp;
                --this->size;
                return;
            }
            tmp = tmp->next;
        }
    }

    bool contains (const T& item) const override
    {
        Node<T>* tmp = this->head;
        while(tmp != nullptr)
        {
            if(tmp->value == item) return true;
            tmp = tmp->next;
        }
        return false;
    }

    void clear () override
    {
        Node<T>* tmp = this->head;
        while(this->head != nullptr)
        {
            tmp = this->head->next;
            delete this->head;
            this->head = tmp;
        }
        this->size = 0;
        this->head = this->tail = nullptr;
    }
    size_t get(const T& item) const override
    {
        Node<T>* tmp = this->head;
        if(!empty()) {
            for(size_t i{}; i < this->size; ++i)
            {
                if(tmp->value == item) return i;
                tmp = tmp->next;
            }
        }
        throw OutOfBounds();
    }
    std::vector<T> toVector() const override{
        std::vector<T> inOrder;
        Node<T>* tmp = this->head;
        while(tmp != nullptr)
        {
            inOrder.push_back(tmp->value);
            tmp = tmp->next;
        }
        return inOrder;
    }

    T& operator[](size_t index) override
    {
        Node<T>* tmp = this->head;
        for (size_t i{}; i < index; ++i)
        {
            tmp = tmp->next;
        }
        return tmp->value;
    }

    T& at(size_t index) override
    {
        if(empty() || index >= this->size) throw OutOfBounds();
        return (*this)[index];
    }
    
    bool empty() const override {
        return this->head == nullptr;
    }

};

#endif //ORDEREDLIST_H