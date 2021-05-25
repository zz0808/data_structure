#include <iostream>
#include <unordered_map>
#include <list>
#include <utility>
#include <mutex>
using namespace std;

class LruCache {
public:
    /**
     * lru design
     * @param operators int整型vector<vector<>> the ops
     * @param k int整型 the k
     * @return int整型vector
     */
    LruCache(size_t n = 10) {
        cap = n;
    }
    
    void set(int key, int value) {
        auto it = hash.find(key);
        if (it != hash.end()) {
            lru_cache.erase(it->second);
            hash.erase(key);
        }
        lru_cache.emplace_front(key, value);
        hash.emplace(key, lru_cache.begin());
        if (lru_cache.size() > cap) {
            hash.erase(lru_cache.back().first);
            lru_cache.pop_back();
        }
    }
    
    int get(int key) {
        auto it = hash.find(key);
        if (it == hash.end()) {
            return -1;
        }
        unique_lock<mutex> lck(mtx, try_to_lock);
        if (lck) {
            pair<int, int> kv = {it->first, it->second->second};
            lru_cache.erase(it->second);
            hash.erase(key);
            lru_cache.push_front(kv);
            hash.emplace(kv.first, lru_cache.begin());   
            lck.unlock();        
        }

        return kv.second;
    }
    
private:
    size_t cap;
    list<pair<int, int>> lru_cache;
    unordered_map<int, list<pair<int, int>>::iterator> hash;
    mutex mtx;
};

int main(int argc, char const *argv[])
{
        vector<int> LRU(vector<vector<int> >& operators, int k) {
        // write code here
        vector<int> ans;
        if (k <= 0) {
            return ans;
        }
        cap = k;
        for (vector<int>& opert : operators) {
            if (opert[0] == 2) {
                int key = opert[1];
                ans.push_back(get(key));
            } else if (opert[0] == 1) {
                int key = opert[1], value = opert[2];
                set(key, value);
            }
        }
        
        return ans;
    }
    return 0;
}