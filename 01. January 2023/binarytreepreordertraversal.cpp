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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> answer;
        TreeNode* curr = root;
        TreeNode* last;
        
        while (curr != nullptr) {
          
            if (curr->left == nullptr) {
                answer.push_back(curr->val);
                curr = curr->right;
            } else {
                last = curr->left;
                while (last->right != nullptr && last->right != curr) {
                    last = last->right;
                }
                
              
                if (last->right == nullptr) {
                    answer.push_back(curr->val);
                    last->right = curr;
                    curr = curr->left;
                } else {
                    last->right = nullptr;
                    curr = curr->right;
                }
            }
        }

        
        return answer;
    }
};
