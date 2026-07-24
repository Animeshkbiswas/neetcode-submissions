class Solution {
    private:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int m, int n){
        int i=grid.size();
        int j= grid[0].size();
        vis[m][n]=1;
        if(m-1>=0&&grid[m-1][n]=='1'&&vis[m-1][n]==0 ){
            dfs(grid,vis,m-1,n);
        }
         if(m+1<i&&grid[m+1][n]=='1'&&vis[m+1][n]==0){
            dfs(grid,vis,m+1,n);
        }
         if(n-1>=0&&grid[m][n-1]=='1'&&vis[m][n-1]==0){
            dfs(grid,vis,m,n-1);
        }
        if(n+1<j&&grid[m][n+1]=='1'&&vis[m][n+1]==0){
            dfs(grid,vis,m,n+1);
        }

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n= grid[0].size();
       vector<vector<int>>vis(m, vector<int>(n,0));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n; j++){
                if(grid[i][j]=='1'&& !vis[i][j]){
                
                    ans++;
                    dfs(grid,vis,i,j);
                
                }
            }
        }
        return ans;
    }
};
