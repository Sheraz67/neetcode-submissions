class TrieNode{
public:
    TrieNode* children[26];
    bool endofword;
    TrieNode() {
        for(int i = 0; i < 26;i++)
        {
            children[i] = nullptr;
        }
        endofword = false;
    }

};

class PrefixTree {
    TrieNode*root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(char c:word)
        {
            int i = c-'a';
            if(curr->children[i]==nullptr)
                curr->children[i] = new TrieNode();
            curr= curr->children[i];
        }
        curr->endofword = true;
    }
    
    bool search(string word) {
        TrieNode *curr = root;
        for(char c:word)
        {
            int i = c-'a';
            if(curr->children[i]==nullptr)
                return false;
            curr = curr->children[i];
        }
        return curr->endofword;
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        for(char c:prefix)
        {
            int i = c - 'a';
            if(curr->children[i]==nullptr)
                return false;
            curr = curr->children[i];
        }
        return true;
    }
};
