class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int c = k;

        long long sum = 0;
        for(auto it : chalk){
            sum += it;
        }

        c = c % sum;
        

        for(int i = 0; i < chalk.size(); i++) {
            if(chalk[i] > c) return i;
            c = c-chalk[i];
        }
        return 0;

    }
};
