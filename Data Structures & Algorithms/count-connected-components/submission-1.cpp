class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int count=0;
        vector<vector<int>> adj(n);
        vector<int> vis(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(vis[i]!=1){
                count++;
                q.push(i);
                vis[i]=1;
                while(!q.empty()){
                    int k= q.front();
                    q.pop();
                    for(int j=0;j<adj[k].size();j++){
                        if(!vis[adj[k][j]]){
                            vis[adj[k][j]]=1;
                            q.push(adj[k][j]);
                        }
                    }
                }

            }
        }
        return count;
    }
};
