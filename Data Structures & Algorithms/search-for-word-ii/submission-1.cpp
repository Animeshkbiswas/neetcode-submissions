
class Solution {
public:
    
struct Node{
    Node* links[26];
    bool flag;
    string word;
    Node(){
        flag= false;
        for(int i=0; i<26;i++){
            links[i]=nullptr;
        }
    } 
};
class Trie{
public:
    Node* root;

    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(isPresent(word[i],node))node= node->links[word[i]-'a'];
            else{
                Node* temp= new Node();
                node->links[word[i]-'a']=temp;
                node= temp;
            }
        }
        node->flag=true;
       node->word = word;
    }
    bool isPresent(char r,Node* node){
        if(node->links[r-'a']!=nullptr) return true;

        return false;
    }
};
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        Trie trie;
        for(string &word : words){
            trie.insert(word);
        }
        for(int i=0;i<board.size();i++){
             for(int j=0;j<board[0].size();j++){   
                dfs(board, i, j, trie.root, ans);
             }
        }
       
        return ans;
    }
    void dfs(vector<vector<char>>& board, int row, int col,Node* node, vector<string> &ans){
        if(row<0|| col<0||row>=board.size()|| col>=board[0].size()){
            return;
        }
        char ch = board[row][col];
        if(board[row][col]=='#')
        return;
        if((node->links[ch-'a'])==nullptr){
            return;
        }
        node = node->links[ch-'a'];
        if(node->flag){
         ans.push_back(node->word);
         node->flag=false;
        }
        char temp = board[row][col];
        board[row][col] = '#';
            dfs(board,row+1,col,node,ans);

           dfs(board,row,col+1,node,ans);
           
           dfs(board,row-1,col,node,ans);
           
           dfs(board,row,col-1,node,ans);
           
        board[row][col]= temp;
        }
    
};
