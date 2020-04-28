#include <iostream>

using namespace std;

class SingleLinkedList
{
    struct Node
    {
        int data;
        Node *pNext;
    };
    
    private:
        Node *pHead;
    public:
        SingleLinkedList();
        ~SingleLinkedList();
        void addFirst(int val);
        void addLast(int val);
        void addPosition(int pos, int val);
        void deleteFirst();
        void deleteLast();
        void deletePostion(int pos);
        void printLinkedList();
};


//Constructor
SingleLinkedList::SingleLinkedList()
{
    pHead = NULL;
}

//Destructor
SingleLinkedList::~SingleLinkedList()
{
    Node *pTempHead = pHead;
    while (pTempHead)
    {
        Node *temp = pHead;
        pTempHead = pHead->pNext;
        delete temp;
        temp = NULL;
    }
    
}

//Add value val at first position of linked list
void SingleLinkedList::addFirst(int val)
{
    Node *newNode = new Node();
    newNode->data = val;
    
    //check linked list is empty or not
    if(pHead != NULL){
        /** if linked list is not empty 
        * assign newNode to the head 
        * assign next node of the head to newNode
        */
        newNode->pNext = pHead->pNext;
        pHead = newNode;
    }else
    {
        /** if linked list is empty (pHead is NULL)
         * assign newNode to the head
         * assign next node is NULL
         */
        pHead = newNode;
        pHead->pNext = NULL;
    }
}
/** Add value val to the last position of the linked list */
void SingleLinkedList::addLast(int val)
{
    Node *newNode = new Node();
    newNode->data = val;
    newNode->pNext = NULL;
    Node *iterator = new Node();
    iterator = pHead;
    while (iterator->pNext != NULL) 
    {
        iterator = iterator->pNext;
    }
    iterator->pNext = newNode;
}

/** Add value val to position pos of linked list */
void SingleLinkedList::addPosition(int pos, int val)
{
    Node *newNode = new Node();
    newNode->data = val;
    Node *iterator = pHead;
    while (iterator->pNext != NULL)
    {
        iterator = iterator->pNext;
        --pos;
        if(pos == 1)
            break;
    }

    /** check position pos is valid or invalid */
    if(iterator->pNext != NULL)
    {
        Node *temp = iterator->pNext;
        iterator->pNext = newNode;
        newNode->pNext = temp;
    }else
    {
        cout << "POSITION IS INVALIDED" << endl;
        return;
    }
}

/** Delete node at first position of linked list */
void SingleLinkedList::deleteFirst()
{
    if(pHead != NULL)
    {
        Node *temp = pHead;
        pHead = pHead->pNext;
        delete temp;
    }
} 

/** Delete node at last position of linked list */
void SingleLinkedList::deleteLast()
{
    Node *iterator = pHead;
    while (iterator->pNext->pNext != NULL)
    {
        iterator = iterator->pNext;
    }
    Node *temp = iterator->pNext;
    delete temp;
    iterator->pNext = NULL;
}

/** Delete node at position pos of linked list */
void SingleLinkedList::deletePostion(int pos)
{
    Node *iterator = pHead;
    while (iterator->pNext != NULL)
    {
        iterator = iterator->pNext;
        --pos;
        if(pos == 1)
            break;
    }
    if(pos == 1)
    {
        Node *temp = iterator->pNext;
        iterator->pNext = temp->pNext;
        delete temp;
    }else
    {
        cout << "POSTITION IS INVALIDED!" << endl;
        return;
    }
}

/** print out linked to console */
void SingleLinkedList::printLinkedList()
{
    Node *iterator = pHead;
    int count = 0;
    while (iterator != NULL)
    {
        if(iterator->pNext == NULL)
            cout << "[" << count << ": " << iterator->data << "]";
        else 
            cout << "[" << count << ": " << iterator->data << "]->";
        ++count;
        iterator = iterator->pNext;
    }
    cout << endl;
}

