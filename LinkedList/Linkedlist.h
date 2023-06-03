#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class Node{
    public:
    int data;
    Node* next;
};

class Linkedlist{

    private:
    Node *head, *tail;

    private:
    int count;
    bool isEmpty();

    public:
    Linkedlist();
    Linkedlist(int elem);
    void insertAt(int elem, int pos);
    void insertAtFront(int elem);
    void insertAtEnd(int elem);
    int removeAt(int pos);
    int removeFromHead();
    int removeFromTail();
    int search(int elem);
    void printList();
    int getListLength();
    void emptyList();

};




#endif
