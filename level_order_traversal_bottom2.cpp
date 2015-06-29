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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> t;
        if(!root)
            return t;

        queue<TreeNode*> a, *cur = &a;
        queue<TreeNode*> b, *next = &b;
        
        next->push(root);
        swap(cur, next);
        while(cur->size()) {
            vector<int> y;
            while(cur->size()) {
                auto x = cur->front(); cur->pop();
                if (x) {
                    y.push_back(x->val);
                    next->push(x->left);
                    next->push(x->right);
                }
            }
            if (y.size())
                t.push_back(y);
            swap(cur, next);
        }
        reverse(t.begin(), t.end());
        return t;
    }
};
