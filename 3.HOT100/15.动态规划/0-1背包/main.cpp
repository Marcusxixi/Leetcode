/*
capacity: 背包容量
w[i]: 第 i 个物品的体积
v[i]: 第 i 个物品的价值
返回: 所选物品体积和不超过 capacity 的前提下，所能得到的最大价值和
*/

/*
                       ｜-  当前操作？枚举第 i 个物品选或者不选：不选，剩余容量不变，选，剩余容量减少 w[i]       
backtrace 3 question  -｜-  子问题？ 在剩余容量为 c 时，从前 i 个物品中得到的最大价值和
                        |-  下一个子问题？分类讨论：不选：在剩余容量为 c 时，从前 i-1 个物品中得到的最大价值和
                                                 选：在剩余容量为 c - w[i]时，从前 i-1 个物品中得到的最大价值和
*/




#include<vector>
using namespace std;
#include<functional>

int zero_one_knapsack(int capacity, vector<int> w, vector<int> v) {
    int n = w.size();
    // i 是第 i 件物品，c 是总体积
    function<int(int, int)> dfs = [&](int i, int c) -> int {
        if (i < 0) return 0;
        // 当现在选择的物品体积超过了 capacity 的话 就不选这个物品，继续寻找下一个小于当前 capacity 的物品
        if (c < w[i]) return dfs(i - 1, 0);
        // 选择这件物品 或者不选这件物品
        return max(dfs(i - 1, c), dfs(i - 1, c - w[i]) + v[i]);
    };
    return dfs(n - 1, capacity);
}

int main(int argc, char const *argv[])
{
    
    return 0;
}



