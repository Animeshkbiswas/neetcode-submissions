class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> mpp;
        for(auto it:nums){
         auto it2 = mpp.find(it);
            if (it2!= mpp.end()){
                return true;
            }
            mpp.insert(it);
        }
    return false;
    }
};