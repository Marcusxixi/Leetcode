#include<vector>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left = 0, right = people.size() - 1;
        int ret = 0;
        // left == right 的时候是剩下一个人的时候 也需要上船
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                ++left;
                --right;
            } else {
                --right;
            }
            ++ret;
        }
        return ret;
    }
};