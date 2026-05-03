class Solution {
public:
    bool isAnagram(string s, string t) {
        map <char,int> mpp;
         map <char,int> mpp2;
        if(s.size()!= t.size()){
            return false;
        }
        for (int i=0; i<s.size(); i++){
                    mpp[s[i]]+=1;
                    mpp2[t[i]]+=1;
        }
        if(mpp==mpp2){
            return true;
        }
    return false;
    }
};
