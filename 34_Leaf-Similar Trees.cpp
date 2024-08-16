// 872. Leaf-Similar Trees
// runtime：3 ms Beats 58.33%
// space : 14.68 MB Beats 16.18%

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1,leaves2;
        getLeavesSeq(root1,leaves1);
        getLeavesSeq(root2,leaves2);
        if(leaves1==leaves2){
            return true;
        }
        else{
            return false;
        }
    }
    void getLeavesSeq(TreeNode * node,vector<int>& leaves){
        if(node==nullptr){
            return; // 立即結束當前函數的執行，並返回到函數的調用處，遇到空子樹時提前終止遞迴，避免不必要的操作
        }
        if(node->right==nullptr&&node->left==nullptr){
            leaves.push_back(node->val);
        }
        else{
            getLeavesSeq(node->left,leaves);
            getLeavesSeq(node->right,leaves);
        }
    }
};