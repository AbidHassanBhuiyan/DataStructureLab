#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class MyQueue {
private:
    Node* front;
    Node* rear;

public:
    MyQueue() : front(nullptr), rear(nullptr) {}

    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return front->data;
    }

    bool isEmpty() {
        return front == nullptr && rear == nullptr;
    }
};

int main() {
    MyQueue myQueue;

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    cout << "Front element of the queue: " << myQueue.getFront() << endl;

    myQueue.dequeue();

    cout << "Front element after dequeue: " << myQueue.getFront() << endl;

    return 0;
}
