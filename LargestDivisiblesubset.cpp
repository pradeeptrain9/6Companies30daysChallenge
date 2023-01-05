class Solution {
public:
     unordered_map<int, vector<int>> dp;
     vector<int> LDS(vector<int>& nums, int start) {
        if(start >= nums.size()) return {};
        if(dp.count(start)) return dp[start];
        for(int next = start+1; next < nums.size(); next++) {
            if(nums[next] % nums[start]) continue;
            auto res = LDS(nums, next);
            if(res.size() >= dp[start].size()) dp[start] = res;
        }
        dp[start].push_back(nums[start]);
        return dp[start];
        
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            auto res = LDS(nums, i);
            if(res.size() > ans.size()) ans = res;
        }
        return ans;
    }
   

};