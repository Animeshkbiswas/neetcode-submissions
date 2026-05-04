class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int count=1;
        unordered_set<int> s;
        if(nums.empty()) return 0;
        for(auto it: nums){
            s.insert(it);
        }
        
        for(auto num:s){
            if(s.find(num-1)== s.end()){
                int curr=num;
                int len=1;
                while(s.find(curr+1)!= s.end()){
                    len++;
                    curr++;
                }
                count = max(count, len);
            }
        }
        return count;
    }
};
