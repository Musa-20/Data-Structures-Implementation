#include <iostream>
#include <stdexcept>

const int MAX = 5;


class ArrayQueue{
private:
    int m_last;
    int m_first;
    int array [MAX];
    int size;

public:
    ArrayQueue(){
        m_first = 0;
        m_last = 0;
        size = 0;
    };

    void enqueue(int value){
        if(size == MAX)
        {
            throw std::overflow_error("Queue is full");
        }
        array[m_last] = value;
        // circular incrementation
        m_last = (m_last + 1) % MAX;
        size++;
    };

    int dequeue(){
        if(size == 0)
        {
            throw std::overflow_error("Queue is empty");
        }
        else
        {
            int front_value = array[m_first];
            m_first = (m_first + 1) % MAX;
            size--;
            return front_value;
        }
    };

    // returns the element in front of the queue
    int frontValue(){
        if(size == 0){
            std::cout << "Queue is empty"<< std::endl;
            return 0;
        }
        return array[m_first];
    }

    // return the element right after the queue
    int nextUp(){
        if(size == 0){
            std::cout << "Queue is empty"<< std::endl;
            return 0;
        }
        std::cout << "NEXT!!!: ";
        return array[(m_first + 1 )% MAX];
    }

    int maxSize(){
        return MAX;
    }

    int getSize(){

        return size;
    };

    void print(){
        if(size == 0){
            std::cout << "Queue is empty"<< std::endl;
            return;
        }
        std::cout << "Queue Order: \n";
        int index = m_first;
        for(int i = 0; i < size; i++){
            std::cout << array[index]<<std::endl;
            index = (index + 1) % MAX;
        }
    };
};

int main() {
    ArrayQueue queue;

    // Enqueue elements
    try {
        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);
        queue.enqueue(40);
        queue.enqueue(50);
        // Attempt to enqueue to a full queue
        queue.enqueue(60);
    } catch (const std::overflow_error& e) {
        std::cout << e.what() << std::endl;
    }

    queue.print();

    // Dequeue elements
    try {
        std::cout << "Dequeued: " << queue.dequeue() << std::endl;
        std::cout << "Dequeued: " << queue.dequeue() << std::endl;
    } catch (const std::underflow_error& e) {
        std::cout << e.what() << std::endl;
    }

    queue.print();

    std::cout << "Front value: " << queue.frontValue() << std::endl;

    std::cout << queue.nextUp() << std::endl;

    std::cout << "Queue size: " << queue.getSize() << std::endl;

    std::cout << std::endl;

    try {
        queue.enqueue(80);
        queue.enqueue(90);
        // Attempt to enqueue to a full queue
        queue.enqueue(100);

    } catch (const std::overflow_error& e) {
        std::cout << e.what() << std::endl;
    }

    queue.print();

    try {
        std::cout << "Dequeued: " << queue.dequeue() << std::endl;
        std::cout << "Dequeued: " << queue.dequeue() << std::endl;
    } catch (const std::underflow_error& e) {
        std::cout << e.what() << std::endl;
    }

    queue.print();

    std::cout << "Front value: " << queue.frontValue() << std::endl;

    std::cout << queue.nextUp() << std::endl;

    std::cout << "Queue size: " << queue.getSize() << std::endl;

    return 0;
}