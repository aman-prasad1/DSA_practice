class SmallestInfiniteSet {
    map<int,int> mp;
public:
    SmallestInfiniteSet() {
        for(int i=1; i<=1000; i++) mp[i]++;
    }
    
    int popSmallest() {
        int res = mp.begin()->first;
        mp.erase(res);
        return res;
    }
    
    void addBack(int num) {
        mp[num]++;
    }
};
