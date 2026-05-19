class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            while (!isvalidCharacter(s[left]))
                left++;
            if (left >= right)
                break;
            while (!isvalidCharacter(s[right]))
                right--;
            if (left >= right)
                break;
            if (s[left] != s[right] && std::tolower(s[left]) != std::tolower(s[right]))
                return false;
            left++;
            right--;
        }
        return true;
    }
private:
    static bool isvalidCharacter(const char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }
};
