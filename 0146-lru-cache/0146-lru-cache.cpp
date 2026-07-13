class LRUCache {
private:
    class Node {
    public:
        int key, value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = next = nullptr;
        }
    };

    int capacity;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    // Remove node from list
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Insert node right after head (MRU position)
    void insert(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        remove(node);
        insert(node);

        return node->value;
    }

    void put(int key, int value) {

        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;

            remove(node);
            insert(node);
            return;
        }

        if (mp.size() == capacity) {
            Node* lru = tail->prev;

            remove(lru);
            mp.erase(lru->key);

            delete lru;
        }

        Node* node = new Node(key, value);
        insert(node);
        mp[key] = node;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna