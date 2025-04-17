#include<vector>
#include<string>
#include<unordered_map>
using namespace std;


class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        int size = equations.size();
        unordered_map<string, int> hash_table(2 * size);
        UnionFind uf(2 * size);
        int index = 0;
        for (int i = 0; i < size; ++i) {
            string var1 = equations[i][0];
            string var2 = equations[i][1];

            if (!hash_table.count(var1)) hash_table[var1] = index++;
            if (!hash_table.count(var2)) hash_table[var2] = index++;
            uf.unite(hash_table[var1], hash_table[var2], values[i]);
        }

        vector<double> ret;
        for (int i = 0; i < queries.size(); ++i) {
            string var1 = queries[i][0];
            string var2 = queries[i][1];
            if (!hash_table.count(var1) || !hash_table.count(var2)) ret.emplace_back(-1.0);
            else ret.emplace_back(uf.isConnected(hash_table[var1], hash_table[var2]));
        }
        return ret;

    }

private:
    // 建立并查集
    class UnionFind {
    private:
        vector<int> parent;
        vector<double> weight;

    public:
        UnionFind(int n) : parent(n), weight(1.0) {
            for (int i = 0; i < n; ++i) {
                parent[i] = i;
            }
        }

        // 将 x 所在的子树链接到 y 所在的子树
        void unite(int x, int y, double value) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX == rootY) return;
            parent[rootX] = rootY;
            weight[rootX] = weight[y] * value / weight[x];
            /*
               rx---ry
              /     /
             x --- y
            */
        }

        // 找到父节点并压缩路径
        int find(int x) {
            if (x != parent[x])  {
                int x_father = parent[x];
                parent[x] = find(parent[x]);
                weight[x] *= weight[x_father];
            }
            return parent[x];
        }

        // 计算结果
        double isConnected(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX == rootY) return weight[x] / weight[y];
            else return -1.0;
        }
    };
};