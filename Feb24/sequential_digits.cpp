class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;

        for(int i = 1; i <= 9; i++) {
            q.push(i);
        }


        vector<int> ans;

        while(!q.empty()) {
            int front = q.front();
            q.pop();

            if(front >= low && front <= high) ans.push_back(front);

            if(front > high) break;

            if(front % 10 < 9) q.push(front * 10 + (front % 10 + 1));
        }
        return ans;
    }
};
