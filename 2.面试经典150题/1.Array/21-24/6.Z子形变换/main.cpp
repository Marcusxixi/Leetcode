#include<string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length(), r= numRows;
        if (r == 1 || r >= n) return s;

        string ret;
        int term = 2 * r - 2; 
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j + i < n; j += term) {
                ret += s[j + i];
                if (0 < i && i < r - 1 && j + term - i < n) {
                    ret += s[j + term - i];
                }
            }
        }
        return ret;
    }
};

/*


0             0+t                    0+2t                     0+3t
1      t-1    1+t            0+2t-1  1+2t            0+3t-1   1+3t
2  t-2        2+t  0+2t-2            2+2t  0+3t-2             2+3t  
3             3+t                    3+2t                     3+3t


*/