class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastPosMap;
        for (int i = 0; i < s.size(); ++i)
            lastPosMap[s[i]] = i; 
        
        vector<int> res;
        int lastPos = -1;
        int startPos = 0;
        for (int i = 0; i < s.size(); ++i) {
            lastPos = max(lastPos, lastPosMap[s[i]]);
            if (i == lastPos) {
                res.push_back(lastPos - startPos + 1);
                startPos = lastPos + 1;
                lastPos = -1;
            }
        }
        return res;
    }
};
