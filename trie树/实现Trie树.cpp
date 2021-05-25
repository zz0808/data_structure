class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curt = root;
        for (const auto& w : word) {
            unsigned int index = w - 'a';
            if (curt->nexts[index] == nullptr) {
                curt->nexts[index] = new TrieNode();
            }
            curt = curt->nexts[index];
        }
        curt->has_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* curt = root;
        for (const auto& w : word) {
            unsigned int index = w - 'a';
            if (curt->nexts[index] == nullptr) {
                return false;
            }
            curt = curt->nexts[index];
        }
        return curt->has_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curt = root;
        for (const auto& w : prefix) {
            unsigned int index = w - 'a';  
            if (curt->nexts[index] == nullptr) {
                return false;
            }
            curt = curt->nexts[index];
        }    
        return true;
    }

private:
    struct TrieNode {
        TrieNode* nexts[26];
        bool has_word;
        TrieNode(bool has_w = false)
            : has_word(has_w) { 
                fill(nexts, nexts + 26, nullptr);
        }
    };
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
