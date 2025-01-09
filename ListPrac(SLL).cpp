#include <iostream>
#include <cassert>

class Node {
public:
    int data;
    Node* next; // address to next node
    Node(int element, Node* nextVal = nullptr)
    {
        data = element;
        next = nextVal;
    }
};

class S_LinkedList{
public:
    S_LinkedList(): head(nullptr), tail(nullptr), cnt(0){}

    ~S_LinkedList()
    {
        while(head != nullptr)
        {
            curr = head;
            head = head->next;
            delete curr;
        }
    }

    void append(const int& value)
    {
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
        }
        else{
            tail->next = newNode;
        }
        tail = newNode;
        cnt++;
    }

    // insert(position, value)
    void insertAt(int pos,const int& value)
    {
        assert(pos >= 0 || pos <= cnt && "Position out of range");
        if(pos == 0)
        {
            head = new Node(value, head);
        }
        else if(pos == cnt)
        {
            append(value);
        }
        else
        {
            curr = head;
            for(int i = 0; i < pos - 1; i++){
                curr = curr->next;
            }
            curr->next = new Node(value, curr->next);
        }
        cnt++;
    }
    
    void remove(int value)
    {

        if(head == nullptr){ return;}   // empty list

        // case 1: remove head node
        if(head->data == value)
        {
            Node* toDelete = head;
            head = head->next;
            delete toDelete; // to prevent memory leak
            cnt--;
            return;
        }

        Node* temp = head;
        // case 2: remove a node in the list
        while(temp->next != nullptr && temp->next->data != value)
        {
            temp = temp->next;    
        }

        if(temp->next != nullptr)
        {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete; // to prevent memory leak
            cnt--;
        }
    }
    
    void print()
    {
        Node* curr = head;
        while(curr != nullptr){
            std::cout << curr->data << std::endl;
            curr = curr->next;
        }
        std::cout << "--------"<< std::endl;
    }

    void printCurr()
    {
        std::cout << curr->data <<std::endl;
    }

    void next()
    {
        if(curr != tail)
        {
            curr = curr->next;
        }
    }

    void prev()
    {
        if(curr == head){
            return;
        }
        Node* temp = head;
        while(temp->next != curr)
        {
            temp = temp->next;
        }
        curr = temp;
    }

    int currPos() const
    {
        Node* temp = head;
        int i;
        for(i = 0; curr != temp; i++)
        {
            temp = temp->next;
        }
        return i;
    }

    int getCurrValue() const
    {
        if(curr == nullptr || curr == tail){
            throw std::runtime_error("No value at current position");
        }
        return curr->data;
    }

private:
    Node* head;
    Node* tail;
    Node* curr;
    int cnt;
};

int main(){
    S_LinkedList myLL;
    myLL.append(1);
    myLL.append(2);
    myLL.append(3);
    myLL.append(4);
    myLL.print();
    myLL.remove(2);
    myLL.print();
    myLL.insertAt(2, 8);
    std::cout << "Current Position: " << myLL.currPos() << ", Current Value: " << myLL.getCurrValue() << std::endl;
    myLL.print();
    
    return 0;
}