class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=0;
        vector<int> vis((n*n),0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({grid[0][0],0});
        while(!pq.empty()){
            pair<int,int> p= pq.top();
            pq.pop();
            int idx= p.second;
            int weight= p.first;
            if(vis[idx]==1) continue;
            vis[idx] = 1;
            ans= max(ans,weight);
            int row= idx/n;
            int col= idx%n;
            if(idx==n*n-1) break;
            if(row-1>=0 && vis[(row-1)*n+col]!=1){
                pq.push({grid[row-1][col],((row-1)*n+col)});
            }
            if(row+1<n && vis[(row+1)*n+col]!=1){
                pq.push({grid[row+1][col],((row+1)*n+col)});
            }
              if(col-1>=0 && vis[row*n+(col-1)]!=1){
                pq.push({grid[row][col-1],(row*n+(col-1))});
            }
              if(col+1<n && vis[row*n+col+1]!=1){
                pq.push({grid[row][col+1],(row*n+(col+1))});
            }
        }
        return ans;
    }
};
