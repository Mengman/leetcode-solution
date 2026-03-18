/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start

struct DLinkedNode {
    int key, value;
    DLinkedNode* prev, *next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int k, int v): key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int cap;
    unordered_map<int, DLinkedNode*> hmap;
    DLinkedNode* head, *tail; // 哨兵节点

    // 将节点移出链表（不删除内存）
    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // 插入到头部（哨兵 head 之后）
    void addToHead(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity): cap(capacity) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!hmap.count(key)) return -1;

        DLinkedNode* node = hmap[key];
        removeNode(node);
        addToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (hmap.count(key)) {
            DLinkedNode* node = hmap[key];
            node->value = value;
            removeNode(node);
            addToHead(node);
        } else {
            if (hmap.size() == cap) {
                // 删除尾部节点（tail的前一个）
                DLinkedNode* removed = tail->prev;
                hmap.erase(removed->key);
                removeNode(removed);
                delete removed;
            }
            DLinkedNode* newNode = new DLinkedNode(key, value);
            hmap[key] = newNode;
            addToHead(newNode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

