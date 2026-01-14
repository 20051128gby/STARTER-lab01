// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    head = nullptr;
    tail = nullptr;

    if (source.head == nullptr) {
        return;
    }
    head = new Node;
    head->info = source.head->info;
    head->next = nullptr;
    tail = head;
    Node* curr = source.head->next;
    while (curr != nullptr) {
        Node* newNode = new Node;
        newNode->info = curr->info;
        newNode->next = nullptr;

        tail->next = newNode;
        tail = newNode;

        curr = curr->next;
    }
}

IntList::~IntList() {
    Node* curr = head;
    while (curr != nullptr) {
        Node* next = curr->next; 
        delete curr;
        curr = next;
    }
    head = nullptr;
    tail = nullptr;
}


// return sum of values in list
int IntList::sum() const {
    Node* curr = head;
    int sum = 0;
    while(curr != nullptr){
        sum += curr->info;
        curr = curr->next;
    }
    return sum; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {

    Node* curr = head;
    while(curr != nullptr){
        if(curr->info == value){
            return true;
        }else{
            curr = curr->next;
        }
    }
    return false; // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    Node* curr = head;
    int max = 0;
    while(curr != nullptr){
        if(curr->info > max){
            max = curr->info;
        }
        curr = curr->next;
    }
    return max; // REPLACE THIS NON-SOLUTION
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    return sum()/count(); // REPLACE THIS NON-SOLUTION
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* newNode = new Node;
    newNode->info = value;
    newNode->next = head;

    head = newNode;     
    if (tail == nullptr) {
        tail = newNode;
    }
}


void IntList::push_back(int value) {
    Node* newNode = new Node;
    newNode->info = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}


// return count of values
int IntList::count() const {
   //IMPLEMENT THIS
    Node* curr = head;
    int len = 0;
   while (curr != nullptr)
   {
    len+=1;
    curr = curr->next;
   }
   return len;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    //IMPLEMENT
    Node* curr = head;
    while(source != nullptr)

    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    //IMPLEMENT THIS 

    head = nullptr;
    tail = nullptr;
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

