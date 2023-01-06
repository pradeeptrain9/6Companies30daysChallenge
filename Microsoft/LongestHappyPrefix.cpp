class Solution {
public:
    string longestPrefix(string s) {
        //unordered_map<string,int>mp;
        vector<int>pos(s.size(),0);
        int i=0,j=1;
       while(j<s.size())
        {
            if(s[i]==s[j])
            {
                pos[j]=i+1;
                i++;
                j++;
            }
            else
            {
                if(i==0) j++;
                else i=pos[i-1];
            }
        }
        return s.substr(0,i);
    }
};