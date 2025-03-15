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
    int minCostToMoveChips(vector<int>& position) {
        if (position.empty()) return 0;
        int odd = 0;
        int even = 0;
        for (int i = 0; i < position.size(); i++) {
            if (position[i] % 2 == 0) even++;
            else odd++;
        }
        return min(odd, even);
    }
};


int main(int argc, char const *argv[]){
    return 0;
}