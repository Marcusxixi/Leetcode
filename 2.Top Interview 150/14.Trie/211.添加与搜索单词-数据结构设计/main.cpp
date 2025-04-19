#include<string>
#include<vector>
#include<queue>
using namespace std;


class WordDictionary {
vector<WordDictionary*> childiren;
bool isEnd;
public:
    WordDictionary(): childiren(26, nullptr), isEnd(false) {}
    
    void addWord(const string& word) {
        WordDictionary* node = this;
        for (const char& ch: word) {
            if (!node->childiren[ch - 'a']) node->childiren[ch - 'a'] = new WordDictionary();
            node = node->childiren[ch - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(const string& word) {
        dfs(word, 0, this);
    }

    bool dfs(const string& word, int index, WordDictionary* node) {
        if (index == word.size()) return node->isEnd;
        char ch = word[index];
        if (ch >= 'a' && ch <= 'z') {
            WordDictionary* child = node->childiren[ch - 'a'];
            if (child && dfs(word, index + 1, child)) return true;
        } else if (ch == '.') {
            for (int i = 0; i < 26; ++i) {
                WordDictionary* child = node->childiren[i];
                if (child && dfs(word, index + 1, child)) return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */