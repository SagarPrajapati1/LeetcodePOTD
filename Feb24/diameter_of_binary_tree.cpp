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
    int height(TreeNode* root, int &dia){
        if(root == nullptr) return 0;

        int left = height(root -> left, dia);
        int right = height(root -> right, dia);
        dia =  max(dia, left + right + 1         );
        return max(left, right) + 1;
    }

    pair<int, int> solve(TreeNode* root){
        if(root == nullptr) return {0,0};

        pair<int, int> left = solve(root -> left);
        pair<int, int> right = solve(root -> right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = (left.second + right.second) + 1;

        pair<int, int> ans;
        ans.first = max(op1, max(op2, op3));
        ans.second = max(left.second, right.second) + 1;
        return ans;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // if(root == nullptr) return 0;
        // int dia = 0;
        // height(root, dia);
        // return dia - 1;

        int ans = solve(root).first;
        return ans - 1;
    }
};
