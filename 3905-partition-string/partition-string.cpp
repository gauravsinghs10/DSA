class Solution {
public:
    vector<string> partitionString(string s) {
        vector<string> result;
        unordered_set<string> seen;
        string current = "";

        for (char c : s) {
            current += c;
            if (seen.find(current) == seen.end()) {
                result.push_back(current);
                seen.insert(current);
                current = "";
            }
        }

        return result;
    }
};