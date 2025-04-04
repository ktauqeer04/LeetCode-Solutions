class Solution {
public:

    int maxD = 0;

    void solve(TreeNode* root, int depth){
        if(!root) return;
        maxD = max(maxD, depth);
        solve(root -> left, depth + 1);
        solve(root -> right, depth + 1);
    }

    TreeNode* find(TreeNode* root, int depth){
        if(!root) return nullptr;
        if(depth == maxD) return root;
        TreeNode* left = find(root -> left, depth + 1);
        TreeNode* right = find(root -> right, depth + 1);

        if(left && right) return root;

        return left ? left : right;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        solve(root, 0);

        TreeNode* ans = find(root, 0);

        return ans;

    }
};