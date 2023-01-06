class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<int, char> mp;
        
        int a = 0, b = 0;
        
        for(int i = 0;i<secret.size();i++)
            mp[i] = secret[i];
        
        for(int i = 0;i<guess.size();i++)
            if(secret[i] == guess[i])
                a++;
            else{
                for(int j = 0;j<secret.size();j++)
                    if(secret[j] != guess[j] and mp[j] == guess[i]){
                        b++;
                        mp[j] = '#';
                        break;
                    }
            }
        
        return to_string(a) + "A" + to_string(b) + "B";
    }
};