
class Solution {
public:
    int min_diff = INT_MAX;
    int prev = -1; // Initialize to -1 since constraint says 0 <= Node.val <= 10^5

    void inorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        // Traverse Left
        inorder(root->left);

        // Process Current Node
        if (prev != -1) {
            min_diff = std::min(min_diff, root->val - prev);
        }
        prev = root->val; // Update prev to current node's value

        // Traverse Right
        inorder(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return min_diff;
    }
};