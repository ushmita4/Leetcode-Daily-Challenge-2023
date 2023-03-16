class Solution {
public:
bool check(TreeNode* root,ListNode* curr,ListNode* head){
    if(!curr)
    return true;
    if(!root)
    return false;
    

    bool ans=false;
    ListNode *temp=curr;
    if(temp->val==root->val){
        temp=curr->next;
        ans|=check(root->left,temp,head);
        ans|=check(root->right,temp,head);
    }
    else{
        temp=head;
        if(head->val==root->val)
        temp=head->next;
        ans|=check(root->left,temp,head);
        ans|=check(root->right,temp,head);
    }
    return ans;
}
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root)
        return false;
        return check(root,head,head)||isSubPath(head,root->left)||isSubPath(head,root->right);
    }
};
