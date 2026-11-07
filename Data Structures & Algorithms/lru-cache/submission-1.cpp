class LRUCache {
public:
    list<pair<int,int>> dll;
    unordered_map<int,list<pair<int,int>>::iterator> mpp;
    int cap;
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end()){
            return -1;
        }

        auto it=mpp[key];
        int value=it->second;
        dll.erase(it);
        dll.push_front({key,value});
        mpp[key]=dll.begin();
        return value;
    }
    
    void put(int key, int value) {

        if(mpp.find(key)!=mpp.end()){
            dll.erase(mpp[key]);
            mpp.erase(key);
        }

        dll.push_front({key,value});
        mpp[key]=dll.begin();

        if(dll.size()>cap){
            int lrukey=dll.back().first;
            dll.pop_back();
            mpp.erase(lrukey);
        }
    }
};
