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
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hash_map;
        vector<string> rec;
        for (const string& word : words) {
            if (hash_map[word] == 0) rec.emplace_back(word);
            hash_map[word]++;

        }

        // 这个lambda表达式的意思是 如果hash_map中的a的频率等于b的频率的话就要比较他们的alpha的值，小的在前面，如果频率不一样 频率高的排在前面
        sort(rec.begin(), rec.end(), [&](const string& a, const string& b) ->bool {
            return hash_map[a] == hash_map[b] ? a < b : hash_map[a] > hash_map[b];
        });

        rec.erase(rec.begin() + k, rec.end());
        return rec;
    }
};


int main(int argc, char const *argv[]){

    auto print = [](const vector<int>& nums){
        for (const auto& num : nums) {
            cout << num << " ";
        }
        cout << endl;
    };

    auto printS = [](const vector<string>& nums){
        for (const auto& num : nums) {
            cout << num << " ";
        }
        cout << endl;
    };

    auto order = [](const int a, const int b) -> bool {
        return a < b;
    };
    vector<int> nums = {5,3,4,1,2};
    print(nums);
    sort(nums.begin(), nums.end(), [] (const int a, const int b) {return a < b;});
    print(nums);
    sort(nums.begin(), nums.end(), order);
    print(nums);


    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    vector<string> cp;
    for (const string& word : words){
        cp.emplace_back(word);
    }
    printS(cp);

    Solution sol;
    printS(sol.topKFrequent(words, 2));
    return 0;
}