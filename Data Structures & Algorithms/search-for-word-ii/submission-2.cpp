#include <vector>
#include <string>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool endofword;
    string word;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        endofword = false;
        word = "";
    }
};

class Solution {
public:
    vector<string> result;
    vector<vector<int>> direction = {
        {0, 1},
        {1, 0},
        {-1, 0},
        {0, -1}
    };

    void insert(string& word, TrieNode* root) {
        TrieNode* curr = root;

        for (char c : word) {
            int idx = c - 'a';

            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
            }

            curr = curr->children[idx];
        }

        curr->endofword = true;
        curr->word = word;
    }

    void dfs(vector<vector<char>>& board, int i, int j,
             TrieNode* node, int m, int n) {

        if (i < 0 || i >= m || j < 0 || j >= n ||
            board[i][j] == '#') {
            return;
        }

        int idx = board[i][j] - 'a';

        if (node->children[idx] == nullptr) {
            return;
        }

        TrieNode* curr = node->children[idx];

        if (curr->endofword) {
            result.push_back(curr->word);
            curr->endofword = false;
        }

        char temp = board[i][j];
        board[i][j] = '#';

        for (auto& dir : direction) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            dfs(board, new_i, new_j, curr, m, n);
        }

        board[i][j] = temp;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        result.clear();

        if (board.empty() || board[0].empty()) {
            return result;
        }

        TrieNode* root = new TrieNode();

        for (string& word : words) {
            insert(word, root);
        }

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root, m, n);
            }
        }

        return result;
    }
};