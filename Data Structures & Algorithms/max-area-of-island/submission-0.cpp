class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& vis,int m, int n,int area){
        int i=grid.size();
        int j= grid[0].size();
        vis[m][n]=1;
        area++;
        if(m-1>=0&&grid[m-1][n]==1&&vis[m-1][n]==0 ){
           area= dfs(grid,vis,m-1,n,area);
        }
         if(m+1<i&&grid[m+1][n]==1 &&vis[m+1][n]==0){
            area=dfs(grid,vis,m+1,n,area);
        }
         if(n-1>=0&&grid[m][n-1]==1 &&vis[m][n-1]==0){
            
            area= dfs(grid,vis,m,n-1,area);
        }
        if(n+1<j&&grid[m][n+1]==1 && vis[m][n+1]==0){
            area= dfs(grid,vis,m,n+1,area);
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        int row= grid.size();
        int col= grid[0].size();
        vector<vector<int>>vis(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0; j<col; j++){
                if(vis[i][j]==0&& grid[i][j]==1){
                    int k= dfs(grid,vis,i,j,0);
                    ans= max(ans,k);
                }
            }
        }
        return ans;
    }
};
