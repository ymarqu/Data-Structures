   #include <iostream>
   using namespace std;
   #include "doubly.h"


   doublyLinkedList::doublyLinkedList(){
    head = NULL;
    tail = NULL;
    count = 0;
   }
   void doublyLinkedList::insertAtFront(int elem){
    if(head == NULL){
       head = new DLLNode;
       head->prev = NULL;
       head->next = NULL;
       head->data = elem;
       tail = head;
   }else{
    head->prev = new DLLNode;
    head->prev->data = elem;
    head->prev->next = head;
    head = head->prev;
   }
    count++;
   }
    void doublyLinkedList::insertAtpos(int pos, int elem){
        if(isEmpty()){
            insertAtFront(elem);
        }
        else if(pos == count){
            insertAtTail(elem);
        }
        else if(pos > count){
            cout << "The position is out of range. Cannot add" << endl;
        }else{
            int holder = 0;
            DLLNode *temp = head;
            while(holder < pos){
                temp = temp->next;
                holder++;
            }
            temp->prev->next = new DLLNode();
            temp->prev->next->prev = temp->prev;
            temp->prev->next->next = temp;
            temp->prev = temp->prev->next;
            temp->prev->data = elem;
            count++;
        }
    }
    void doublyLinkedList::insertAtTail(int elem){
    if(head == NULL){
       head = new DLLNode;
       head->prev = NULL;
       head->next = NULL;
       head->data = elem;
       tail = head;
    }else{
       tail->next = new DLLNode;
       tail->next->prev = tail;
       tail = tail->next;
       tail->data = elem;
    }
    count++;
   }

    int doublyLinkedList::deleteFromHead(){
        if(isEmpty()){
            return -1;
        }
        int elem = head->data;
        if(head == tail){
            DLLNode *temp = head;
            head = NULL; tail = NULL;
            delete temp;
        }else{
            DLLNode *temp = head;
            head = head->next;
            temp->next = NULL;
            head->prev = NULL;
            delete temp;
        }
        count--;
        return elem;
    }
    int doublyLinkedList::deleteFromTail(){
     if(isEmpty()){
        return -1;
     }
     int elem = tail ->data;
     if(head == tail){
            DLLNode *temp = head;
            head = NULL; tail = NULL;
            delete temp;
        }else{
            DLLNode *temp = tail;
            tail = tail->prev;
            temp->prev = NULL;
            tail->next = NULL;
            delete temp;
        }
        count--;
        return elem;
    }
    int doublyLinkedList::deleteAtPos(int pos){
        int elem = -1;
        if(pos == 0){
            elem = deleteFromHead();
        }
        else if(pos == count){
            elem = deleteFromTail();
        }
        else if(pos > count){
            cout << "position provided is out of bound. please enter a number between 0 and "<< count << "."<< endl;
        }
        else{
        int holder = 0;
        DLLNode *temp = head;
        while(holder < pos){
            temp = temp->next;
            holder++;
        }
        elem = temp->data;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = NULL;
        temp->prev = NULL;
        delete temp;
        count--;
       }
        return elem;
    }
    int doublyLinkedList::search(int elem){

        if(isEmpty()){
            cout << "List is empty cannot search." << endl;
            return -1;
        }
        int pos = 0;
        DLLNode *temp = head;
        while(temp != NULL){
            if(temp->data == elem){
                return pos;
            }
            temp = temp->next;
            pos++;
        }
        return -1;
    }
    void doublyLinkedList::printList(){

        if(isEmpty()){
            cout << "List is empty. Cannot print." << endl;
        }else{
            DLLNode *temp = head;
            cout << "x<=>";
            while(temp != NULL){
                cout << "[";
                cout << temp->data;
                cout <<"]<=>";
                temp = temp->next;
            }
            cout << "x" << endl;
            temp = NULL;
            delete temp;
        }
    }
    void doublyLinkedList::printListReverse(){
        if(isEmpty()){
            cout << "List is empty. Cannot print." << endl;
        }else{
            DLLNode *temp = tail;
            cout << "x<=>";
            while(temp != NULL){

                cout << "[";
                cout << temp->data;
                cout << "]=>";
                temp = temp->prev;
            }
            cout << "x" << endl;\
            temp = NULL;
            delete temp;
        }
    }
    bool doublyLinkedList::isEmpty(){
        if(count == 0){
            return true;
        }
        return false;
    }
