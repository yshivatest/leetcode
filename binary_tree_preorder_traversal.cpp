/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> temp;
        vector<int> ret;
        temp.push(root);
        while(temp.size()) {
            TreeNode* x = temp.top();temp.pop();
            if (x) {
                ret.push_back(x->val);
                temp.push(x->right);
                temp.push(x->left);
            }
        }
        return ret;
    }
};
