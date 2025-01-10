#include <iostream>
#include <cassert>

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val): data(val), next(nullptr), prev(nullptr) {};
};

// Double Linked List Class
class DoublyLinkedList{
private:
    Node* head;
    Node* tail;
    Node* curr;
    int cnt;
public:
DoublyLinkedList() : head(nullptr), tail(nullptr), curr(nullptr), cnt(0) {};

~DoublyLinkedList() {
    while(curr != nullptr)
    {
        curr = head;
        curr = curr->next;
        delete curr;
    }
};

void append(int val){
    Node* newNode = new Node(val);;
    if(head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    tail = newNode;
    cnt++;
};

void insertAt(int pos, const int& val){
    assert(pos >= 0 || pos <= cnt && "Position out of range");

    if(pos == 0)
    {
        Node* newNode = new Node(val);
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    else if(pos == cnt)
    {
        Node* newNode = new Node(val);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    else
    {
        curr = head;
        for(int i = 0; i < pos - 1; i++)
        {
            curr = curr->next;
        }
        Node* newNode = new Node(val);
        newNode->prev = curr;
        newNode->next = curr->next;
        curr->next->prev = newNode;
    }
    cnt++;
};

int remove(int value){
    if (head == nullptr){ return -1; }
    curr = head;
    while(curr != nullptr && curr->next->data != value)
    {
        curr = curr->next;
    }
    if(curr->next != nullptr)
    {
        int valueRemoved = curr->next->data;
        Node* temp = curr->next;
        curr->next = curr->next->next;
        curr->next->next->prev = curr;
        delete temp;
        cnt--;
        return valueRemoved;
    }
    // if curr ->next is nullptr, then the value is not in the list
    return -1;
};

void print(){
    curr = head;
    while(curr != nullptr)
    {
        std::cout << "<->" << curr->data << "<->";
        curr = curr->next;
    }
    std::cout << std::endl;
}

};

int main(){
    DoublyLinkedList dll;
    dll.append(1);
    dll.append(2);
    dll.append(3);
    dll.append(4);
    dll.append(5);
    dll.print();
    dll.remove(3);
    dll.print();
    return 0;
}