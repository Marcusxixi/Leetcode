#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
using namespace std;


class Solution {

vector<vector<int>>edges;
vector<int>indeg;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        indeg.resize(numCourses);

        for(const auto& info: prerequisites) {
            edges[info[1]].push_back(info[0]);
            ++indeg[info[0]];
        }

        queue<int> q;
        for(int i = 0; i < numCourses; ++i) {
            if(indeg[i] == 0) q.push(i);
        }

        int visited = 0;

        while(!q.empty()) {
            int q_index = q.front(); q.pop();
            ++visited;

            for (int v: edges[q_index]){
                --indeg[v];
                if(indeg[v] == 0) q.push(v);
            }
        }
        return visited == numCourses;
    }
};


int main(int argc, char const *argv[]){
    return 0;
}