// 199. Binary Tree Right Side View
// runtime：8 ms Beats 5.80%
// space : 14.49 MB Beats 29.15%

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode *> q;
        if(root==nullptr){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
            int qsize=q.size(); // 代表各level共有幾個數值
            for(int i=0;i<qsize;i++){
                TreeNode * temp=q.front();
                q.pop();
                if(i==qsize-1){ // 記錄各層的最後一個數值
                    ans.push_back(temp->val);
                }
                // 各個數的左右子樹加進到queue
                if(temp->left!=nullptr){ 
                    q.push(temp->left);
                }
                if(temp->right!=nullptr){
                    q.push(temp->right);
                }
            }
        }
        return ans;
    }
};