class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
            int i=1;
            int it1;
            int a=0;
            vector<int> ans;
            for (auto it: nums){
                if(it==0&&a==0){
                    it1=i;
                    a++;
                }
                else if(it==0&&a==1){
                        it1=0;
                }
                else if(it!=0){
                    it1= it1*it;
                }
                i= i*it;
                
            }
            for(int j=0; j<nums.size(); j++){
                int k=nums[j];
                if(k==0){
                    ans.push_back(it1);
                }
                else{
                    ans.push_back((i/k));
                }

            }
    return ans;
    }
};
