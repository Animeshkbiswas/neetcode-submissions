class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> subset;
        vector<vector<int>> res;
        sort(candidates.begin(),candidates.end());
        dfs(candidates, target,0,subset,res,0);
        return res;
    }
     void dfs(vector<int>&nums, int target,int i,vector<int>&subset,vector<vector<int>>&res,int total){
        if(total==target||i>=nums.size()){
           if(total==target){ 
            res.push_back(subset);
           }
            return;
        }
        if(total+ nums[i]>target){
            return;
        }
        int temp=nums[i];
        subset.push_back(temp);
        dfs(nums, target,i+1,subset,res,total+temp);
        subset.pop_back();
        while(i<nums.size()&& nums[i]==temp){
            i++;
        }
        dfs(nums, target,i,subset,res,total);
    }
};
