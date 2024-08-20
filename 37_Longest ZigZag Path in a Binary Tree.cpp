// 1372. Longest ZigZag Path in a Binary Tree
// runtime：128 ms Beats 27.61%
// space : 92.80 MB Beats 34.96%

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
    int maxlength;
    int longestZigZag(TreeNode* root) {
        if(root->left==nullptr&&root->right==nullptr){
            return 0;
        }
        zigzag(root,false,0);
        zigzag(root,true,0);
        return maxlength;
    }
    void zigzag(TreeNode * root,bool isright,int length){
        if(root==nullptr){
            return;
        }
        maxlength=max(maxlength,length);
        if(isright==true){ // 往右走
            zigzag(root->left,false,length+=1); // 往左走，是正確的步驟會跳到37行，持續增加length長度
            zigzag(root->right,true,1); // 再往右走是錯誤的，所以初始化新的路徑
        }
        else{ // 往左走
            zigzag(root->right,true,length+=1); // 往右走，是正確的步驟會跳到33行，持續增加length長度
            zigzag(root->left,false,1); // 再往左走是錯誤的，所以初始化新的路徑
        }
    }
};