#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;


class UnionFind {
public:
vector<int> city_map;
int city;


    UnionFind(vector<vector<int>>& isConnected) {
        city_map = vector<int>(isConnected.size());
        for (int i = 0; i < isConnected.size(); i++) {
            city_map[i] = i;
        }
        city = isConnected.size();
    }

    int find(int x) {
        if (city_map[x] == x) return city_map[x];
        else {
            city_map[x] = find(city_map[x]);
            return city_map[x];
        }
    }

    void unionCity(int city1, int city2) {
        int root1 = find(city1);
        int root2 = find(city2);
        if (root1 != root2) {
            city_map[root1] = root2;
            city -= 1;
        }
    }
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int row = isConnected.size();
        int col = isConnected[0].size();
        if (isConnected.empty() || row == 0) return 0;

        UnionFind uf(isConnected);
        for(int i = 0; i < row; i++) {
            for (int j = i; j < col; j++) {
                if (j != i && isConnected[i][j] == 1) {
                    uf.unionCity(i, j);
                }
            }
        }
        return uf.city;
    }
};


int main(int argc, char const *argv[]){
    vector<vector<int>> isConnected = {{1,1,0}, {1,1,0}, {0,0,1}};

    Solution sol;
    cout << sol.findCircleNum(isConnected) << endl;
    
    return 0;
}