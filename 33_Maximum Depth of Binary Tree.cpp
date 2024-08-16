// 104. Maximum Depth of Binary Tree
// runtime：8 ms Beats 37.34%
// space : 17.66 MB Beats 48.26%

// 遞迴本身就包含了計數的功能。在遞迴中，每一層函數調用都負責處理當前的節點並將結果返回給上層，這樣就自然而然地實現了計數的功能
//     1
//    / \
//   2   3
//  / 
// 4  
//   1.	從根節點 1 開始，遞迴進入左子樹根節點 2，然後再進入節點 4。
//   2.	當到達 4 的左右子節點時，它們都是 nullptr，所以對這些 nullptr 的 maxDepth 會返回 0。
//   3.	回到節點 4，max(0, 0) + 1 得到深度 1。
//   4.	返回節點 2，max(1, 0) + 1 得到深度 2。
//   5.	返回節點 1，計算右子樹（深度為 1），最後 max(2, 1) + 1 得到深度 3

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
    int maxDepth(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int x=maxDepth(root->right);
        int y=maxDepth(root->left);
        return max(x,y)+1; // +1是為了得到深度多少 
    }
};