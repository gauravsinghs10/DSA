class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end()); // String ko sort karke key banaya
            mp[key].push_back(s);         // Group me original string add ki
        }
        
        vector<vector<string>> result;
        for (auto auto_pair : mp) {
            result.push_back(auto_pair.second);
        }
        
        return result;
    }
};