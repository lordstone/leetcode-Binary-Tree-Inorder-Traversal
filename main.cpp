/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
        TreeNode *prev = NULL;
        TreeNode *cur = root;
        if(cur == NULL) return output;
        while(cur != NULL){
            if(cur->left == NULL){
                
                output.push_back(cur->val);
                cur = cur -> right;
                
            }else{
                
                prev = cur -> left;
                
                while(prev->right != NULL && prev -> right != cur)
                    prev = prev -> right;
                
                if(prev->right == NULL){
                    prev->right = cur;
                    cur = cur->left;
                }else{
                    prev->right = NULL;
                    output.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }//end while
        return output;
    }
};
