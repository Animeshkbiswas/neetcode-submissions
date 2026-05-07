class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.size()==0) return 0;
        int n=s.size();
        int maxcount=0;
        int left=0;
        int ans=0;
        vector<int> count(26,0);
        for(int i=0; i<n; i++){
            count[s[i]-'A']++;
            maxcount= max(maxcount, count[s[i]-'A']);
            while(i-left+1- maxcount>k){
                count[s[left]-'A']--;
                left++;
            }
            ans=max(ans,i-left+1);
        }
    return ans;
    }
};
