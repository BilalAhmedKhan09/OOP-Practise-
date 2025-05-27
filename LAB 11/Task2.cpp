#include <iostream>
#include <exception>

using namespace std;

class QueueOverflowException : public exception {};

class QueueUnderflowException : public exception {};

template <typename T>
class Queue {
    T data[5];
    int front;
    int rear;
    int count;
    public:
    Queue() : front(0), rear(0), count(0) {}

    void enqueue(T value) {
        if (count == 5) {
            throw QueueOverflowException();
        }
        data[rear] = value;
        rear = (rear + 1) % 5;
        count++;
    }
    void dequeue() {
        if (count == 0) {
            throw QueueUnderflowException();
        }
        front = (front + 1) % 5;
        count--;
    }
    void display() {
        int i = front;
        int elements = count;
        while (elements--) {
            cout << data[i] << " ";
            i = (i + 1) % 5;
        }
        cout <<endl;
    }
};

int main() {
    Queue<int> q;
    try {
        for (int i = 0; i < 5; ++i) {
            q.enqueue(i + 1);
        }
        cout << "Attempting to enqueue to a full queue..." <<endl;
        q.enqueue(6); 
    }
    catch (const QueueOverflowException& e) {
        cout << "Caught QueueOverflowException - what(): " << e.what() <<endl;
    }
    try {
        for (int i = 0; i < 5; ++i) {
            q.dequeue();
        }
        cout << "Attempting to dequeue from an empty queue..." <<endl;
        q.dequeue();
    }
    catch (const QueueUnderflowException& e) {
        cout << "Caught QueueUnderflowException - what(): " << e.what() <<endl;
    }
}
