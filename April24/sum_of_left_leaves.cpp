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
int sum = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr) return sum;
        
        if(root -> left){
            if(!root -> left -> left && !root -> left -> right){
                sum += root -> left -> val;
            }
        }

        if(root -> left) sumOfLeftLeaves(root -> left);
        if(root -> right) sumOfLeftLeaves(root -> right);
        return sum;
    }
};
