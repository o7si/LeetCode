class LRUCache {
public:
    LRUCache(int capacity) {
        
        this->capacity = capacity;
    }
    
    int get(int key) {
        
        if (hash.find(key) == hash.end())
            return -1;

        visitUpdate(key);
        return hash[key];
    }
    
    void put(int key, int value) {

        if (hash.find(key) != hash.end()) {

            hash[key] = value;
            visitUpdate(key);
            return;
        }

        if (hash.size() >= capacity) {

            hash.erase(visit.front());
            visit.pop_front();
            hash[key] = value;
            visitUpdate(key);
        } else {

            hash[key] = value;
            visitUpdate(key);
        }
    }
private:
    void visitUpdate(int key) {

        visit.remove(key);
        
        auto pre = visit.before_begin();
        auto cur = visit.begin();
        while (cur != visit.end()) {

            ++ pre;
            ++ cur;
        }
        visit.insert_after(pre, key);            
    }

    unordered_map<int, int> hash;
    forward_list<int> visit;
    int capacity;
};
