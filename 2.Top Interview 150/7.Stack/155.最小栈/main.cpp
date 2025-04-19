#include<stack>
using namespace std;

class MinStack {

stack<int> comm;
stack<int> minst;

public:
    MinStack() {
        minst.push(INT_MAX);
    }
    
    void push(int val) {
        comm.push(val);
        minst.push(min(val, minst.top()));
    }
    
    void pop() {
        minst.pop();
        comm.pop();
    }
    
    int top() {
        return comm.top();
    }
    
    int getMin() {
        return minst.top();
    }
};
