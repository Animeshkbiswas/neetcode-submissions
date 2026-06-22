class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> subset;
        vector<vector<int>> res;
        dfs(nums, target,0,subset,res);
        return res;

    }
    void dfs(vector<int>&nums, int target,int i,vector<int>subset,vector<vector<int>>&res){
        int r= findsum(subset);
        if(r==target||i>=nums.size()){
           if(r==target){ 
            res.push_back(subset);
           }
            return;
        }
        if(r>=target){
            return;
        }
        int temp=nums[i];
        subset.push_back(temp);
        dfs(nums, target,i,subset,res);
        subset.pop_back();
        dfs(nums, target,i+1,subset,res);
    }




    int findsum(vector<int>&nums){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        return sum;
    }
};
