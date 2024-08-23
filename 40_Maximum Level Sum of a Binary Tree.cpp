// 1161. Maximum Level Sum of a Binary Tree
// runtime：133 ms Beats 67.49%
// space : 105.93 MB Beats 18.41%

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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode *> q;
        int maxsum=INT_MIN; // maybe negative number
        int maxlevel=1;
        int level=1;
        if(root==nullptr){
            return 0;
        }
        q.push(root);
        while(!q.empty()){
            int qsize=q.size();
            int sum=0;
            for(int i=0;i<qsize;i++){
                sum+=q.front()->val;
                TreeNode * temp=q.front();
                q.pop();
                if(temp->left!=nullptr){
                    q.push(temp->left);
                }
                if(temp->right!=nullptr){
                    q.push(temp->right);
                }
            }
            if(sum>maxsum){ // if(sum==maxsum) not to chage the value of maxlevel
                maxsum=sum;
                maxlevel=level;
            }
            level+=1;
        }
        return maxlevel;
    }
};