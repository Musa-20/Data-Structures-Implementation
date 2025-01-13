#include <iostream>
#include <stdexcept>

class LinkedListStack{
private:
    struct Node{
        int data;
        Node* next;

        Node(int value): data(value), next(nullptr) {}
    };

    Node* top;
    int size;
public:
    LinkedListStack(): top(nullptr), size(0) {};
    ~LinkedListStack(){
        while (top != nullptr){
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    };

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        size++;
        /* or top = new Node*(value, top)*/
    }

    int pop(){
        // check if stack is empty
        if (isEmpty())
        {
            throw std::out_of_range("Cannot Pop from stack, stack is empty");
        }
        int valuePop = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
        return valuePop;
    };

    int topValue(){
        // check if stack is empty
        if (isEmpty())
        {
            throw std::out_of_range("Cannot get top value, stack is empty");
        }
        return top->data;
    };

    int length() {
        // check if stack is empty
        if (top == nullptr)
        {
            return 0;
        }
        return size;
    };

    bool isEmpty() const{
        return top == nullptr;
    };
};

int main(){
    LinkedListStack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout << "Top Value: " << stack.topValue() << std::endl; // 3
    std::cout << "Stack Size: " << stack.length() << std::endl; // 3

    stack.pop();
    std::cout << "Top Value: " << stack.topValue() << std::endl; // 2
    std::cout << "Stack Size: " << stack.length() << std::endl; // 2
    stack.pop();
    std::cout << "Top Value: " << stack.topValue() << std::endl; // 1
    std::cout << "Stack Size: " << stack.length() << std::endl; // 1

    stack.pop();
    std::cout << "Stack Size: " << stack.length() << std::endl; // 0

    try{
        std::cout << "Top Value: " << stack.topValue() << std::endl;
    } catch(const std::out_of_range& e){
        std::cout <<"Error Occured: " << e.what() << std::endl;
    }

    try{
        stack.pop();
    } catch(const std::out_of_range& e){
        std::cout <<"Error Occured: " << e.what() << std::endl;
    }

    std::cout << "Stack Size: " << stack.length() << std::endl;

    return 0;
}