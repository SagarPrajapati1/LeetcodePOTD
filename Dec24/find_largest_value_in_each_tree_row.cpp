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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;

        if(!root) return {};

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int sz = q.size();

            int mx = INT_MIN;
            
            while(sz--){
                TreeNode* front = q.front();
                q.pop();
                
                mx = max(mx, front -> val);
                if(front -> left) q.push(front -> left);
                if(front -> right) q.push(front -> right);
            }
            ans.push_back(mx);
        }

        return ans;
    }
};
