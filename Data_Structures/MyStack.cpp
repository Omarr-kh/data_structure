//#include "MyStack.h"
//
//template <class Type>
//void stackType<Type>::initializeStack()
//{
//    stackTop = 0;
//}
//
//template <class Type>
//bool stackType<Type>::isEmptyStack() const
//{
//    return (stackTop == 0);
//}
//
//template <class Type>
//bool stackType<Type>::isFullStack() const
//{
//    return (stackTop == maxStackSize);
//}
//
//template <class Type>
//void stackType<Type>::push(const Type& newItem)
//{
//    if (!isFullStack())
//        list[stackTop++] = newItem;
//    else
//        std::cout << "can't add to a full stack" << std::endl;
//}
//
//template <class Type>
//Type stackType<Type>::top() const
//{
//    assert(stackTop != 0);
//
//    return list[stackTop - 1];
//}
//
//template <class Type>
//void stackType<Type>::pop()
//{
//    if (!isEmptyStack())
//        stackTop--;
//    else
//        std::cout << "Cannot remove from an empty Stack." << std::endl;
//}
//
//template <class Type>
//void stackType<Type>::copyStack(const stackType<Type>& other)
//{
//    delete[] list;
//    maxStackSize = other.maxStackSize;
//    stackTop = other.stackTop;
//
//    list = new Type[maxStackSize];
//
//    for (int i = 0; i < stackTop; i++)
//    {
//        list[i] = other.list[i];
//    }
//}
//
//template <class Type>
//stackType<Type>::stackType(int stackSize)
//{
//    if (stackSize <= 0)
//    {
//        std::cout << "Size of the array to hold the stack must be positive." << std::endl;
//        std::cout << "Creating an array of size 100" << std::endl;
//        maxStackSize = 100;
//    }
//    else
//        maxStackSize = stackSize;
//
//    stackTop = 0;
//    list = new Type[maxStackSize];
//}
//
//template <class Type>
//stackType<Type>::~stackType()
//{
//    delete[] list;
//}
//
//template <class Type>
//stackType<Type>::stackType(const stackType<Type>& other)
//{
//    list = NULL;
//    copyStack(other);
//}
//
//template <class Type>
//const stackType<Type>& stackType<Type>::operator=(const stackType<Type>& other)
//{
//    if (this != &other)
//        copyStack(other);
//
//    return *this;
//}
