class TrieNode {
    public:
    char val;
    bool isWord;
    vector<TrieNode*>child;

     TrieNode(char value)
        : val(value), isWord(false), child(26, nullptr)
    {}
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode('/');
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(int i=0;i<word.size();i++) {
            if(curr->child[word[i]-'a']==nullptr) {
                TrieNode* tp = new TrieNode(word[i]);
                curr->child[word[i]-'a'] = tp;
            }
            curr= curr->child[word[i]-'a'];
        }
        curr->isWord = true;
    }
    
    bool dfs(string& word, int index, TrieNode* curr) {
        if (index == word.size()) return curr->isWord;
        
        if (word[index] == '.') {
            for (int i = 0; i < 26; i++) {
                if (curr->child[i] != nullptr && dfs(word, index + 1, curr->child[i])) {
                    return true;
                }
            }
            return false;
        } else {
            int charIdx = word[index] - 'a';
            if (curr->child[charIdx] == nullptr) return false;
            return dfs(word, index + 1, curr->child[charIdx]);
        }
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};