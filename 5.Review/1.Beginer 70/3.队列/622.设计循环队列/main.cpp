#include<vector>
using namespace std;

class MyCircularQueue {
public:
    vector<int> q;
    int capacity;
    int front;
    int rear;

    MyCircularQueue(int k) {
        capacity = k + 1;
        q.resize(capacity);
        rear = front = 0;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        q[rear] = value;
        rear = (rear + 1) % capacity;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return q[front];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return q[(rear - 1 + capacity) % capacity];
    }
    
    bool isEmpty() {
        return front == rear;
    }
    
    bool isFull() {
        return (rear + 1) % capacity == front;
    }
};