// Define the Node structure
class ListNode {
    public:
        int key;    // the key of the node
        int value ;  // The data stored in the node
        ListNode* next;   // Pointer to the next node
        ListNode* prev;   // Pointer to the next node

    // Constructor to initialize a new node
    ListNode(int k, int val) : key(k), value(val), next(nullptr), prev(nullptr) {}
};
class LRUCache {
public:
    unordered_map<int, ListNode*>cache;
    ListNode* front;
    ListNode* back;
    int maxCap;

    LRUCache(int capacity) {
        cache.clear();
        maxCap = capacity;
        front = new ListNode(-1,-1);
        back = new ListNode(-1,-1);
        front->next = back;
        back->prev = front;
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end()) {
            ListNode* tp = cache[key];
            cache.erase(key);
            deleteNode(tp);
            insertNode(tp);
            cache[key] = front->next;
            return tp->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            ListNode* curr = cache[key];
            cache.erase(key);
            deleteNode(curr);
        }
        if(cache.size()==maxCap) {
            cache.erase(back->prev->key);
            deleteNode(back->prev);
        }
        insertNode(new ListNode(key,value));
        cache[key]= front->next;
    }

    void deleteNode(ListNode* delNode) {
        ListNode* prev = delNode->prev;
        ListNode* next = delNode->next;

        prev->next = next;
        next->prev = prev;
    }

    void insertNode(ListNode* newNode) {
        ListNode* next = front->next;
        next->prev = newNode;
        newNode->next = next;

        front->next = newNode;
        newNode->prev = front;
    }
};
