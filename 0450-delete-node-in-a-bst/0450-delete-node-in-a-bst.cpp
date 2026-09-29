class Solution {
public:

    TreeNode* findMin(TreeNode* root) {
        while (root->left != NULL) {
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        if (root == NULL) {
            return root;
        }

        // key chhoti hai
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }

        // key badi hai
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }

        // key mil gayi
        else {

            // left child nahi hai
            if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // right child nahi hai
            if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // dono children hain
            TreeNode* successor = findMin(root->right);

            root->val = successor->val;

            root->right = deleteNode(root->right, successor->val);
        }

        return root;
    }
};