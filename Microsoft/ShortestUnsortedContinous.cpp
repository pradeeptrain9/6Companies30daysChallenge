class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int ans=0,n=nums.size();
        int st=-1,end=-1, con=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[i-1])
            {
                st=i-1;
                break;
            }
            
        }
        con=0;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]>nums[i+1])
            {
                end=i+1;
                break;
                
            }
            
        }
        if(st==end) return 0;
        ans=end-st+1;
        int mn=INT_MAX, mx=INT_MIN;
        for(int i=st;i<=end;i++)
        {
            mn=min(mn,nums[i]);
            mx=max(mx,nums[i]);
        }
        st--;
        while(st>=0 && mn<nums[st])
        {
            ans++;
            st--;
        }
        end++;
        while(end<n && mx>nums[end])
        {
            ans++;
            end++;
        }
        return ans;
    }
};