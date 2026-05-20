class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        data[key].push_back(std::make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        auto iter = data.find(key);
        if (iter == data.end()) return "";
        auto pairs = iter->second;
        int left = 0, right = pairs.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (pairs[mid].first <= timestamp)
                left = mid + 1;
            else
                right = mid;
        }
        return left >= 1 ? pairs[left - 1].second : "";
    }

private:
    std::unordered_map<string, vector<pair<int, string>>> data;
};
