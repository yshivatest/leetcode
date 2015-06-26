/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void inorderTraversal(TreeNode *root, vector<int>& temp, int level) {
        if (!root)
            return;
            
        if (temp.size() < level + 1) {
            temp.push_back(root->val);
        } else {
            temp[level] = root->val;
        }
        inorderTraversal(root->left, temp, level+1);
        inorderTraversal(root->right, temp, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> temp;
        inorderTraversal(root, temp, 0);
        return temp;
    }
};
