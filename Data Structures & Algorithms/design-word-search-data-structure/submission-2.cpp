class TrieNode{
public:
    TrieNode*children[26];
    bool endofword;
    TrieNode()
    {
        for(int i = 0; i<26; i++)
        {
            children[i]=nullptr;
        }
        endofword = false;
    }
    
    

};

class WordDictionary {
    TrieNode*root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode * curr = root;
        for(char c:word)
        {
            int i = c - 'a';
            if(curr->children[i]==nullptr)
                curr->children[i] = new TrieNode();
            curr = curr->children[i]; 
        }
        curr->endofword = true;
    }
    
    bool helper(TrieNode*root,string word)
    {
        TrieNode*curr = root;
        for(int i = 0; i < word.size(); i++)
        {
            char ch = word[i];
            if(ch == '.')
            {
                for(int j = 0; j < 26; j++)
                {
                    if(curr->children[j]!=nullptr)
                    {
                        if(helper(curr->children[j],word.substr((i+1))))
                        {
                            return true;
                        }

                    }
                }
                return false;
            }
            else if(curr->children[ch-'a']==nullptr)
            {
                return false;
            }
            curr = curr->children[ch-'a'];
        }
        return (curr!=nullptr && curr->endofword);
    }

    bool search(string word) {
        if(word.empty())
            return root->endofword;
        return helper(root,word);
    }
};
