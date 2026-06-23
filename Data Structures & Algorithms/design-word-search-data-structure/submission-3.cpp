
struct Node{
    Node* links[26];
    bool flag;
    Node(){
        flag=false;
    for(int i=0;i<26;i++){
        links[i]=nullptr;
    }
    }
    bool containskey(char i){
        if(links[i-'a']!=nullptr) return true;
        return false;
    }
    void createkey(char i, Node* node){
        links[i-'a']= node;
    }
    Node* get(char i){
        return links[i-'a'];
    }
};
class WordDictionary {
     private: Node *root;
public:
    WordDictionary() {
         root = new Node();
    }
    
    void addWord(string word) {
        Node *node= root;
        for(int i=0; i<word.size();i++){
            if(!node->containskey(word[i])){
               node->createkey(word[i],new Node);
            }
          node=  node->get(word[i]);
        }
        node->flag=true;
        
    }
    
    bool search(string word) {
        return dfs(root,0,word);
    }
    bool dfs(Node* node, int idx, string &word){
        if(idx == word.size()) return node->flag;
        if(word[idx] != '.'){
            if(!node->containskey(word[idx])) return false;
            node=  node->get(word[idx]);
           return dfs(node,idx+1,word);
        }
        else if(word[idx] == '.'){
            for(int i=0;i<26;i++){
                if(node->links[i]!=nullptr) {
                    if(dfs(node->links[i],idx+1,word)){
                        return true;
                    }
                    };
            }
        }
    return false;
    }
};