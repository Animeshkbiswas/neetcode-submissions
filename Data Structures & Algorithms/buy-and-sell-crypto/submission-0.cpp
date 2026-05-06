class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int temp;
        int n= prices.size();
        for(int i=0; i<n; i++){
            for(int j=i+1;j<n; j++){
                temp= prices[j]-prices[i];
                profit=max(temp,profit);
            }
        }
    return profit;
    }
};
