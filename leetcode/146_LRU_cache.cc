class LRUCache {
public:
    LRUCache(int capacity): capacity_(capacity) {
        
    }
    
    int get(int key) {
        auto    iter_map = map_.find(key);
        if (iter_map == map_.end())
            return -1;

        auto    iter_cache = iter_map->second;
        auto    pair = *iter_cache;
        cache_.erase(iter_cache);
        cache_.push_back(pair);
        iter_map->second = --cache_.end();
        
        return pair.second;
    }
    
    void put(int key, int value) {
        auto    iter_map = map_.find(key);
        if (iter_map != map_.end()) {
            cache_.erase(iter_map->second);
            map_.erase(iter_map);
        }
        if (cache_.size() == capacity_) {
            int lru_key = cache_.front().first;
            cache_.pop_front();
            map_.erase(lru_key);
        }
        
        // put.
        cache_.push_back(pair<int, int> {key, value});
        map_[key] = --cache_.end();
    }
private:
    typedef list<pair<int, int> > CacheType;
    
    unordered_map<int, CacheType::iterator> map_;
    CacheType   cache_;
    int         capacity_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */