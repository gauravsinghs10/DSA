class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int l_max = 0, r_max = 0;
        int ans = 0;
        
        while (l < r) {
            l_max = max(l_max, height[l]);
            r_max = max(r_max, height[r]);
            
            if (l_max < r_max) {
                ans += l_max - height[l];
                l++;
            } else {
                ans += r_max - height[r];
                r--;
            }
        }
        
        return ans;
    }
};