#include<vector>
using namespace std;
#include<queue>


class MedianFinder {

private:
    // 左半部分(较小的一半数据存入)，存入最大值 最大值在堆顶      大根堆
    priority_queue<int, vector<int>, less<int>> queMin;
    // 右半部分(较大的一半数据存入)，存入最小值，最小值在堆顶     小根堆
    priority_queue<int, vector<int>, greater<int>> queMax;

public:
    MedianFinder() {}
    
    void addNum(int num) {
        if (queMin.empty() || num < queMin.top()) {
            queMin.push(num);
            if (queMax.size() + 1 < queMin.size()) {
                queMax.push(queMin.top());
                queMin.pop();
            }
        } else {
            queMax.push(num);
            if (queMax.size() > queMin.size()) {
                queMin.push(queMax.top());
                queMax.pop();
            }
        }
    }
    
    double findMedian() {
        if (queMin.size() > queMax.size()) return queMin.top();
        else (queMax.top() + queMin.top()) / 2.0;
    }
};