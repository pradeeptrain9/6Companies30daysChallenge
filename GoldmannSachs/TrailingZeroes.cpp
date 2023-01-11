class Solution {
public:
    int trailingZeroes(int n) {
        int t=5;
        int ans=0;
        while(t<=n)
        {
            ans+=(n/t);
            t=t*5;
        }
        return ans;
    }
};