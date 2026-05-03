class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    unordered_map<string,vector<string>> mpp;

    for (auto it: strs){
        int count[26]={0};
        for( auto ch: it){
           count[ch-'a']++;
        }
    string key;
    for(int i=0; i<26; i++){
        key+=to_string(count[i]);
        key+='#';
    }

    mpp[key].push_back(it);
       
    }
    for(auto it : mpp){
    ans.push_back(it.second);
    }
    return ans;
    }

};
