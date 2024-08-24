// 1161. Maximum Level Sum of a Binary Tree
// runtime：128 ms Beats 80.49%
// space : 105.67 MB Beats 65.84%

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
        q.push(root);
        while(!q.empty()){
            int qsize=q.size();
            int sum=0;
            for(int i=0;i<qsize;i++){
                sum+=q.front()->val;
                if(q.front()->left!=nullptr){
                    q.push(q.front()->left);
                }
                if(q.front()->right!=nullptr){
                    q.push(q.front()->right);
                }
                q.pop();
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