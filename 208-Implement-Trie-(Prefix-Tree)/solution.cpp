class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() : hasword(false) {
        memset(next, NULL, 26*sizeof(TrieNode*));
    }
    
    TrieNode* next[26];
    bool hasword;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* rt = root;
        
        for(auto ch : word)
        {
            TrieNode* &tmp = rt->next[ch-'a'];
            if(tmp == NULL)
                tmp = new TrieNode();
            rt = tmp;
        }
        
        rt->hasword = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* rt = root;
        
        for(auto ch : word)
        {
            TrieNode* tmp = rt->next[ch-'a'];
            if(tmp == NULL)
                return false;
            rt = tmp;
        }
        return rt->hasword;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* rt = root;
        
        for(auto ch : prefix)
        {
            TrieNode* tmp = rt->next[ch-'a'];
            if(tmp == NULL)
                return false;
            rt = tmp;
        }
        
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");