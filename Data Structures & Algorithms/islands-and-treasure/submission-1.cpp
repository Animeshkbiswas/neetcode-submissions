class Solution {
public:
    void bfs(vector<vector<int>>& grid,queue<pair<int,int>>& q,int m,int n){
        long long p=2147483647;
        int row= grid.size();
        int col= grid[0].size();
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        for(int k=0;k<4;k++){
            int nr= m+ dr[k];
            int nc= n+ dc[k];
            if(nr>=0&&nc>=0&&nr<row&& nc<col&&grid[nr][nc]==p){
                grid[nr][nc]= grid[m][n] + 1;
                q.push({nr,nc});
            }
        }
        

    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int row= grid.size();
        int col= grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            pair <int,int>p= q.front();
            q.pop();
            int m=p.first;
            int n=p.second;
            bfs(grid,q,m,n);
        }
    }
};
