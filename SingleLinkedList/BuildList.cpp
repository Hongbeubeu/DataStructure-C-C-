#include "SingleLinkedList.h"

int main()
{
    SingleLinkedList *testList = new SingleLinkedList();
    for (int i = 0; i < 10; i++)
    {
        if (i == 0){
            testList->addFirst(0);
        }
        else
            testList->addLast(i);
    }
    cout << "List: " << endl;
    testList->printLinkedList();
    cout << "Add vi tri 30, gia tri 1:" << endl;
    testList->addPosition(30, 1);
    cout << "Add vi tri 5, gia tri 10:" << endl;
    testList->addPosition(5, 10);
    testList->printLinkedList();
    cout << "Delete vi tri dau:" << endl;
    testList->deleteFirst();
    testList->printLinkedList();
    cout << "Delete vi tri cuoi:" << endl;
    testList->deleteLast();
    testList->printLinkedList();
    cout << "Delete vi tri 7:" << endl;
    testList->deletePostion(7);
    testList->printLinkedList();
    return 0;
}