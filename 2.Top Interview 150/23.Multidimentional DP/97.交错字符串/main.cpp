#include<string>
using namespace std;
#include<vector>
#include<functional>
// #include<unordered_map>

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(), m = s2.length(), t = s3.length();
        if (n + m != t) return false;

        function<bool(int, int)> dfs = [&] (int i, int j) -> bool {
            int k = i + j;
            if (k == t) return true;

            bool ret = false;
            if (i < n && s1[i] == s3[k]) {
                ret = dfs(i + 1, j);
            }
            if (!ret && j < m && s2[j] == s3[k]) {
                ret = dfs(i, j + 1);
            }
            return ret;
        };
        return dfs(0, 0);


    }
};