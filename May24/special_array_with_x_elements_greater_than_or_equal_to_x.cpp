class Solution {
public:
    int specialArray(vector<int>& nums) {
       
       sort(nums.begin(), nums.end());
       int n = nums.size();

        for(int i = 0; i < nums.size(); i++){
            
            if(n-i <= nums[i] && (i == 0 || n-i > nums[i-1])) return n-i;
    
        }

        return -1;
    }
};


class Solution {
public:
    int specialArray(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        int low=0;
        int high=1000;

        while(low<=high)
        {
            int md=(low + high)/2;
            int ct=0;
            for(int i=0;i<nums.size();i++)
            {
                    if(nums[i]>=md)
                    {
                        ct++;
                    }
            }

                if(ct==md)
                {
                    return md;
                }
                else if(ct<md)
                {
                    high=md-1;
                }
                else
                {
                    low=md+1;
                }
        }
        return -1;
    }
};
