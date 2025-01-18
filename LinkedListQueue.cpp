#include <iostream>
#include <stdexcept>

template <typename E>

class LinedListQueue {
private:
    struct Node{
        E data;
        Node* next;

        Node(E it){
            data = it;
            next = nullptr;
        }
    };

    int size;
    Node* head;
    Node* tail;

public:
    LinedListQueue() : head(nullptr), tail(nullptr), size(0) {};

    ~LinedListQueue() {};

    void enqueue(E value) {
        Node* newNode = new Node(value);
        if(size == 0)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    };

    E dequeue(){
        if(size == 0){
            throw std::underflow_error("Queue is empty");
        }
        E frontValue = head->data;
        Node* temp = head;
        head = head->next;
        if(head == nullptr)
        {
            tail = nullptr;
        }
        delete temp;
        size--;
        return frontValue;  
    };

    E frontValue() {
        if (size == 0)
        {
            throw std::underflow_error("Queue is empty");
        }
        return head->data;
    }

    void print(){
        if (size == 0)
        {
            std::cout<< "Queue is empty"<< std::endl;
            return;
        }
        Node* curr = head;
        while(curr != nullptr)
        {
            std::cout << curr->data << std::endl;
            curr = curr->next;
        }
    }

};

int main() {
    LinedListQueue<int> queue;

    try {
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);
        queue.enqueue(4);
        queue.enqueue(5);

        std::cout << "Queue after enqueuing 5 elements:" << std::endl;
        queue.print();

        std::cout << "Front value: " << queue.frontValue() << std::endl;

        std::cout << "Dequeuing an element: " << queue.dequeue() << std::endl;

        std::cout << "Queue after dequeuing one element:" << std::endl;
        queue.print();

        std::cout << "Front value: " << queue.frontValue() << std::endl;
    } catch (const std::exception& e) {
        std::cerr <<"Exception: " << e.what()<< std::endl;
    }
    return 0;
}