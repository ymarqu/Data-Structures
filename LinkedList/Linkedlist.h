#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class Node{
    public:
    int data;
    Node* next;
};

class Linkedlist{

    private:
    Node* Head, Tail;

    private:
    int listLenght;
    bool isEmpty;

    public:
    void insertAt(int elem, int pos);
    void insertAtFront(int elem);
    void insertAtEnd(int elem);
    int removeAt(int pos);
    int removeFromHead();
    int removeFromTail();
    int search();
    void printList();

};




#endif
