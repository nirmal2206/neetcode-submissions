class LRUCache {
private:
    struct Node{
        int key, val;
        Node* prev;
        Node* next;

        Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr){}
    };
    int capacity;
    unordered_map<int, Node*> cache;

    Node* head; // dummy head points to MRU
    Node* tail; // dummy tail points to LRU

// Helper: Remove a node from the doubly linked list
    void removeNode(Node* node){
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

// Helper: Insert a node right after head (MRU position)
    void insertInFront(Node* node){
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity): capacity(capacity) {
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        
        if(cache.find(key) == cache.end()) return -1;

        Node* node = cache[key];
        removeNode(node);
        insertInFront(node);

        return node->val;
    }
    
    void put(int key, int value) {
        //if key exists already, update the value and move to front
        if(cache.find(key) != cache.end()){
            Node* oldNode = cache[key];
            oldNode->val = value;
            removeNode(oldNode);
            insertInFront(oldNode);
        } else {
            //if not, create a new node, and move to front
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            insertInFront(newNode);

            if(cache.size() > capacity){
                Node* lruNode = tail->prev;
                removeNode(lruNode);
                cache.erase(lruNode->key);
                delete lruNode;
            }
        }
    }

    ~LRUCache() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};
