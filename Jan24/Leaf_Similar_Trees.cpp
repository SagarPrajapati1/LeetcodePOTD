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
    void solve(TreeNode* root, vector<int> & ans){
        if(root -> left == nullptr && root -> right == nullptr) {
            ans.push_back(root->val);
            cout << root -> val<< "  ";
            return;
        }

        if(root -> left) solve(root -> left, ans);
        if(root -> right) solve(root -> right, ans);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> t1;
         solve(root1, t1);
        vector<int> t2;
        solve(root2, t2);

        // if(t1.size() != t2.size()) return false;

        // for(int i = 0; i < t1.size(); i++){
        //     if(t1[i] != t2[i]) return false;
        // }
        // return true;

        return t1 == t2;
    }
};
