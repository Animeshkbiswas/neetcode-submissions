class Solution {
public:
    int trap(vector<int>& height) {
        int leftval=height[0];
        int left=0;
        int rightval=height[height.size()-1];
        int right=height.size()-1;
        int ans=0;
     
     while(left<right){
       if(leftval <= rightval){
        left++;
        if(min(leftval,rightval)-height[left]>0){
            ans+=min(leftval,rightval)-height[left];
        }
        leftval=max(leftval,height[left]);
       }
     else if(leftval> rightval){
        right--;
        if(min(leftval,rightval)-height[right]>0){
            ans+=min(leftval,rightval)-height[right];
        }

        rightval=max(rightval,height[right]);
       }
     }  
     
     return ans; 
    }
};
