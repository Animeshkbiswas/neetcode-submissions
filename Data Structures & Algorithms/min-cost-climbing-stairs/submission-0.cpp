class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        int prev2= cost[0];
        int prev= cost[1];
        for(int i=2; i<n;i++){
            int curr= min(prev,prev2)+cost[i];
            prev2= prev;
            prev= curr;
        }
        return min(prev,prev2);

    }
};
