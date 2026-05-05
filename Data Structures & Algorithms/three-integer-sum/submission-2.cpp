class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size(); i++){
            if(i>0&& nums[i]==nums[i-1]) continue;
            vector<int>a;
            int k=nums[i];
            int left=i+1;
            int right=nums.size()-1;
           while(left<right){
            if(nums[left]+nums[right]>(-k)){
                right--;
                continue;
            }
             if(nums[left]+nums[right]<(-k)){
                left++;
                continue;
            } if(nums[left]+nums[right]==(-k)){
                a.push_back(nums[left]);
                a.push_back(nums[right]);
                a.push_back(nums[i]);
                ans.push_back(a);
                a.clear();
            }
            left++;
            right--;
            while(left < right && nums[left] == nums[left-1]) left++;
            while(left < right && nums[right] == nums[right+1]) right--;
           }
        }
    return ans;
    }
};
