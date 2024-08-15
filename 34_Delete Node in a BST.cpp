// 450. Delete Node in a BST
// runtime：38 ms Beats 6.63%
// space : 33.48 MB Beats 40.18%

// Time complexity: O(logn)
// Space complexity: O(1)

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr){
            return nullptr;
        }
        if(key>root->val){
            root->right=deleteNode(root->right,key);
        }
        else if(key<root->val){
            root->left=deleteNode(root->left,key);
        }
        else{
            if(root->right==nullptr&&root->left==nullptr){
                delete root;
                return nullptr;
            }
            else if(root->right!=nullptr&&root->left!=nullptr){
                TreeNode * temp=findMinimum(root->right);
                root->val=temp->val;
                root->right=deleteNode(root->right,temp->val);
            }
            else{
                TreeNode * temp;
                if(root->left==nullptr){
                    temp=root->right;
                }
                else{
                    temp=root->left;
                }
                delete root;
                return temp;
            }
        }
        return root;
    }
    TreeNode * findMinimum(TreeNode * root){
        if(root==nullptr){
            return nullptr;
        }
        else if(root->left!=nullptr){
            root=findMinimum(root->left);
        }
        return root;
    }
};