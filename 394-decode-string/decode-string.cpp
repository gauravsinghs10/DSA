class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> strings;
        string currentString = "";
        int k = 0;

        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            } else if (c == '[') {
                counts.push(k);
                strings.push(currentString);
                currentString = "";
                k = 0;
            } else if (c == ']') {
                int currentK = counts.top();
                counts.pop();
                string decodedString = strings.top();
                strings.pop();
                for (int i = 0; i < currentK; ++i) {
                    decodedString += currentString;
                }
                currentString = decodedString;
            } else {
                currentString += c;
            }
        }
        return currentString;
    }
};