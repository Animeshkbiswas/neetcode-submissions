class Solution {
public:
    void dfs(vector<vector<int>>& grid,int m,int n,int dist ){
        int row= grid.size();
        int col= grid[0].size();
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        if (grid[m][n] < dist) return;
        grid[m][n]=dist;
        for(int k=0;k<4;k++){
            int nr= m+ dr[k];
            int nc= n+ dc[k];
            if(nr>=0&&nc>=0&&nr<row&& nc<col&&grid[nr][nc]!=-1){
                dfs(grid,nr,nc,dist+1);
            }
        }

    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int row= grid.size();
        int col= grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==0){
                    dfs(grid,i,j,0);
                }
            }
        }
    }
};
