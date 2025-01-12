#include <iostream>
#include <stdexcept> // Include for std::out_of_range

// Abstract Stack Class
class Stack {
protected:
    Stack() {} // Prevent direct instantiation
private:
    Stack(const Stack&); // Copy constructor
    void operator=(const Stack&); // Assignment operator

public:
    virtual ~Stack() {}

    virtual void push(int value) = 0;
    virtual int pop() = 0;
    virtual void clear() = 0;
    virtual int length() const = 0;
    virtual int topValue() const = 0;
};

// Dynamic Array Stack Class
class ArrayStack : public Stack {
private:
    int* arr;
    int maxSize;
    int top;

public:
    ArrayStack(int size) : maxSize(size), top(-1), arr(new int[size]) {}

    ~ArrayStack() {
        delete[] arr;
    }

    void clear()  {
        top = -1; // Reset top to -1 to indicate an empty stack
    }

    void push(int value)  {
        if (top >= maxSize - 1) {
            throw std::overflow_error("Stack is full");
        }
        arr[++top] = value;
    }

    int pop()  {
        if (top < 0) {
            throw std::underflow_error("Stack is empty");
        }
        return arr[top--];
    }

    int topValue() const  {
        if (top < 0) {
            throw std::out_of_range("Stack is empty");
        }
        return arr[top];
    }

    int length() const  {
        return top + 1; // Return the number of elements in the stack
    }
};

int main() {
    try {
        ArrayStack stack(10); // Create a stack with a maximum size of 10

        // Perform stack operations
        stack.push(11);
        std::cout << "The top value: " << stack.topValue() << std::endl;
        std::cout << "The length of the stack: " << stack.length() << std::endl;

        stack.push(12);
        stack.push(13);
        std::cout << "The top value: " << stack.topValue() << std::endl;
        std::cout << "The length of the stack: " << stack.length() << std::endl;

        stack.pop();
        std::cout << "The top value: " << stack.topValue() << std::endl;
        std::cout << "The length of the stack: " << stack.length() << std::endl;

        stack.clear();

        // Attempt to access the top value after clearing the stack
        stack.topValue(); // This will throw an exception

    } catch (const std::overflow_error& e) {
        std::cerr << "Overflow Error: " << e.what() << std::endl;
    } catch (const std::underflow_error& e) {
        std::cerr << "Underflow Error: " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Out of Range Error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        // Catch-all for any other standard exceptions
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}
