class Solution {
    public String[] findRelativeRanks(int[] score) {
        
        int n = score.length;
        
        int maxScore = 0;
        for (int i = 0 ; i < n ; i++) {
            maxScore = Math.max(maxScore, score[i]);
        }
        
        int[]  score2Index = new int[maxScore+1];
        
        for (int i = 0 ; i < n ; i++) {
            score2Index[score[i]] = i+1;
        }
        
        String[] ans = new String[n];
        
        int place = 1;
        
        for (int i = maxScore ; i >= 0 ; i--) {
            
            if (score2Index[i] == 0) continue;
                
            int actualIndex = score2Index[i] - 1;
            if (place == 1) {
                ans[actualIndex] = "Gold Medal";
            } else if (place == 2) {
                ans[actualIndex] = "Silver Medal";
            } else if (place == 3) {
                ans[actualIndex] = "Bronze Medal";
            } else {
                ans[actualIndex] = String.valueOf(place);
            }
            place++; 
        }
        
        return ans;
    }
}


class Solution {
public:
    std::vector<std::string> findRelativeRanks(std::vector<int>& score) {
        int n = score.size();

        int M = 0;
        for (int x : score) {
            if (x > M) {
                M = x;
            }
        }
        std::vector<int> score_idx(M + 1, 0);
        for (int i = 0; i < n; i++) {
            score_idx[score[i]] = i + 1;
        }

        std::vector<std::string> medals = {"Gold Medal", "Silver Medal", "Bronze Medal"};

        std::vector<std::string> rank(n, "");
        int place = 1;
        for (int i = M; i >= 0; i--) {
            if (score_idx[i] != 0) {
                int org_idx = score_idx[i] - 1;
                if (place < 4) {
                    rank[org_idx] = medals[place - 1];
                } else {
                    rank[org_idx] = std::to_string(place);
                }
                place++;
            }
        }
        return rank;
    }
};
