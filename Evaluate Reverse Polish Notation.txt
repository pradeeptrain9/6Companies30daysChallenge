class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long>s;
        for(auto x:tokens)
        {
            
            if( x.size()==1 && (x[0]=='+' || x[0]=='-' || x[0]=='/' || x[0]=='*'))
            {
                long first = s.top();
                s.pop();
                long second = s.top();
                s.pop();
                if(x[0]=='+') s.push(first+second);
                else if(x[0]=='-') s.push(second-first);
                else if(x[0]=='*') s.push(second*first);
                else s.push(second/first);
            }
            else 
            {
                s.push(stoi(x));
            } 
               //cout<<"x";  
           }
        return s.top();
    }
};