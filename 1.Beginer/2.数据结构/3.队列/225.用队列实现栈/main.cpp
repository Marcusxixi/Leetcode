#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;


class MyStack {
    queue<int> q1;
    queue<int> q2;
    public:
        MyStack() {
            
        }
        
        void push(int x) {
            q2.push(x);
            while (! q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }
            swap(q1, q2);

        }
        
        int pop() {
            if (empty()) return -1;
            int ret = q1.front();
            q1.pop();
            return ret;
        }
        
        int top() {
            if (empty()) return -1;
            return q1.front();
        }
        
        bool empty() {
            return q1.size() == 0;
        }
    };


int main(int argc, char const *argv[]){
    MyStack ms;
    ms.push(1);
    ms.push(2);
    cout << ms.top() << endl;
    cout << ms.pop() << endl;
    cout << ms.empty() << endl;

    return 0;
}