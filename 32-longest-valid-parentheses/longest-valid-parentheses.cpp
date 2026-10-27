#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        std::stack<int> st;
        st.push(-1); // Base boundary for valid substrings
        
        int maxLength = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    // Current ')' has no matching '(' -> set new boundary
                    st.push(i);
                } else {
                    // Calculate length from current index to top of stack
                    maxLength = std::max(maxLength, i - st.top());
                }
            }
        }
        
        return maxLength;
    }
};