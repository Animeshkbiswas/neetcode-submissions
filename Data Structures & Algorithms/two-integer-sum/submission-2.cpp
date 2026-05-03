class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> mpp;
        for(int i=0; i<nums.size();i++){
            
           int key= target-nums[i];
           
           auto it= mpp.find(nums[i]);
           if(it!=mpp.end()){
           int j= it->second;
           if(i!=j){
            ans.push_back(j);
            ans.push_back(i);
           }
           }
           
            mpp[key]=i;
           
        }
    return ans;
    }
};
