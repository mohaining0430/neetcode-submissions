class Solution {
public:
    bool checkValidString(string s) {
        stack<int> leftIndex, starIndex;
        for (int i = 0; i < s.size(); ++i) {
            auto c = s[i];
            if (c == '(') {
                leftIndex.push(i);
            } else if (c == '*') {
                starIndex.push(i);
            } else {
                if (!leftIndex.empty()) {
                    leftIndex.pop();
                } else if (!starIndex.empty()) {
                    starIndex.pop();
                } else {
                    return false;
                }
            }
        }

        while (!leftIndex.empty()) {
            int left = leftIndex.top();
            leftIndex.pop();
            if (starIndex.empty() || starIndex.top() < left)
                return false;
            else
                starIndex.pop();
        }

        return true;
    }
};
