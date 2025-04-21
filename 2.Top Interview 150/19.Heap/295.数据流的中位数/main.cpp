#include<queue>
using namespace std;

class MedianFinder {
private:
    priority_queue<int, vector<int>, less<>> left;
    priority_queue<int, vector<int>, greater<>> right;

public:
    MedianFinder() {}
    
    void addNum(int num) {
        if (left.empty() || num < left.top()) {
            left.push(num);
            if (right.size() + 1 < left.size()) {
                right.push(left.top());
                left.pop();
            }
        } else {
            right.push(num);
            if (right.size() > left.size()) {
                left.push(right.top());
                right.pop();
            }
        }
    }
    
    double findMedian() {
        if (left.size() > right.size()) return left.top();
        return (left.top() + right.top()) / 2.0;
    }
};