/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int inorder(TreeNode* root , int low , int high){
        if(root == nullptr)
            return 0;
        int sum = 0;

        if(root->val >= low && root->val <= high){
            sum  += root->val;
        }
        if(root->val > low){
            sum += inorder(root->left , low , high);
        }
        if(root->val < high){
            sum += inorder(root->right , low , high);
        }
        return sum;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return inorder(root , low , high);
    }
};