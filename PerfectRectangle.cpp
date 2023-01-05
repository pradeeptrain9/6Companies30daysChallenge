class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int>countpairs;
        for(auto rect: rectangles)
        {
            countpairs[{rect[0],rect[1]}]++;
            countpairs[{rect[2],rect[3]}]++;
            countpairs[{rect[0],rect[3]}]--;
            countpairs[{rect[2],rect[1]}]--;
        }
        int corners=0;
        for(auto i=countpairs.begin();i!=countpairs.end();i++)
        {
            if(i->second!=0)
            {
                if(abs(i->second) != 1) return false;
                corners++;
            }
        }
        //cout<<corners<<" ";
        return corners==4;
    }
};