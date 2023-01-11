class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>cnt,endwith;
        for(int i: nums) cnt[i]++;
        
        for(int i : nums)
        {
            if(!cnt[i]) continue;
            cnt[i]--;
            if(endwith[i-1]>0)
            {
                endwith[i-1]--;
                endwith[i]++;
            }
            else if(cnt[i+1] && cnt[i+2])
            {
                cnt[i+1]--;
                cnt[i+2]--;
                endwith[i+2]++;
            }
            else return false;
        }
        
        return true;
    }
     
};