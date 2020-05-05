class LRUCache {
    unordered_map<int, pair<int,int>> _map_key_time_value;//first is key and second is pair of <time,value>
    //time can be done by counter 
    int _counter;
    int _capacity;

    map<int,int> _counter_key_map;//leas counter value is for LRU key
    
public:
    LRUCache(int capacity) {
        _counter = 0;

        _capacity = capacity;
        _map_key_time_value.reserve(_capacity);
    }
    
    int get(int key) {
        //get value and then need to update its time value with current counter value
        auto it = _map_key_time_value.find(key);
        if (it != _map_key_time_value.end()) {
            auto val = it->second;
            int old_count = val.first;
            _counter_key_map.erase(old_count);
            ++_counter;
            it->second.first = _counter;
            _counter_key_map.insert(pair<int,int>(_counter, key));
            return val.second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        
        ++_counter;
        auto it = _map_key_time_value.find(key);
        if (it != _map_key_time_value.end()) {
            pair<int,int> val = it->second;
            int old_count = val.first;
            val.first = _counter;
            val.second = value;
            it->second = val;
            _counter_key_map.erase(old_count);
            _counter_key_map.insert(pair<int,int>(_counter,key));
            return;
        }
        
        if (_map_key_time_value.size() == _capacity) {
            //need to remove least recetly used key
            int least_used_key = (_counter_key_map.begin())->second;
            _map_key_time_value.erase(least_used_key);
            _counter_key_map.erase((_counter_key_map.begin())->first);
        }

        _counter_key_map.insert(pair<int,int>(_counter,key));
        _map_key_time_value.emplace(pair<int, pair<int,int>>(key, {_counter, value}));
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */