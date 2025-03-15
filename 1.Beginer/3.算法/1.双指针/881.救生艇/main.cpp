#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;


class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int ret = 0;
        int left = 0;
        int right = people.size() - 1;
        while (left <= right){
            if (people[left] + people[right] > limit){
                right--;
            } else {
                right--;
                left++;
            }
            ret++;
        }
        return ret;
    }
};


int main(int argc, char const *argv[]){
    vector<int> people = {3,2,2,1};
    Solution sol;
    int ret = sol.numRescueBoats(people, 3);
    cout << ret << endl;
    return 0;
}