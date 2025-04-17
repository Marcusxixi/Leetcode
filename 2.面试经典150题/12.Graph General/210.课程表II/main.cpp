#include<vector>
#include<queue>
using namespace std;

class Solution {
private:
    vector<vector<int>> edges;
    vector<int> indeg;
    vector<int> ret;

public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        indeg.resize(numCourses);

        for (auto& info: prerequisites) {
            edges[info[1]].push_back(info[0]);
            ++indeg[info[0]];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            int q_index = q.front(); q.pop();
            ret.emplace_back(q_index);
            for (int v: edges[q_index]) {
                --indeg[v];
                if (!indeg[v]) q.push(v);
            }
        }
        return ret.size() == numCourses ? ret : vector<int>();
    }
};