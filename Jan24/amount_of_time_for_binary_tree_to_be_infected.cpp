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
// adjacency list for tree
    unordered_map<int, vector<int>> adj;

    void adjList(TreeNode* root){
        
        // base case
        if(!root) return;

        
        if(root -> left) {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            
        }
        if(root -> right) {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            
            
        }
        adjList(root-> left);
        adjList(root -> right);
    }

    int amountOfTime(TreeNode* root, int start) {

        adjList(root);


        queue<int> q;
        q.push(start);

      // set to store the visited nodes
        unordered_set<int> vis;

        int min = -1;

        while(!q.empty()){
            ++min;
        
            for(int lvl = q.size(); lvl > 0; --lvl){
              // take out the front node
                int node = q.front();
                q.pop();

                vis.insert(node);

                for(int it : adj[node]){
                  // if not visited the make it visited
                    if(!vis.count(it)){
                        q.push(it);
                    }
                }
            }
        }
        return min;
    }
};
