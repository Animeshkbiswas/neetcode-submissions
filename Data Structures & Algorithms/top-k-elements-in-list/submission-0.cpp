class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mpp;
        priority_queue<pair<int,int>>pq;
        for(auto it:nums){
                mpp[it]++;
        }
        for(auto it:mpp){
                int val= it.first;
                int key= it.second;
                pq.push({key,val});

        }

        for(int i=0; i<k; i++){
            auto it= pq.top();
            pq.pop();
            ans.push_back(it.second);
           
        }
        return ans;
    }
    
};
