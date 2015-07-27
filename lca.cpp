#include<iostream>
#include<vector>
using namespace std;
 
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    void traverse(TreeNode* root, TreeNode* p, TreeNode* q, vector<TreeNode*>& pvector, vector<TreeNode*>& qvector, vector<TreeNode*>& cur) {
        if (root) {
            cout<<root<<p<<q<<endl;
            cur.push_back(root);
            if (root == p) {
                pvector = cur;
                cout<<cur.size()<<endl;
            } else if (root == q) {
                qvector = cur;
                cout<<cur.size()<<endl;
            }
            
            traverse(root->left, p,q,pvector,qvector,cur);
            traverse(root->right,p,q,pvector,qvector,cur);
            cur.pop_back();
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pvector, qvector, cur;
        traverse(root, p, q, pvector, qvector, cur);
        int i;
        TreeNode *ret = NULL;
        //cout<<pvector.size()<<qvector.size()<<endl;
        for(i =0; i < pvector.size() && i <qvector.size(); i++) {
            
            if (pvector[i] != qvector[i])
                return ret;
                
            ret = pvector[i];
        }
        return ret;
    }
};

int main() {
	TreeNode x(1);
	TreeNode y(2);
	y.left = &x;
	Solution s;
	cout<<s.lowestCommonAncestor(&y, &x, &y)<<endl;
}
