class Solution {
public:
    string encode(vector<string>& strs) {
        string res = "";
        for (const auto str : strs)
            res = res + to_string(str.size()) + "#" + str;
        return res;
    }

    vector<string> decode(string s) {
        int index = 0;
        vector<string> res;
        while (index < s.size()) {
            int len = stoi(s.substr(index));
            index = s.find("#", index);
            res.push_back(s.substr(index + 1, len));
            index += len + 1;
        }
        return res;
    }
};
