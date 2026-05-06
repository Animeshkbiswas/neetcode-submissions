class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        int ans=1;
        int n= s.size();
        int left=0;
        int right=1;
        int temp=1;
        unordered_set<int> mpp;
        while(right<n){
            mpp.insert(s[left]);
            if(mpp.find(s[right])==mpp.end()){
                temp++;
                ans=max(temp,ans);
                mpp.insert(s[right]);
            }
            else{
                left++;
                temp=1;
                mpp.clear();
                right=left;
            }
            right++;
        }
    return ans;
    }
};
