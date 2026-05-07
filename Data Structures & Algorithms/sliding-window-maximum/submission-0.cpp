class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left=0;
        int m=nums[0];
        vector<int> ans;
        for(int i=1; i<k; i++){
            m= max(m,nums[i]);
        }
        ans.push_back(m);
        for(int right=k; right<nums.size();right++){
            if(nums[right]>m){
                m=nums[right];
                ans.push_back(m);
                left++;
                
            }
            else{
                if(m!=nums[left]){
                    ans.push_back(m);
                    left++;
                
                }
                else{
                    m=nums[left+1];
                    for(int i=left+1; i<left+1+k; i++){
                        m=max(m,nums[i]);
                    }
                    ans.push_back(m);
                    left++;
                }
            }
        }
    return ans;
    }
};
