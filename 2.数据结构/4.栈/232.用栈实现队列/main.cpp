#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

//当使用两个栈来实现队列的时候，需要在pop的时候并且输出栈为空的时候交换里面的值
class MyQueue {
private:
    stack<int> st1;
    stack<int> st2;
    void in2out(){
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
    }

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st2.push(x);
    }
    
    int pop() {
        if (st1.empty()) {
            in2out();
        }
        int ret = st1.top();
        st1.pop();
        return ret;

    }
    
    int peek() {
        if (st1.empty()) {
            in2out();
        }
        return st1.top();
    }
    
    bool empty() {
        return st1.size() == 0 && st2.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */


int main(int argc, char const *argv[]){
    MyQueue myQueue;
    myQueue.push(1); // queue is: [1]
    myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
    myQueue.push(3); 
    myQueue.push(4); 
    cout << myQueue.pop() << endl; // return 1
    cout << myQueue.pop() << endl; // return 1, queue is [2]
    cout << myQueue.empty() << endl;; // return false

    return 0;
}