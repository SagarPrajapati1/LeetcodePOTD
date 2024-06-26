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
    void inorder(TreeNode* root, vector<TreeNode*> &in){
        if(!root)
        return ;

        inorder(root->left, in);
        in.push_back(root);
        inorder(root->right, in);
    }

    TreeNode* balancing(int start, int end, vector<TreeNode*> &in){
        if(start>end) return NULL;

        int mid = (start+end)/2;
        in[mid]->left = balancing(start, mid-1, in);
        in[mid]->right = balancing(mid+1, end, in);
        return in[mid];
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> in;
        inorder(root, in);
        return balancing(0,in.size()-1, in);
    }
};





class Solution {
public:
    vector<TreeNode*> sortedArr;
    TreeNode* balanceBST(TreeNode* root) {
        inorderTraverse(root);
        return sortedArrayToBST(0, sortedArr.size() - 1);
    }
    void inorderTraverse(TreeNode* root) {
        if (root == NULL) return;
        inorderTraverse(root->left);
        sortedArr.push_back(root);
        inorderTraverse(root->right);
    }
    TreeNode* sortedArrayToBST(int start, int end) {
        if (start > end) return NULL;
        int mid = (start + end) / 2;
        TreeNode* root = sortedArr[mid];
        root->left = sortedArrayToBST(start, mid - 1);
        root->right = sortedArrayToBST(mid + 1, end);
        return root;
    }
};
