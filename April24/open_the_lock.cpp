class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        unordered_set<string> deadendSet(deadends.begin(), deadends.end());
        if (deadendSet.count("0000")) {
            return -1;
        }
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        unordered_set<string> vis;
        vis.insert("0000");

        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            string currentCombination = curr.first;
            int moves = curr.second;
            if(currentCombination == target) return moves;
                    
        
            for (int i = 0; i < 4; i++) {
                for (int delta : {-1, 1}) {
                    int newDigit = (currentCombination[i] - '0' + delta + 10) % 10;
                    string newCombination = currentCombination;
                    newCombination[i] = '0' + newDigit;
                    
                    if (vis.find(newCombination) == vis.end() 
                    && deadendSet.find(newCombination) == deadendSet.end()) {
                        vis.insert(newCombination);
                        q.push({newCombination, moves + 1});
                    }
                }
            }
        }
        return -1;
    }
};
