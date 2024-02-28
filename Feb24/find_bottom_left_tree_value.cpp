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
    int findBottomLeftValue(TreeNode* root) {

      // using bfs
        queue<TreeNode*> q;

        if(root == nullptr) return -1;

        // q.push(root);
        // int ans = -1;
        // TreeNode* front;
        // while(!q.empty()){
        //     front = q.front();
        //     q.pop();
        //     // if(front -> left == NULL && front -> right == NULL) ans = front -> val;

        //     if(front -> right) q.push(front -> right);
        //     if(front -> left) q.push(front -> left);
        // }
        // return front -> val;


        // q.push(root);
        // while(!q.empty()) {
        //     root = q.front();
        //     q.pop();
        //     if(root -> right) q.push(root -> right);
        //     if(root -> left) q.push(root -> left);
        // }
        // return root -> val;

        int ans = -1;
        q.push(root);
        
        while(!q.empty()){

            // it will tell when level is changed
            int cnt = q.size();

            for(int i = 0; i < cnt; i++){
                TreeNode* front = q.front();
                q.pop();

                if(i == 0) ans = front -> val;

                if(front -> left) q.push(front -> left);
                if(front -> right) q.push(front -> right);
            }
        }
        return ans;

    }
};
