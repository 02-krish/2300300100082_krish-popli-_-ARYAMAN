 
class Solution {
public:
    TreeNode* getSuccessor(TreeNode* root) {
        while (root->left != NULL)
            root = root->left;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;

        if (key < root->val)
            root->left = deleteNode(root->left, key);

        else if (key > root->val)
            root->right = deleteNode(root->right, key);

        else {
            if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            TreeNode* succ = getSuccessor(root->right);
            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val);
        }

        return root;
    }
};