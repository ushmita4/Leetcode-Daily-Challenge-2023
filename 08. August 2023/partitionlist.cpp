/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* smaller=new ListNode(0);
        ListNode* greater=new ListNode(0);
        ListNode* headsmaller=smaller;
        ListNode* headgreater=greater;
        while(head!=NULL){
          if(head->val<x){
              headsmaller->next=head;
              headsmaller=head;
          }
          else{
              headgreater->next=head;
              headgreater=head; 
          }
          head=head->next;
        }
        headgreater->next=NULL;
        headsmaller->next=greater->next;
        return smaller->next;
    }
};
