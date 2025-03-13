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

// private:
    vector<Trie*> children;
    bool isEnd;

    Trie* searchPrefix(string prefix) {
        Trie * node = this;
        for (char ch : prefix) {
            ch -= 'a';
            if (node->children[ch] == nullptr) return nullptr;
            node = node->children[ch];
        }
        return node;
    } 


public:
    Trie() {
        children.resize(26);
        isEnd = false;
    }
    
    void insert(string word) {
        Trie * node = this;
        for (char ch : word) {
            if (node->children[ch - 'a'] == nullptr) {
                node->children[ch - 'a'] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie * node = this->searchPrefix(word);
        return (node != nullptr && node->isEnd);
    }
    
    bool startsWith(string prefix) {
        return this->searchPrefix(prefix) != nullptr;
    }
};


int main(int argc, char const *argv[]){
    Trie* t = new Trie();
    return 0;
}