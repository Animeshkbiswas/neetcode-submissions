class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int sum=0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> vis(points.size(),0);
        for(int i=0;i<points.size();i++){
            vis[i]=0;
        }
        int n=0;
        vector<int> v;
        v.push_back(0);
        v.push_back(0);
        pq.push(v);
        while(!pq.empty()&& n!=points.size()){
            vector<int> z=pq.top();
            pq.pop();
            if(vis[z[1]]==1) continue;
            sum+=z[0];
            vis[z[1]] = 1;
            n++;
            for(int i=0;i<points.size();i++){
                if(vis[i]==1) continue;
                int wt= abs(points[z[1]][0]-points[i][0])+ abs(points[z[1]][1]-points[i][1]);
                vector<int>z1;
                z1.push_back(wt);
                z1.push_back(i);
                pq.push(z1);
            }
        }
        return sum;
    }
};
