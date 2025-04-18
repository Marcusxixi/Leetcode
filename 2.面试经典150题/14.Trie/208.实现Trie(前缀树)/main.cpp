#include<vector>
#include<string>
using namespace std;

class Trie {
vector<Trie*> children;
bool isEnd;
public:
    Trie(): children(26, nullptr), isEnd(false) {}
    
    void insert(const string& word) {
        Trie* node = this;
        for (const char& ch: word) {
            if (!node->children[ch - 'a']) node->children[ch -'a'] = new Trie();
            node = node->children[ch -'a'];
        }
        node->isEnd = true;
    }
    
    bool search(const string& word) {
        Trie* node = this;
        for (const char& ch: word) {
            if (!node->children[ch - 'a']) return false;
            node = node->children[ch - 'a'];
        }
        return node->isEnd;
    }
    
    bool startsWith(const string& prefix) {
        Trie* node = this;
        for (const char& ch: prefix) {
            if (!node->children[ch - 'a']) return false;
            node = node->children[ch - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */