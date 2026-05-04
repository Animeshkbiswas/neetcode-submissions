class Solution {
public:

    string encode(vector<string>& strs) {
        string en;
        for(auto it: strs){
            int i= it.size();
            en+=to_string(i);
            en+='#';
            en+=it;
        }
     return en;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i=0;
        string z={};
       while(i<s.size()){
        if(s[i]!='#'){
            z+= s[i];
            i++;
        }
        else{
            i++;
            int k;
            k= stoi(z);
            z={};
            for(int j=0; j<k; j++){
                z+=s[i+j];
            }
            i=i+k;
            ans.push_back(z);
            z={};

        }
       }
    
    return ans; 
    }
};
