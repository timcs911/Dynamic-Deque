#ifndef MYINTDEQUE_H
#define MYINTDEQUE_H

#include <iostream>

using namespace std;

class MyIntDeque{
private:
    
    struct Node{
        int value;
        Node* next = nullptr;
        Node* prev = nullptr;
    };
    
    Node* first;
    Node* last;
    
public:
   inline MyIntDeque()
    {
        first = nullptr;
        last = nullptr;
    };
    inline ~MyIntDeque()
    {
        clear();
    };
    
    inline void push_front(int v)
    {
        if(!isFull())
        {
            if(first == nullptr || last == nullptr)
            {
                Node* n = new Node;
                n->value = v;
                n->next = nullptr;
                n->prev = nullptr;

                first = n;
                last = n;
            }
            else{
                Node * n = new Node;
                n->value = v;
                n->next = first;
                n->prev = nullptr;
                first->prev = n;
                first = n;
            }
        }
        else
            throw "Out of Memory!";
        
    };
    
    inline void push_back(int v)
    {
        if(!isFull())
        {
            if(first == nullptr || last == nullptr)
            {
                Node* n = new Node;
                n->value = v;
                n->next = nullptr;
                n->prev = nullptr;
                first = n;
                last = n;
            }
            else{
                Node* n = new Node;
                n->value = v;
                n->next = nullptr;
                n->prev = last;
                last->next = n;
                last = n;
            }
        }
        else
            throw "Out of Memory!";
    };
    
    inline void pop_back()
    {
        if(!isEmpty())
        {
            if(last == first)
            {
                delete first;
                first = nullptr;
                last= nullptr;
            }
            else{
                Node *p = last;
                last = last->prev;
                last->next = nullptr;
                delete p;
            }
            
        }
        else
            throw "Empty Deque";

    };
    
    inline void pop_front()
    {
        if(!isEmpty())
        {
            if(last == first)
            {
                delete first;
                first = nullptr;
                last= nullptr;
            }
            else{
                Node* p = first;
                first = first->next;
                first->prev = nullptr;
                delete p;
            }
        }
        else
            throw "Empty Deque";
    };
    
    inline int size() const
    {
        int count = 0;
        Node* t = new Node;
        t = first;
        while(t)
        {
            count++;
            t = t->next;
        }
        return count;
    };
    
    inline int front() const
    {
        if(!isEmpty())
            return first->value;
        else
            return -1;
    };
   
    inline int back() const
    {
        if(!isEmpty())
        {
            return last->value;
        }
        else
            return -1;
    };
    
    inline bool isFull() const
    {
        try{
            Node * newNode = new Node;
            delete newNode;
            return false;
        }
        catch(bad_alloc)
        {
            return true;
        }
    };
    
    inline bool isEmpty() const
    {
        if(first == nullptr || last == nullptr)
            return true;
        else
            return false;
    };
    
    inline void clear()
    {
            Node* p = first;
            while(p)
            {
                first = first->next;
                delete p;
                p = first;
            }
            first = nullptr;
            last = nullptr;
    };

};
#endif /* MYINTDEQUE_H */