class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        int ans=1;
        int n= s.size();
        int left=0;
        int right=0;
        unordered_set<int> mpp;
        while(right<n){
            
                while(mpp.find(s[right])!=mpp.end()){
                    mpp.erase(s[left]);
                    left++;
                }
             mpp.insert(s[right]);
            ans = max(ans, right - left + 1);
            right++;
        }
    return ans;
    }
};
