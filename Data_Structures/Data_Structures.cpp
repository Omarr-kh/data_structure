#include "linkedList.h"

//using namespace std;

//void testCopyConstructor(stackType<int> otherStack);
//
//int main()
//{
//    stackType<int> stack(50);
//    stackType<int> copyStack(50);
//    stackType<int> dummyStack(100);
//    stack.initializeStack();
//    stack.push(23);
//    stack.push(45);
//    stack.push(38);
//    copyStack = stack; //copy stack into copyStack
//    std::cout << "The elements of copyStack: ";
//    while (!copyStack.isEmptyStack()) //print copyStack
//    {
//        std::cout << copyStack.top() << " ";
//        copyStack.pop();
//    }
//    std::cout << std::endl;
//    copyStack = stack;
//    testCopyConstructor(stack); //test the copy constructor
//    if (!stack.isEmptyStack())
//        std::cout << "The original stack is not empty." << std::endl
//        << "The top element of the original stack: "
//        << copyStack.top() << std::endl;
//    dummyStack = stack; //copy stack into dummyStack
//    std::cout << "The elements of dummyStack: ";
//    while (!dummyStack.isEmptyStack()) //print dummyStack
//    {
//        std::cout << dummyStack.top() << " ";
//        dummyStack.pop();
//    }
//    std::cout << std::endl;
//    return 0;
//}
//void testCopyConstructor(stackType<int> otherStack)
//{
//    if (!otherStack.isEmptyStack())
//        std::cout << "otherStack is not empty." << std::endl
//        << "The top element of otherStack: "
//        << otherStack.top() << std::endl;
//
//}
