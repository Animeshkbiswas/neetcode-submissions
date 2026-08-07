class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dist(n, vector<int>(k + 2, 1e9));
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        int curr=0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> r;
        r.push_back(0);
        r.push_back(src);
        r.push_back(0);
        pq.push(r);
        dist[src][0] = 0;
        while(!pq.empty()){
            vector<int> z= pq.top();
            int weight= z[0];
            int node= z[1];
            int stops= z[2];
            pq.pop();
             if (stops == k+1) continue;
            for(int i=0;i<adj[node].size();i++){
                int next = adj[node][i].first;
                int wt   = adj[node][i].second;
                if(dist[next][stops+1]>weight+wt){
                    dist[next][stops+1]=weight+wt;
                    vector<int> k;
                    k.push_back(weight+wt);
                    k.push_back(next);
                    k.push_back(stops+1);
                    pq.push(k);
                }
            }
        }
    int ans = 1e9;

    for (int i = 0; i <= k + 1; i++) {
    ans = min(ans, dist[dst][i]);
    }
    if (ans == 1e9) return -1;
        return ans;
    }
};
