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
    const int SHIFT = 20;
    const int MASK = 0xFFFFF;

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 0;

        while(!q.empty()) {

            int sz = q.size();
            vector<long long> vec(sz);

            int lvl = sz;
            int k = 0;
            while(k < sz){
                TreeNode* temp = q.front();
                q.pop();

                vec[k] = (static_cast<long long>(temp->val) << SHIFT) + k;

                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
                k++;
            }

            sort(vec.begin(), vec.end());
            for(int i = 0; i < lvl; i++) {
                int org = static_cast<int>(vec[i] & MASK);
                if(org != i) {
                    swap(vec[i], vec[org]);
                    cnt++;
                    i--;
                }
            }

        }
        return cnt;
    }
};
