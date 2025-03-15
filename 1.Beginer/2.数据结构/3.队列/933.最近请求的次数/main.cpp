#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;


class RecentCounter {
    queue<int> q;
    public:
        RecentCounter() {
            
        }
        
        int ping(int t) {
            q.push(t);
            while (q.front() < t - 3000){
                q.pop();
            }
            return q.size();

        }
    };


int main(int argc, char const *argv[]){
    RecentCounter rc;
    cout << rc.ping(1) << endl;
    cout << rc.ping(100) << endl;
    cout << rc.ping(3001)<< endl;
    cout << rc.ping(3002) << endl;
    
}