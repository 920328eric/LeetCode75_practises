// 1372. Longest ZigZag Path in a Binary Tree
// runtime：107 ms Beats 87.01%
// space : 92.82 MB Beats 34.75%

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
    int maxlength=0;
    int longestZigZag(TreeNode* root) {
        if(root->left==nullptr&&root->right==nullptr){
            return 0;
        }
        zigzag(root,true,0);
        zigzag(root,false,0);
        return maxlength;
    }
    void zigzag(TreeNode * root,bool isright,int length){
        if(root==nullptr){
            return;
        }
        maxlength=max(maxlength,length);
        if(isright==true){
            zigzag(root->left,false,length+=1);
            zigzag(root->right,true,1);
        }
        else{
            zigzag(root->right,true,length+=1);
            zigzag(root->left,false,1);
        }
    }
};