class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> result;
        vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string current = "";
        
        backtrack(digits, 0, pad, current, result);
        return result;
    }
    
private:
    void backtrack(const string& digits, int index, const vector<string>& pad, string& current, vector<string>& result) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        
        string letters = pad[digits[index] - '0'];
        for (char c : letters) {
            current.push_back(c);
            backtrack(digits, index + 1, pad, current, result);
            current.pop_back();
        }
    }
};