class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache;
    Node* oldest;
    Node* latest;

    void remove(Node* node) {
        if (!node)
            return;
        Node* prevN = node->prev;
        Node* nextN = node->next;
        if (prevN)
            prevN->next = nextN;
        if (nextN)
            nextN->prev = prevN;
        node->prev = node->next = nullptr;
    }

    void insertBeforeLatest(Node* node) {
        Node* prevN = latest->prev;
        prevN->next = node;
        node->prev = prevN;
        node->next = latest;
        latest->prev = node;
    }

    void moveToLatest(Node* node) {
        if (node->next == latest) return;
        remove(node);
        insertBeforeLatest(node);
    }

public:
    LRUCache(int capacity) : cap(capacity) {
        oldest = new Node(0, 0);
        latest = new Node(0, 0);
        oldest->next = latest;
        latest->prev = oldest;
    }

    ~LRUCache() {
        Node* cur = oldest;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        Node* node = it->second;
        moveToLatest(node);
        return node->val;
    }

    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            Node* node = it->second;
            node->val = value;
            moveToLatest(node);
            return;
        }

        Node* node = new Node(key, value);
        cache[key] = node;
        insertBeforeLatest(node);

        if ((int)cache.size() > cap) {
            Node* lru = oldest->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */