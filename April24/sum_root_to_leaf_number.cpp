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
    int res = 0;
    int solve(TreeNode* root, int ans){
        if(root == nullptr){
            return 0;
        }
        ans = ans*10 + root -> val;
        
        if(!root -> left && !root -> right) return ans;
        
        return solve(root -> left, ans) + solve(root -> right, ans);
        
    }
    int sumNumbers(TreeNode* root) {
        
        int ans = 0;
        return solve(root, ans);
        
    }
};
