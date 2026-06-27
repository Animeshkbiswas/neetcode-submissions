class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            swap(nums1,nums2);
        }
        int left=0;
        int right=nums1.size();
        int s=(nums2.size()+nums1.size()+1)/2;
        while(left<=right){
            int mid= left+ (right-left)/2;
            int z=s-mid;
           int l1 = (mid == 0) ? INT_MIN : nums1[mid-1];
            int r1 = (mid == nums1.size()) ? INT_MAX : nums1[mid];

            int l2 = (z == 0) ? INT_MIN : nums2[z-1];
            int r2 = (z == nums2.size()) ? INT_MAX : nums2[z];
            if(l1 <= r2 && l2 <= r1){
                if((nums2.size()+nums1.size())%2!=0){
                    return max(l1,l2);
                }
                else{
                    return (min(r1,r2)+max(l1,l2))/2.0;
                }
            }
            else if(l1 > r2){
                right=mid-1;
            }
            else if(l2 > r1){
                left=mid+1;
            }
        }
        return -1;
    }
};
