// 1448. Count Good Nodes in Binary Tree
// runtime：94 ms Beats 69.69%
// space : 86.15 MB Beats 8.47%

// you have to recurse the max value, so you need to create the new structure

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
    int goodNodes(TreeNode* root) {
        return countnum(root,root->val);
    }
    int countnum(TreeNode * root,int maxval){
        if(root==nullptr){
            return 0;
        }
        int count = 0;
        if(root->val >= maxval){ // determine whether the current node is good
            count=1; 
        }
        else{
            count=0;
        }
        maxval=max(maxval,root->val);
        count+=countnum(root->left,maxval);
        count+=countnum(root->right,maxval);
        return count;
    }
};