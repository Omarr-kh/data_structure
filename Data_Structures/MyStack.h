//#pragma once
//#include <iostream>
//#include <cassert>
//
//template <class Type>
//class stackADT
//{
//public:
//    virtual void initializeStack() = 0;
//    virtual bool isEmptyStack() const = 0;
//    virtual bool isFullStack() const = 0;
//    virtual void push(const Type& newItem) = 0;
//    virtual Type top() const = 0;
//    virtual void pop() = 0;
//};
//
//
//template <class Type>
//class stackType: public stackADT<Type>
//{
//public:
//    const stackType<Type>& operator=(const stackType<Type>& other);
//    void initializeStack();
//    bool isEmptyStack() const;
//    bool isFullStack() const;
//    void push(const Type& newItem);
//    Type top() const;
//    void pop();
//    stackType(int stackSize = 100);
//    stackType(const stackType<Type>& other);
//    ~stackType();
//
//private:
//    int maxStackSize;
//    int stackTop;
//    Type* list;
//
//    void copyStack(const stackType<Type>& other);
//};
