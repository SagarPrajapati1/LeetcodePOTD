class Solution {
public:
    int trap(std::vector<int>& height) {
        int i = 0, left_max = height[0], sum = 0;
        int j = height.size() - 1, right_max = height[j];
        while (i < j) {
            if (left_max <= right_max) {
                sum += (left_max - height[i]);
                i++;
                left_max = std::max(left_max, height[i]);
            } else {
                sum += (right_max - height[j]);
                j--;
                right_max = std::max(right_max, height[j]);
            }
        }
        return sum;
    }
};


// 2nd solution
#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    static int trap(vector<int>& height) {
        const unsigned n = height.size();
        int ans=0;
        vector<unsigned> st;
        for(int r=0; r<n; r++){
            while(!st.empty() && height[st.back()]<height[r]){
                int m=st.back();
                st.pop_back();
                if (st.empty()) break;
                int l=st.back();
                int h= min(height[r]-height[m], height[l]-height[m]);
                int w= r-l-1;
                ans+=h*w;
            }
            st.push_back(r);
        }
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
