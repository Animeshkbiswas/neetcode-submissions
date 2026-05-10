class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0; 
        int right=nums.size()-1;
        while(left<=right){
           
            int k= ceil(left+((right -left)/2));
            if(nums[k]==target){
                return k;
            }
            else if(nums[k]>target){
                right=k-1;
            }
            else if(nums[k]<target){
                left=k+1;
            }
        }
    return -1;
    }
};
