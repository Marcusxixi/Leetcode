#include<iostream>
using namespace std;
#include<vector>

class Trie {

vector<Trie*> children;
bool isEnd;

public:
    Trie(): children(26, nullptr),  isEnd(false) {}
    
    void insert(const string& word) {
        Trie* node = this;
        for (char ch: word) {
            if (!node->children[ch - 'a']) {
                node->children[ch - 'a'] = new Trie();
            }
            node = node->children[ch - 'a'];
        }
        node->isEnd = 1;
    }
    
    bool search(const string& word) {
        Trie* node = this;
        for (char ch: word) {
            if (!node->children[ch -'a']) return 0;
            node = node->children[ch -'a'];
        }
        return node->isEnd;
    }
    
    bool startsWith(const string& prefix) {
        Trie* node = this;
        for (char ch: prefix) {
            if (! node->children[ch - 'a']) return 0;
            node = node->children[ch - 'a'];
        }
        return 1;
    }
};
