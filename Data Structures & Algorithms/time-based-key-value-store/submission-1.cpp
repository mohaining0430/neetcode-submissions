class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        data[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!data.contains(key))
            return "";
        auto& pairs = data[key];
        int left = 0, right = pairs.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (pairs[mid].first <= timestamp)
                left = mid + 1;
            else 
                right = mid;
        }
        if (left >= 1 && pairs[left - 1].first <= timestamp)
            return pairs[left - 1].second;
        else
            return "";
    }

private:
    unordered_map<string, vector<pair<int, string>>> data;
};
