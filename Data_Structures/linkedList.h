#pragma once
#include <iostream>
#include <cassert>

class Node
{
    int info;
    Node* next;
public:
    Node() { next = 0; }
    Node(int n, Node* in = 0)
    {
        next = in; info = n;
    }
    Node* getNext() { return next; }
    void setNext(Node* pt) { next = pt; }
    int getInfo() { return info; }
    void setInfo(int n) { info = n; }
    friend std::ostream& operator<<(std::ostream& stream, Node node)
    {
        stream << node.getInfo();
        stream << (node.getNext() == 0 ? "" : "->");
        return stream;
    }
};


class linkedListIterator
{
private:
    Node* current;
public:
    linkedListIterator();
    linkedListIterator(Node *it);
    int operator*();
    linkedListIterator operator++();
    bool operator==(const linkedListIterator& it);
    bool operator!=(const linkedListIterator& it);
};


class linkedList
{
protected:
    int count;
    Node* head;
    Node* tail;
public:
    const linkedList& operator=(const linkedList& other);
    void initializeList();
    bool isEmptyList();
    void print();
    int length();
    void destroyList();
    int front();
    int back();
    virtual bool search(const int& item) = 0;
    virtual void insertFirst(const int& item) = 0;
    virtual void insertLast(const int& item) = 0;
    virtual void deleteNode(const int& item) = 0;
    linkedListIterator begin();
    linkedListIterator end();
    linkedList();
    linkedList(const linkedList&);
    ~linkedList();
private:
    void copyList(const linkedList&);
};

class unorderedLinkedList :public linkedList
{
public:
    bool search(const int& item);
    void insertFirst(const int& item);
    void insertLast(const int& item);
    void deleteNode(const int& item);
};

class orderedLinkedList :public linkedList
{
public:
    bool search(const int& item);
    void insert(const int& item);
    void insertFirst(const int& item);
    void insertLast(const int& item);
    void deleteNode(const int& item);
};
