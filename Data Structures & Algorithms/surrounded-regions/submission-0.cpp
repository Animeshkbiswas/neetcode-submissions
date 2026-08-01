class Solution {
public:
    void bfs(vector<vector<char>>& board,vector<vector<int>> & vis,int i,int j){
        int row= board.size();
        int col= board[0].size();
        vis[i][j]=1;
        bool b= true;
         if(i==0||i==row-1||j==0||j==col-1){
                    b=false;
                }
        queue<pair<int,int>> w;
        queue<pair<int,int>> region;
        w.push({i,j});
        region.push({i,j});
        while(!w.empty()){
            pair p= w.front();
            w.pop();
            int x= p.first;
            int y= p.second;
            if(x-1>=0 && board[x-1][y]=='O'&& vis[x-1][y]!=1){
                vis[x-1][y]=1;
                w.push({x-1,y});
                region.push({x-1,y});
                if(x-1==0||x-1==row-1||y==0||y==col-1){
                    b=false;
                }
            }
            if(x+1<row && board[x+1][y]=='O'&& vis[x+1][y]!=1){
                vis[x+1][y]=1;
                w.push({x+1,y});
                region.push({x+1,y});
                if(x+1==0||x+1==row-1||y==0||y==col-1){
                    b=false;
                }
            }
            if(y-1>=0 && board[x][y-1]=='O'&& vis[x][y-1]!=1){
                vis[x][y-1]=1;
                w.push({x,y-1});
                region.push({x,y-1});
                if(x==0||x==row-1||y-1==0||y-1==col-1){
                    b=false;
                }
            }
            if(y+1<col && board[x][y+1]=='O'&& vis[x][y+1]!=1){
                vis[x][y+1]=1;
                w.push({x,y+1});
                region.push({x,y+1});
                if(x==0||x==row-1||y+1==0||y+1==col-1){
                    b=false;
                }
            }
        }
        if(b==true){
            while(!region.empty()){
                pair p= region.front();
                region.pop();
                int x= p.first;
                int y= p.second;
                board[x][y]='X';
            }
        }
        
    }
    void solve(vector<vector<char>>& board) {
        int row= board.size();
        int col= board[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]=='O'){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            pair p= q.front();
            q.pop();
            int x= p.first;
            int y= p.second;
            if(vis[x][y]==0){
                bfs(board,vis,x,y);
            }
        }
    }
};
