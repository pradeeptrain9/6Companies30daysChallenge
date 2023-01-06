class Solution {
public:
    int numberOfSubstrings(string s) {
       vector<int>count(3,0);
       int st=0,ans=0;
       for(int i=0;i<s.size();i++)
       {
           count[s[i]-'a']++;
           while(count[0] && count[1] && count[2])
           {
               ans+=(s.size()-i);
               count[s[st]-'a']--;
               st++;
           }
       }
       
       return ans;
    }
};