class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        set<pair<int,int>> s;
        for(int r=0; r<board.size();r++){
            for(int c=0; c<board[0].size();c++){
                bool res=dfs(r,c,0,board,word,s);
                if(res==true) return true;
            }
        }
        return false;
    }
    bool dfs(int r, int c, int i, vector<vector<char>>& board, string &word,set<pair<int,int>>&s){
        if(i==word.size()) return true;
        if(r<0||c<0||r>=board.size()|| c>=board[0].size()||(s.find({r,c})!=s.end()||word[i]!=board[r][c])) return false;
        s.insert({r,c});
      bool res= ( dfs(r+1,c,i+1,board,word,s)|| dfs(r,c+1,i+1,board,word,s)|| dfs(r-1,c,i+1,board,word,s)|| dfs(r,c-1,i+1,board,word,s));
        s.erase({r,c});
      if(res==true) return res;

      return false;
    }
};
