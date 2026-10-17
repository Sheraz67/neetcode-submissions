/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    TreeNode* helper(unordered_map<int,int>&inordermap,vector<int>& preorder,int &preindex,int left,int right)
    {
        if(left>right)
        {
            return NULL;
        }
        TreeNode*root = new TreeNode(preorder[preindex]);
        preindex++;
        int mid = inordermap[root->val];
        root->left = helper(inordermap,preorder,preindex,left,mid-1);
        root->right = helper(inordermap,preorder,preindex,mid+1,right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>inordermap;
        for(int i = 0; i < inorder.size();i++)
        {
            inordermap[inorder[i]] = i;
        }
        int preIndex = 0;
        return helper(inordermap,preorder,preIndex,0,inorder.size()-1);
    }
};
