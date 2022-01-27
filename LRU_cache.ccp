class LRUCache {
public:
    int cap;
    unordered_map <int, pair < list <int>:: iterator,int> > mp;
    list <int> dll;
    
    LRUCache(int capacity) 
    {
        cap = capacity;
    }
    
    int get(int key) 
    {
        if(mp.find(key) != mp.end())
        {
            dll.erase(mp[key].first);
            dll.push_front(key);
            mp[key].first = dll.begin();
            return mp[key].second;
        }
        else
            return -1;
    }
    
    void put(int key, int value) 
    {
        // key not present, we insert it into map and list, take care of 
        // capacity going negative below
        if(mp.find(key) == mp.end())
        {
            dll.push_front(key);
            mp[key] = { dll.begin(), value};
            cap--;
        }
        // key is present
        else
        {
            // update value
            mp[key].second = value;
            dll.erase(mp[key].first);
            dll.push_front(key);
            mp[key].first = dll.begin();
        }
        
        if(cap < 0)
        {
            mp.erase(dll.back());
            dll.pop_back();
            cap++;
        }
    }
};