#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
using namespace std;


class Trie {

    vector<Trie*> children;
    bool isEnd;

public:
    Trie(): children(26), isEnd(false){}

    bool insert(string word){
        Trie* node = this;
        for (char& ch : word) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
        return true;
    }


    bool search(string word){
        Trie * node = this;
        for (char& ch : word) {
            ch -= 'a';
            if (node->children[ch] == nullptr || !node->children[ch]->isEnd) return false;
            node = node->children[ch];
        }
        return node != nullptr && node->isEnd;
    };


};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie tr;
        for (const auto& word : words) {
            tr.insert(word);
        }
        string longest = "";
        for (const auto& word : words) {
            if (tr.search(word)) {
                if (word.size() > longest.size() || word.size() == longest.size() && word < longest) {
                    longest = word;
                }
            }
        }
        return longest;
    }
};


int main(int argc, char const *argv[]){

}