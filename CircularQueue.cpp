#include <iostream>

using namespace std;

class MyQueue {
private:
    static const int max_size = 5;
    int queue[max_size];
    int front;
    int rear;

public:
    MyQueue() : front(-1), rear(-1) {}

    void enqueue(int value) {
        if ((rear + 1) % max_size == front) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % max_size;
        }

        queue[rear] = value;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % max_size;
        }
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return queue[front];
    }

    bool isEmpty() {
        return front == -1 && rear == -1;
    }
};

int main() {
    MyQueue myQueue;

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.enqueue(4);
    myQueue.enqueue(5);

    cout << "Front element of the queue: " << myQueue.getFront() << endl;

    myQueue.dequeue();

    cout << "Front element after dequeue: " << myQueue.getFront() << endl;
    myQueue.enqueue(6);
    myQueue.enqueue(7);
    myQueue.dequeue();

    cout << "Front element after additional enqueue: " << myQueue.getFront() << endl;

    return 0;
}
