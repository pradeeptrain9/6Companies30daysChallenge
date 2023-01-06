class Solution {
public:
    bool dfs(int i,vector<int>&vis, vector<int>&dfsVis, vector<int>adj[])
    {
        vis[i]=1;
        dfsVis[i]=1;
        for(auto j : adj[i])
        {
            if(!vis[j]) 
            {
                if(dfs(j,vis,dfsVis,adj)) return true;
            }
            else if(dfsVis[j]) return true;
        }
        dfsVis[i]=0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int>adj [n];
        for(auto req:prerequisites)
        {
            adj[req[0]].push_back(req[1]);
        }
        vector<int>vis(n,0),dfsVis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,vis,dfsVis,adj)) return false;
            }
        }
        return true;
    }
};