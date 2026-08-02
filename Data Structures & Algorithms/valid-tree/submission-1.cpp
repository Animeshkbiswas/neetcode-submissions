class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!= n-1) return false;
        vector<vector<int>> adj(n);
        vector<int> vis(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                q.push({i,-1});
                vis[i]=1;
                while(!q.empty()){
                    pair p= q.front();
                    q.pop();
                    for(int j=0;j<adj[p.first].size();j++){
                        if(vis[adj[p.first][j]]==1&&p.second!=adj[p.first][j]){
                            return false;
                        }
                        else if(vis[adj[p.first][j]]==0){
                            vis[adj[p.first][j]]=1;
                            q.push({adj[p.first][j],p.first});
                        }
                    }
                }
            }
        }
        return true;
    }
};
