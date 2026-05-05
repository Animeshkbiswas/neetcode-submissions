class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left=0;
        int right= heights.size()-1;
        int ans=0;
        while(left<right){
            int k=min(heights[left],heights[right])*(right-left);
            ans= max(ans,k);
            if(heights[left]>heights[right]){
                right--;
                continue;
            }
            else{
                left++;
                continue;
            }
        }
        return ans;
    }

};
