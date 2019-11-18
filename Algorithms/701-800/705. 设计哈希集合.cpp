class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        
    }
    
    void add(int key) {
        
        expansion(key);
        hash[key] = true;
    }
    
    void remove(int key) {
        
        expansion(key);
        hash[key] = false;
    }
    /** Returns true if this set contains the specified element */   
    bool contains(int key) {
        
        expansion(key);
        return hash[key];
    }
private:
    void expansion(int key) {
        
        if (key >= hash.size())
            hash.resize(key + 1, false);
    }
    vector<bool> hash;
};
