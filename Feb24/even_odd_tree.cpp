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

    bool isEvenOddTree(TreeNode* root) {
        // if(root -> left == NULL && root -> right == NULL) return true;

        queue<TreeNode*> q;

        q.push(root);
        
        int prev = 0;
        bool lvl = 1;

        while(!q.empty()) {

            int size = q.size();

            prev = lvl ? INT_MIN : INT_MAX;
            

            for(int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();

                if(lvl) {
                    if(front -> val % 2 == 0 || front -> val <= prev) return false;
                }
                else {
                    if(front -> val % 2 != 0 || front -> val >= prev) return false;
                }


                if(front -> left) q.push(front -> left);
           

                if(front -> right) q.push(front -> right);
                prev = front -> val;

            }      
 
            lvl = !lvl;

        }
        return true;
    }

};
