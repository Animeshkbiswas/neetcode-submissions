class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mpp;
        int n=nums.size();
        vector<vector<int>> p(n+1);
        for(auto it:nums){
                mpp[it]++;
        }
        for(auto it:mpp){
                int key= it.first;
                int val= it.second;
                p[val].push_back(key);

        }

        for(int i=n; i>=1 && k>=1; i--){
            for(auto it:p[i]){
            ans.push_back(it);
            k--;
            if(k==0){
                break;
            }
            }
        }
        return ans;
    }
    
};
