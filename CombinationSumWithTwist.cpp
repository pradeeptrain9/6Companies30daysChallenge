class Solution {
public:
    set<vector<int>>ans;
    
    void rec(int cur, int i, int n, vector<int>temp,int k)
    {
        if(temp.size()==k)
        {
            if(cur==0) ans.insert(temp);
            return;
        }
        if(i<1) return;
        cur-=i;
        temp.push_back(i);
        rec(cur,i-1,n,temp,k);
        cur+=i;
        temp.pop_back();
        //cout<<cur<<" ";
        rec(cur,i-1,n,temp,k);
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>t;
        rec(n,9,n,t,k);
        vector<vector<int>>res;
        for(auto i :ans)res.push_back(i);
        return res;
    }
};