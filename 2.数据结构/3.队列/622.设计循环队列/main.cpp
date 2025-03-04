#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;


class MyCircularQueue {
private:
    vector<int> list{};
    int front;
    int rear;
    int capacity;
public:
    MyCircularQueue(int k) {
        this->capacity = k + 1;
        this->list = vector<int>(capacity);
        rear = front = 0;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        list[rear] = value;
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
        return list[front];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return list[(rear - 1 + capacity) % capacity];
    }
    
    bool isEmpty() {
        return front == rear;
    }
    
    bool isFull() {
        return (rear + 1) % capacity == front;
    }
};


int main(int argc, char const *argv[]){
    MyCircularQueue circularQueue(8);
    cout << circularQueue.enQueue(3) << endl;  
    cout << circularQueue.enQueue(9) << endl;  
    cout << circularQueue.enQueue(5) << endl;  
    cout << circularQueue.enQueue(0) << endl;  
    cout << circularQueue.deQueue() << endl;  
    cout << circularQueue.deQueue() << endl;  
    cout << circularQueue.isEmpty() << endl;  
    cout << circularQueue.isEmpty() << endl;  
    cout << circularQueue.Rear() << endl;  
    cout << circularQueue.Rear() << endl;
    cout << circularQueue.deQueue() << endl;


    return 0;
}