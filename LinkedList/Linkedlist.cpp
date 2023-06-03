#include "Linkedlist.h"
#include <iostream>
using namespace std;

    Linkedlist::Linkedlist(){
        head = NULL;
        tail = NULL;
        count = 0;
    }
    Linkedlist::Linkedlist(int elem){
        head = new Node();
        tail = head;
        head -> data = elem;
        head -> next = NULL;
        count++;

    }
    void Linkedlist::insertAt(int elem, int pos){
        if(pos == 0){
            insertAtFront(elem);
        }else if(pos >= count){
            insertAtEnd(elem);
        }else{
            Node *temp = head;
            Node *prev = NULL;
            while(pos > 0){
                prev = temp;
                temp = temp->next;
                pos--;
            }
            prev->next = new Node();
            prev->next->data = elem;
            prev->next->next = temp;
            temp = NULL;
            prev=NULL;
            delete temp;
            delete prev;
            count++;
        }
    }
    void Linkedlist::insertAtFront(int elem){
        if(head == NULL){
            head = new Node();
            head->data = elem;
            head->next = NULL;
            tail = head;
        }else{
            Node *temp = new Node;
            temp->data = elem;
            temp->next = head;
            head = temp;
            temp = NULL;
            delete temp;
        }
        count++;
    }
    void Linkedlist::insertAtEnd(int elem){

        if(head == NULL){
            insertAtFront(elem);
        }else{
            // Node *temp = new Node;
            // temp->data = elem;
            // temp->next = NULL;
            // tail->next=temp;
            // tail=temp;
            // temp=NULL;
            // delete temp;
            tail->next = new Node();
            tail->next->data = elem;
            tail->next->next = NULL;
            tail = tail-> next;
            count++;
        }


    }
    int Linkedlist::removeAt(int pos){
        int elem =  0;
        if(pos > count){
            cout << "Position provided is out of range" << endl;
        }else{
        if(pos == 0){
            elem = removeFromHead();
        }else if(pos == count){
            elem = removeFromTail();
        }else{
            Node *temp = head;
            Node *prev = NULL;
            while(pos > 0){
                prev = temp;
                temp = temp->next;
                pos--;
            }
            elem = prev->data;
            prev->next = temp->next;
            temp->next = NULL;
            prev=NULL;
            delete temp;
            delete prev;
            count--;
        }
       }
        return elem;
    }
    int Linkedlist::removeFromHead(){

        int elem = head->data;
        if(isEmpty()){
            cout << "Cant't remove element. List is empty" << endl;
        }else if(head == tail){
            Node *temp = head;
            head = NULL;
            tail = NULL;
            delete temp;

        }else{
        Node *temp = head;
        head = head -> next;
        temp->next = NULL;
        delete temp;
        }
        count--;
        return elem;
    }
    int Linkedlist::removeFromTail(){
        int elem = tail->data;
        if(isEmpty()){
            cout << "Cant't remove element. List is empty" << endl;
        }else if(head == tail){
            removeFromHead();
        }else{
            Node *temp1 = head;
            Node *temp2 = tail;
            cout << "Tail Data: " << temp2->data << endl;
            while(temp1->next != tail){
                temp1 = temp1->next;
                }
              tail = temp1;
              tail->next = NULL;
              delete temp2;
              temp1 = NULL;
              delete temp1;
              count--;
            }
        return elem;
        }

    int Linkedlist::search(int elem){

        int pos = 0;
        if(isEmpty()){
            cout << "List is empty. Cannot search." << endl;
        }else{
            Node *temp = head;
            while(temp != NULL){
                if(temp->data == elem){
                    return pos;
                }else{
                    temp = temp->next;
                    pos++;
                }
            }
        }
        return -1;
    }
    void Linkedlist::printList(){

        if(isEmpty()){
            cout << "List is empty. Nothing to print" << endl;
        }else{
            Node *temp = head;
            while(temp != NULL){
                cout << "[";
                cout << temp->data;
                cout << "]->";
                temp=temp->next;
            }
            cout <<"x";
            cout << endl;

            cout << "Tail: " << tail->data << endl;
        }

    }
    int Linkedlist:: getListLength(){
        return count;
    }
    bool Linkedlist::isEmpty(){
        if(count == 0){
            return true;
        }
        return false;
    }
