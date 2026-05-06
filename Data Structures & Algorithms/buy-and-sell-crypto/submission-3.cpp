class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int temp;
        int n= prices.size();
        int left=0;
        int right=1;
        while(right<n){
            if(prices[left]>prices[right]){
                left=right;

            }
            else{
                temp= prices[right]-prices[left];
                profit=max(profit,temp);
               
            }
            right++;
        }
    return profit;
    }
};
