class Solution {
public:
    string merge(string s1, string s2) {
        if (s1.find(s2) != string::npos) return s1;
        for (int i = 0; i < s1.length(); i++) {
            if (s2.substr(0, s1.length() - i) == s1.substr(i)) {
                return s1 + s2.substr(s1.length() - i);
            }
        }
        return s1 + s2;
    }

    string minimumString(string a, string b, string c) {
        vector<string> arr = {a, b, c};
        vector<vector<int>> perms = {
            {0, 1, 2}, {0, 2, 1}, {1, 0, 2},
            {1, 2, 0}, {2, 0, 1}, {2, 1, 0}
        };

        string ans = "";

        for (auto& p : perms) {
            string res = merge(merge(arr[p[0]], arr[p[1]]), arr[p[2]]);
            if (ans == "" || res.length() < ans.length() || 
               (res.length() == ans.length() && res < ans)) {
                ans = res;
            }
        }

        return ans;
    }
};