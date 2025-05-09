#include<stack>
using namespace std;

class MyQueue {
public:
    stack<int> stk1;
    stack<int> stk2;

    MyQueue() {
        
    }
    
    void push(int x) {
        stk2.push(x);
    }

    void in2out() {
        while (!stk2.empty()) {
            stk1.push(stk2.top());
            stk2.pop();
        }
    }
    
    int pop() {
        if (empty()) return -1;
        if (stk1.empty()) in2out();
        int ret = stk1.top();
        stk1.pop();
        return ret;
    }
    
    int peek() {
        if (empty()) return -1;
        if (stk1.empty()) in2out();
        return stk1.top();
    }
    
    bool empty() {
        return stk1.empty() && stk2.empty();
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