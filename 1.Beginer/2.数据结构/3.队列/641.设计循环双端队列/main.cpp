#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;


class MyCircularDeque {
private:
int front;
int rear;
int capacity;
vector<int> list;
public:
    MyCircularDeque(int k) {
        this->front = 0;
        this->rear = 0;
        this->capacity = k + 1;
        this->list = vector<int>(this->capacity);
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + capacity) % capacity;
        list[front] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        list[rear] = value;
        rear = (rear + 1) % capacity;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + capacity) % capacity;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return list[front];
    }
    
    int getRear() {
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
    MyCircularDeque circularDeque(3); // 设置容量大小为3
    cout << circularDeque.insertLast(1) << endl;			        // 返回 true
    cout << circularDeque.insertLast(2) << endl;			        // 返回 true
    cout << circularDeque.insertFront(3) << endl;			        // 返回 true
    cout << circularDeque.insertFront(4) << endl;			        // 已经满了，返回 false
    cout << circularDeque.getRear() << endl;  				// 返回 2
    cout << circularDeque.isFull() << endl;				        // 返回 true
    cout << circularDeque.deleteLast() << endl;			        // 返回 true
    cout << circularDeque.insertFront(4) << endl;			        // 返回 true
    cout << circularDeque.getFront() << endl;				// 返回 4
    return 0;
}