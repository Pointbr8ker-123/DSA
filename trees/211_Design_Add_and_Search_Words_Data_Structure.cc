#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool end = false;
    ~TrieNode() {
        for (auto &p : children) {
            delete p.second;
        }
    }
};

struct Trie {
    TrieNode* root;
    Trie() : root(new TrieNode()) {}
    ~Trie() { delete root; }

    void insert(const string& word) {
        TrieNode* cur = root;
        for (char ch : word) {
            if (cur->children.count(ch) == 0) {
                cur->children[ch] = new TrieNode();
            }
            cur = cur->children[ch];
        }
        cur->end = true;
    }

    bool find(const string& word) {
        return findHelper(word, 0, root);
    }

private:
    bool findHelper(const string& word, int i, TrieNode* cur) {
        if (i == word.size()) return true;

        char c = word[i];

        if (c != '.') {
            if (cur->children.count(c) == 0) {
                return false;
            }
            return findHelper(word, i + 1, cur->children[c]);
        }

        for (auto& [c, child] : cur->children) {
            if (findHelper(word, i+1, child)) {
                return true;
            }
        }
        return false;
    }
};

class WordDictionary {
    Trie trie;
public:
    WordDictionary() {}
    
    void addWord(string word) {
        trie.insert(word);
    }
    
    bool search(string word) {
        return trie.find(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */