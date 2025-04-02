#include<vector>
using namespace std;

class Solution {
    public:
        int jump(vector<int>& nums) {
            int n = nums.size(), max_pos = 0, end = 0, step = 0;
            for (int i = 0; i < n - 1; ++i) {
                // 如果 maxPos >= i, 表示当前位置i可达(确保不会走到死路)
                if (max_pos >= i) {
                    // 更新maxPos, 表示目前能跳到最远的距离
                    max_pos = max(max_pos, i + nums[i]);
                    // 到达最远的距离，必须要再跳一次
                    if (i == end) {
                        // 更新最远距离
                        end = max_pos;
                        ++step;
                    }
                }
            }
            return step;
        }
    };