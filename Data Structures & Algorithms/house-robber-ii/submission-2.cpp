class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);
        vector<int> nums1;
        vector<int> nums2;
        
        for(int i = 0; i <n; i++) {
            if(i != n-1) {
                nums1.push_back(nums[i]);
         }

            if(i != 0) {
                nums2.push_back(nums[i]);
            }
        }
        int prev2= nums1[0];
        int prev= max(nums1[0],nums1[1]);
        for(int i=2;i<n-1;i++){
           int curr= max(prev,prev2+nums1[i]);
           prev2= prev;
           prev= curr;
        }
        int m= prev;
        prev2= nums2[0];
        prev= max(nums2[0],nums2[1]);
        for(int i=2;i<n-1;i++){
           int curr= max(prev,prev2+nums2[i]);
           prev2= prev;
           prev= curr;
        }
        m= max(m,prev);
        return m; 
    }
};
