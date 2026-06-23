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
class PrefixTree {
    private: Node *root;
public:

    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
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
        Node *node= root;
        for(int i=0;i<word.size();i++){
            if(!node->containskey(word[i])) return false;
           node= node->get(word[i]);
        }
        if(node->flag==true){
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        Node *node= root;
        for(int i=0;i<prefix.size();i++){
            if(!node->containskey(prefix[i])) return false;
           node= node->get(prefix[i]);
        }
        return true;
        
    }
};
