class Link{
        public:
        int key;
        int val;
        Link* prev;
        Link* next;
        Link(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr)
        {}
    };
class LRUCache {
    private:
    int cap;
    unordered_map<int, Link*> cache;
    Link* left;
    Link* right;
    void remove (Link *node){
        Link *prev = node->prev;
        Link *nxt = node->next;
        prev->next = nxt;
        nxt->prev = prev;
    }
    void insert (Link *node){
        Link* prev= right->prev;
        prev->next =node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }
public:
    LRUCache(int capacity) {
        cap= capacity;
        cache.clear();
        left = new Link(0,0);
        right = new Link(0,0);
        left->next= right;
        right-> prev= left;
    }
    
    int get(int key) {
        if(cache.find(key)!= cache.end()){
            Link* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!= cache.end()){
            remove(cache[key]);
        }
        Link* newNode= new Link(key,value);
        cache[key]= newNode;
        insert(newNode);
        if(cache.size()>cap){
            Link* lru= left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
