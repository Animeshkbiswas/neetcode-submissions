class Solution {
public:
    priority_queue<pair<long long,int>> pq;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for(int i=0; i<points.size();i++){
            int x=points[i][0];
            int y= points[i][1];
            long long dis= x*x+y*y;
            pq.push({dis,i});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>>ans;
        for(int i=0; i<k;i++){
            pair<long long,int> temp=pq.top();
            pq.pop();
            vector<int> t= points[temp.second];
            ans.push_back(t);
        }
        return ans;
    }
};
