class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int k;
        int left=1;
        int right= *max_element(piles.begin(),piles.end());
    
        int m;
        while(left<=right){
            int mid= left+ (right-left)/2;
            long long count=0;
            for(auto pile:piles){
             count += (pile + mid - 1) / mid;
            }
            if(count>h){
                left=mid+1;
            }
            else if(count<=h){
                right=mid-1;
                m=mid;
            }
        }
    return m;
    }
};
