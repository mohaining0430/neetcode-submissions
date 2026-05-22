class Solution {
public:
    vector<string> letterCombinations(string digits) {
        createDict();
        string output;
        vector<string> res;
        if(digits.empty())
        	return res;
        
        dfs(digits, 0, output, res);
        return res;
    }

    void dfs(string &digits, int index, string &output, vector<string> &res) {
        if (index == digits.size()) {
            res.push_back(output);
            return;
        }

        for (const char c : dict[digits[index]]) {
            output.push_back(c);
            dfs(digits, index + 1, output, res);
            output.pop_back();
        }
    }

private:
    map<char, vector<char>> dict;
    void createDict()
    {
        dict.clear();
        dict['2'].push_back('a'); dict['5'].push_back('l'); dict['9'].push_back('w');
        dict['2'].push_back('b'); dict['6'].push_back('m'); dict['9'].push_back('x');
        dict['2'].push_back('c'); dict['6'].push_back('n'); dict['9'].push_back('y');
        dict['3'].push_back('d'); dict['6'].push_back('o'); dict['9'].push_back('z');
        dict['3'].push_back('e'); dict['7'].push_back('p');
        dict['3'].push_back('f'); dict['7'].push_back('q');
        dict['4'].push_back('g'); dict['7'].push_back('r');
        dict['4'].push_back('h'); dict['7'].push_back('s');
        dict['4'].push_back('i'); dict['8'].push_back('t');
        dict['5'].push_back('j'); dict['8'].push_back('u');
        dict['5'].push_back('k'); dict['8'].push_back('v');
    }
};
