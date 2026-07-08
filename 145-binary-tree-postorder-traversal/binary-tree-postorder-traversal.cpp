class Solution {
public:
    void porder(TreeNode* root, vector<int>& ans){
        if(root == NULL) return;

        porder(root->left, ans);
       
        porder(root->right, ans);
         ans.push_back(root->val);
    }

    vector<int>  postorderTraversal(TreeNode* root) {
        vector<int> ans;
        porder(root, ans);
        return ans;
    }
};
