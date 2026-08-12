class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        solve(result, "", 0, 0, n);
        return result;
    }
    
private:
    void solve(vector<string>& result, string current, int open, int close, int n) {
        if (current.length() == n * 2) {
            result.push_back(current);
            return;
        }
        
        if (open < n) {
            solve(result, current + "(", open + 1, close, n);
        }
        if (close < open) {
            solve(result, current + ")", open, close + 1, n);
        }
    }
};