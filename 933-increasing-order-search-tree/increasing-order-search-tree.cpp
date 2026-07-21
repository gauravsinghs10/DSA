class Solution {
public:
    TreeNode* current;
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(0);
        current = dummy;
        inorder(root);
        return dummy->right;
    }
    
    void inorder(TreeNode* node) {
        if (!node) return;
        
        inorder(node->left);
        
        node->left = nullptr;
        current->right = node;
        current = node;
        
        inorder(node->right);
    }
};