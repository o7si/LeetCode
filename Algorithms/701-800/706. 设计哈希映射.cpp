class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        
        expansion(key);
        hash[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        
        expansion(key);
        return hash[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        
        expansion(key);
        hash[key] = -1;
    }
private:
    void expansion(int key) {
        
        if (key >= hash.size())
            hash.resize(key + 1, -1);
    }
    vector<int> hash;
};
