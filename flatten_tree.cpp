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

    TreeNode* flatten_int(TreeNode *root) {
        if(!root)
            return root;
        TreeNode *tail1 = flatten_int(root->left);
        TreeNode *tail2 = flatten_int(root->right);
        TreeNode *temp = root->right;
        if (tail1) {
            root->right = root->left;
            tail1->right = temp;
            root->left = NULL;
        } 
        if (tail2)
            return tail2;
        if (tail1)
            return tail1;
        return root;
        
    }
    void flatten(TreeNode* root) {
        flatten_int(root);
    }
};
