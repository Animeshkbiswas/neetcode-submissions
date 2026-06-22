class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string subset="";
        int open=0;
        int close=0;
        dfs(subset,n,res,open,close);
        return res;

    }
    void dfs(string &subset,int n,vector<string> &res,int open,int close){
        if(open==n&& close==n){
            res.push_back(subset);
            return;
        }
        if(open<n){
            subset+='(';
            dfs(subset,n,res,open+1,close);
            subset.pop_back();
        }
        if(close<open){
            subset+=')';
            dfs(subset,n,res,open,close+1);
           subset.pop_back();

        }
    

    }
};
