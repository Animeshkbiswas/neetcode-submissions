class Solution {
public:
         
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
         dfs(nums,0,subset,res);
         return res;
          
    }
    void dfs(vector<int>& nums,int i,vector<int>subset,vector<vector<int>>& res){
        if (i>=nums.size()) {
            res.push_back(subset);
            return;
        }
        int temp=nums[i];
        subset.push_back(temp);
        dfs(nums,i+1,subset,res);
        subset.pop_back();
        dfs(nums,i+1,subset,res);
    }
};
