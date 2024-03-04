class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());

        // if(tokens.size() == 1 && tokens[0] < power) return 0;

        int i = 0;
        int j = tokens.size() - 1;

        int score = 0;
        int max_score = 0;

        while(i <= j) {
            if(power >= tokens[i])
            {
                power -= tokens[i++];
                score++;
                max_score = max(max_score, score);
            }
            else if(score > 0 ) 
            {
                power += tokens[j--]; 
                score--;
            }
            else break;
        }
        return max_score;
    }
};
