class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        int i=0;
        int ans;
        stack<int>stk;
        while(i<n){
            if(tokens[i]!="+"&& tokens[i]!="-"&& tokens[i]!="*"&&tokens[i]!="/"){
                stk.push(stoi(tokens[i]));
                i++;
            }
            else{
                if(tokens[i]=="+"){
                    int m=stk.top();
                    stk.pop();
                    int n= stk.top();
                    ans= m+n;
                     stk.pop();
                    stk.push(ans);
                }
                 else if(tokens[i]=="-"){
                    int m=stk.top();
                    stk.pop();
                    int n= stk.top();
                    ans= n-m;
                     stk.pop();
                    stk.push(ans);
                } 
                else if(tokens[i]=="*"){
                    int m=stk.top();
                    stk.pop();
                    int n= stk.top();
                    ans= m*n;
                     stk.pop();
                    stk.push(ans);
                } 
                else if(tokens[i]=="/"){
                    int m=stk.top();
                    stk.pop();
                    int n= stk.top();
                    ans= n/m;
                     stk.pop();
                    stk.push(ans);
                }
                 i++;
            }
        }
    return stk.top();
    }
};
