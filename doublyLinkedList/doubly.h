#ifndef DOUBLY_H
#define DOUBLY_H

class DLLNode{
    public:
    int data;
    DLLNode *prev;
    DLLNode *next;
};

class doublyLinkedList{

    private:
    bool isEmpty();
    int count;
    DLLNode *head;
    DLLNode *tail;
    public:
    doublyLinkedList();
    void insertAtFront(int elem);
    void insertAtpos(int pos, int elem);
    void insertAtTail(int elem);
    int deleteFromHead();
    int deleteFromTail();
    int deleteAtPos(int pos);
    int search(int elem);
    void printList();
    void printListReverse();

};



#endif
