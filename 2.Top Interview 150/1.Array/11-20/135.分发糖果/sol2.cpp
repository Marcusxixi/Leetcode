#include<vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        // inc 单枪上升序列的长度（最近连续上升的长度）
        // dec 当前下降序列的长度
        // pre 上一个孩子应该分发的长度
        // ret 总的糖果数量
        int ret = 1;
        int inc = 1, dec = 0, pre = 1;
        for (int i = 1; i < n; ++i) {
            // 当前孩子的分数比上一个孩子的分数高
            if (ratings[i] >= ratings[i - 1]) {
                //下降序列变成 0 了
                dec = 0;
                //如果分数相等，当前分一个，否则+1
                pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
                ret += pre;
                //更新上升序列
                inc = pre;
            //当前孩子分数比上一个孩子的分数低
            } else {
                // 进入下降状态
                ++dec;
                if (dec == inc) {
                    //补偿前面最高点
                    ++dec;
                }
                ret += dec;
                // 孩子糖果归一
                pre = 1;
            }
        }
        return ret;
    }
};