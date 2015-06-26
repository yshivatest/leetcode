/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
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
    void levelOrderBottom_int(TreeNode *root, int level, vector<vector<int>>& t) {
        if(!root)
            return;

        if (t.size() < level + 1) {
            vector<int> x = {root->val};
            t.insert(t.begin(),x);
        } else {
            t[t.size() - 1 - level].push_back(root->val);
        }
        levelOrderBottom_int(root->left, level+1, t);
        levelOrderBottom_int(root->right, level+1, t);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> temp;
        levelOrderBottom_int(root, 0, temp);
        return temp;
    }
};
