  class Solution {
public:
    TreeNode* ans = NULL;

    int fun(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root == NULL)
            return 0;

        int left = fun(root->left, p, q);
        int right = fun(root->right, p, q);

        int self = (root == p || root == q);

        int total = left + right + self;

        if(total >= 2 && ans == NULL)
            ans = root;

        return total;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        fun(root, p, q);

        return ans;
    }
};