class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> pick(nums.size(),false);
        vector<vector<int>> res;
        vector<int>subset;
        dfs(nums,pick,subset,res);
        return res;
    }
    void dfs(vector<int> &nums,vector<bool>pick,vector<int>&subset,vector<vector<int>>&res){
        if(subset.size()==nums.size()){
            res.push_back(subset);
            return;
        }
        for(int i=0; i<nums.size();i++){
            if(!pick[i]){
                pick[i]=true;
                subset.push_back(nums[i]);
                dfs(nums,pick,subset,res);
                subset.pop_back();
                pick[i]=false;
            }
        }

    }
};
