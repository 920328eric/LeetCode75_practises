// 437. Path Sum III
// runtime：16 ms Beats 60.99%
// space : 17.86 MB Beats 63.31%

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
    int ans=0;
    int pathSum(TreeNode* root, int targetSum) {
        if(root!=nullptr){
            dfs(root,targetSum);
            pathSum(root->left,targetSum);
            pathSum(root->right,targetSum);
        }
        return ans;
    }
    void dfs(TreeNode* root, long long sum){
        if(root==nullptr){
            return;
        }
        if(root->val==sum){
           ans++; 
        }
        dfs(root->left,sum-root->val);
        dfs(root->right,sum-root->val);
    }
};