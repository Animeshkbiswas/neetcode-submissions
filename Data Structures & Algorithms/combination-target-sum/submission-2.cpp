class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> subset;
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        dfs(nums, target,0,subset,res,0);
        return res;

    }
    void dfs(vector<int>&nums, int target,int i,vector<int>subset,vector<vector<int>>&res,int total){
        if(total==target||i>=nums.size()){
           if(total==target){ 
            res.push_back(subset);
           }
            return;
        }
        if(total>=target){
            return;
        }
        int temp=nums[i];
        subset.push_back(temp);
        dfs(nums, target,i,subset,res,total+temp);
        subset.pop_back();
        dfs(nums, target,i+1,subset,res,total);
    }




    int findsum(vector<int>&nums){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        return sum;
    }
};
