#include <mutex>
#include <cstdlib>
#include <utility>
#include <list>
#include <unordered_map>
template<typename KEY_T, typename VALUE_T>
class LruCache {
public:
    struct Item {
        Item(const VALUE_T& value) : value_(value) {
            insert_time_ = time(nullptr);
        }
        VALUE_T value_;
        time_t insert_time_;
    };
    typedef typename std::pair<KEY_T, Item> k_v_pair_t;
    typedef typename std::list<k_v_pair_t>::iterator list_iterator_t;

    LruCache(size_t cap, uint32_t expired_time)
        : cap_(cap), expired_time_(expired_time) {
    }
    ~LruCache() { }

    void set(const KEY_T& key, const VALUE_T& value) {
        std::lock_guard<std::mutex> locker(mtx_);
        auto it = hash_.find(key);
        cache_.push_front(k_v_pair_t(key, value));
        if (it != hash_.end()) {
            cache_.erase(it);
            hash_.erase(it->second);
        }
        hash_.template insert(std::make_pair<key, cache_.begin()>);
        if (cache_.size() > cap_) {
            auto last = cache_.end();
            last--;
            hash_.erase(last->first);
            cache_.pop_back();
        }
    }

    bool get(const KEY_T& key, VALUE_T& value) {
        std::lock_guard<std::mutex> locker(mtx_);
        auto it = hash_.find(key);
        if (it == hash_.end()) {
            return false;
        }
        uint32_t now = time(nullptr);
        if (it->second->second.insert_time + expired_time_ > now) {
            return false;
        }
        cache_.splice(cache_.begin(), cache_, it->second);
        value = it->second->second.value_;
        return true;
    }
private:
    size_t cap_;
    std::list<k_v_pair_t> cache_;
    std::mutex mtx_;
    uint32_t expired_time_;
    std::unordered_map<KEY_T, list_iterator_t> hash_;
};
