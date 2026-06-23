class Solution {
public:
    vector<vector<string>> partition(string s) {
      vector<vector<string>>res;
      vector<string> sub;
      dfs(s,res,0,sub);
      return res;
    }
    void dfs(string &s,vector<vector<string>>&res,int i,vector<string> &sub){
        if(i==s.size()){
            res.push_back(sub);
            return;
        }
        for(int j=i;j<s.size();j++){
            string curr = s.substr(i,j-i+1);
            if(check(curr)){
                sub.push_back(curr);
                dfs(s,res,j+1,sub);
                sub.pop_back();
            }
        }
        
    }
    bool check(string &s){
        int first=0;
        int last=s.size()-1;
        while(first<=last){
        if(s[first]!=s[last]) return false;
        first++;
        last--;
        }
        return true;
    }
};
