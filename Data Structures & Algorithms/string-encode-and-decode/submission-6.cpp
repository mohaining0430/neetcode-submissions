class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for (const auto& str : strs)
            res += to_string(str.size()) + "#" + str;
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            int len = stoi(s.substr(i));
            int start = s.find("#", i);
            start++;
            string str = s.substr(start, len);
            res.push_back(str);
            i = start + len;
        }
        return res;
    }
};
