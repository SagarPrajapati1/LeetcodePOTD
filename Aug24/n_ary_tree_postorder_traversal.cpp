/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void solve(Node* root, vector<int> &ans) {
        if(root == nullptr) return;
        stack<Node*> st;
        st.push(root);
        while(!st.empty()) {
            Node* top = st.top();
            st.pop();

            for(int i = 0; i < top->children.size(); i++){
                st.push(top->children[i]);
            }
            ans.push_back(top -> val);
        }
        reverse(ans.begin(), ans.end());
    }
    vector<int> postorder(Node* root) {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};
