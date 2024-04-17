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
    void solve(TreeNode* root, string &res, string path){
        if(root == nullptr) return;

        path += char('a' + root -> val);
        
        // if it is leaf
        if(!root -> left && !root -> right){
            reverse(path.begin(), path.end());
            if(res.empty() || res > path) res = path;
            reverse(path.begin(), path.end());
        }

        solve(root -> left, res, path);
        solve(root -> right, res, path);


    }

    string smallestFromLeaf(TreeNode* root) {
        
        string res;
        solve(root, res, "");
        return res;
    }
};
