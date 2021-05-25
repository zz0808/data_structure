class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curt = root;
        for (auto& w : word) {
            int index = w - 'a';
            if (curt->nexts[index] == nullptr) {
                curt->nexts[index] = new TrieNode();
            }
            curt = curt->nexts[index];
        }
        curt->hasWord = true;
    }
    
    bool search(string word) {
        TrieNode* curt = root;
        return search_helper(0, curt, word);
    }

private:
    struct TrieNode {
        bool hasWord;
        TrieNode* nexts[26];
        TrieNode(bool hw = false) : hasWord(hw){
            fill(nexts, nexts + 26, nullptr);
        } 
    };
    TrieNode* root;

private:
    bool search_helper(int start, TrieNode* curt, string& word) {
        if (start == word.size()) {
            return curt->hasWord;
        }
        char c = word[start];
        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (curt->nexts[i] != nullptr) {
                    if (search_helper(start + 1, curt->nexts[i], word)) {
                        return true;
                    }
                }
            }
        } else if (curt->nexts[c - 'a'] != nullptr) {
            return search_helper(start + 1, curt->nexts[c - 'a'], word);
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
