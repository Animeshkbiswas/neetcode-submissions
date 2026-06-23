class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> res;
        string sub;
        dfs(digits,res,0,sub);
        return res;
    }
    void dfs(string &digits, vector<string>&res,int i, string &sub){
        if(i==digits.size()) {
            res.push_back(sub);
            return;
        }
        string s;
        if(digits[i]=='2'){
                s="abc";
            }
        if(digits[i]=='3'){
                s="def";
            }
        if(digits[i]=='4'){
                s="ghi";
            }
         if(digits[i]=='5'){
                s="jkl";
            }
         if(digits[i]=='6'){
                s="mno";
            }
         if(digits[i]=='7'){
                s="pqrs";
            }
         if(digits[i]=='8'){
                s="tuv";
            }
         if(digits[i]=='9'){
                s="wxyz";
            }
        for(int j=0; j<s.size(); j++){
            sub+=s[j];
            dfs(digits,res,i+1,sub);
            sub.pop_back();
        }

    }
};
