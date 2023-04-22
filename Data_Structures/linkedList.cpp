#include "linkedList.h"

// linkedListIterator member functions definitions
linkedListIterator::linkedListIterator()
{
    current = NULL;
}

linkedListIterator::linkedListIterator(Node *n)
{
    current = n;
}

int linkedListIterator::operator*()
{
    return current->getInfo();
}

linkedListIterator linkedListIterator::operator++()
{
    current = current->getNext();
    return *this;
}

bool linkedListIterator::operator==(const linkedListIterator& it)
{
    return (current == it.current);
}

bool linkedListIterator::operator!=(const linkedListIterator& it)
{
    return (current != it.current);
}



// linkedList member functions definitions
const linkedList& linkedList::operator=(const linkedList& other)
{
    if (this != &other)
    {
        copyList(other);
    }
    return *this;
}

bool linkedList::isEmptyList()
{
    return (head == NULL);
}

void linkedList::initializeList()
{
    destroyList();
}

void linkedList::print()
{
    Node* ptr = head;
    while (ptr != NULL)
    {
        std::cout << ptr->getInfo() << " ";
        ptr = ptr->getNext();
    }
}

int linkedList::length()
{
    return count;
}

int linkedList::front()
{
    assert(head != NULL);
    return (head->getInfo());
}

int linkedList::back()
{
    assert(tail != NULL);
    return (tail->getInfo());
}

linkedListIterator linkedList::begin()
{
    linkedListIterator it(head);
    return it;
}

linkedListIterator linkedList::end()
{
    linkedListIterator it(NULL);
    return it;
}

linkedList::linkedList()
{
    head = tail = NULL;
    count = 0;
}

linkedList::linkedList(const linkedList& other)
{
    head = NULL;
    copyList(other);
}

linkedList::~linkedList()
{
    destroyList();
}

void linkedList::destroyList()
{
    Node* temp;

    while (head != NULL)
    {
        temp = head;
        head = head->getNext();
        delete temp;
    }
    tail = NULL;
    count = 0;
}

void linkedList::copyList(const linkedList& other)
{
    Node* newNode;
    Node* current;

    if (head != NULL)
        destroyList();

    if (other.head == NULL)
    {
        head = tail = NULL;
        count = 0;
    }

    else
    {
        current = other.head;
        count = other.count;

        head = new Node;
        head->setInfo(current->getInfo());
        head->setNext(NULL);
        tail = head;
        current = current->getNext();

        while (current != NULL)
        {
            newNode = new Node;
            newNode->setInfo(current->getInfo());
            newNode->setNext(NULL);
            tail->setNext(newNode);
            tail = newNode;
            current = current->getNext();
        }
    }
}


// unordered linked lists functions definitions
bool unorderedLinkedList::search(const int &item)
{
    Node* current = new Node;
    current = head;
    bool found = false;

    while (current != NULL && !found)
    {
        if (item == current->getInfo())
        {
            found = true;
        }
        else
            current = current->getNext();
    }
    return found;
}

void unorderedLinkedList::insertFirst(const int& item)
{
    Node* newNode = new Node;
    newNode->setInfo(item);
    newNode->setNext(head);
    head = newNode;
    count++;

    if (tail == NULL)
    {
        tail = newNode;
    }
}

void unorderedLinkedList::insertLast(const int& item)
{
    Node* newNode = new Node;
    newNode->setInfo(item);
    newNode->setNext(NULL);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        count++;
    }
    else
    {
        tail->setNext(newNode);
        tail = newNode;
        count++;
    }
}

void unorderedLinkedList::deleteNode(const int& item)
{
    Node* current;
    Node* tailCurrent;
    bool found;

    if (head == NULL)
        std::cout << "Cannot delete from an empty list" << std::endl;
    else
    {
        if (head->getInfo() == item)
        {
            current = head;
            head = head->getNext();
            count--;

            if (head == NULL)
                tail = NULL;

            delete current;
        }
        else
        {
            found = false;
            tailCurrent = head;
            current = head->getNext();

            while (current != NULL && !found)
            {
                if (current->getInfo() != item)
                {
                    tailCurrent = current;
                    current = current->getNext();
                }
                else
                    found = true;
            }

            if (found)
            {
                tailCurrent->setNext(current->getNext());
                count--;

                if (current == tail)
                {
                    tail = tailCurrent;
                }
                delete current;
            }
            else
            {
                std::cout << "the item to be deleted is not in the list." << std::endl;
            }
        }
    }
}


//ordered linked lists functions definitions
bool orderedLinkedList::search(const int& item)
{
    Node* current;
    bool found = false;
    current = head;

    while (current != NULL && !found)
    {
        if (current->getInfo() >= item)
            found = true;
        else
            current = current->getNext();
    }

    if (found)
        found = (current->getInfo() == item);
    return found;
}

void orderedLinkedList::insert(const int& item)
{
    Node* current;
    Node* tailCurrent;
    Node* newNode;
    bool found;

    tailCurrent = head;
    newNode = new Node;
    newNode->setInfo(item);
    newNode->setNext(NULL);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        count++;
    }
    else
    {
        current = head;
        found = false;

        while (current != NULL && !found)
            if (current->getInfo() >= item)
                found = true;
            else
            {
                tailCurrent = current;
                current = current->getNext();
            }

        if (current == head)
        {
            newNode->setNext(head);
            head = newNode;
            count++;
        }
        else
        {
            tailCurrent->setNext(newNode);
            newNode->setNext(current);

            if (current == NULL)
                tail = newNode;

            count++;
        }
    }
}

void orderedLinkedList::insertFirst(const int& item)
{
    insert(item);
}

void orderedLinkedList::insertLast(const int& item)
{
    insert(item);
}

void orderedLinkedList::deleteNode(const int& deleteItem)
{
    Node* current; //pointer to traverse the list
    Node* tailCurrent; //pointer just before current
    bool found;

    tailCurrent = new Node;

    if (head == NULL) //Case 1
        std::cout << "Cannot delete from an empty list." << std::endl;
    else
    {
        current = head;
        found = false;

        while (current != NULL && !found) //search the list
        {
            if (current->getInfo() >= deleteItem)
                found = true;
            else
            {
                tailCurrent = current;
                current = current->getNext();
            }
        }

        if (current == NULL) //Case 4
            std::cout << "The item to be deleted is not in the list."
            << std::endl;

        else
            if (current->getInfo() == deleteItem) //the item to be deleted is in the 
            {
                if (head == current) //Case 2
                {
                    head = head->getNext();
                    if (head == NULL)
                        tail = NULL;
                    delete current;
                }
                else //Case 3
                {
                    tailCurrent->setNext(current->getNext());
                    if (current == tail)
                        tail = tailCurrent;
                    delete current;
                }
                count--;
            }
            else //Case 4
                std::cout << "The item to be deleted is not in the list." << std::endl;
    }
}
