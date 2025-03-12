#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
using namespace std;


class Solution {
public:
    int minMaxDifference(int num) {
        string maxNumStr = to_string(num);
        string minNumStr = to_string(num);
        char maxChar = maxNumStr[0];
        char minChar = minNumStr[0];
        replace(maxNumStr.begin(), maxNumStr.end(), maxChar, '9');
        replace(minNumStr.begin(), minNumStr.end(), minChar, '0');
        cout << maxNumStr << " " << minNumStr << endl;
        return stoi(maxNumStr) - stoi(minNumStr);
    }
};


int main(int argc, char const *argv[]){
    int num = 11891;
    Solution sol;
    cout << sol.minMaxDifference(num) << endl;
    return 0;
}