// 236. Lowest Common Ancestor of a Binary Tree
// runtime：17 ms Beats 23.92%
// space : 16.29 MB Beats 60.34%

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr||root==p||root==q){
            return root;
        }
        TreeNode * left=lowestCommonAncestor(root->left,p,q);
        TreeNode * right=lowestCommonAncestor(root->right,p,q);
        if(left!=nullptr&&right!=nullptr){ // 都不為空，代表p和q在當前root的左右兩側 
            return root;
        }
        else if(left!=nullptr){ // 只有左不為空，代表p和q都在左子樹為root裡面
            return left;
        }
        else{ // 只有右不為空，代表p和q都在右子樹為root裡面
            return right;
        }
    }
};