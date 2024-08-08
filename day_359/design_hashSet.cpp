class MyHashSet {
    vector<bool> map;
public:
    MyHashSet() {
        map.resize(1e6+1, 0);
    }
    
    void add(int key) {
        map[key] = 1;
    }
    
    void remove(int key) {
        map[key] = 0;
    }
    
    bool contains(int key) {
        return map[key];
    }
};
