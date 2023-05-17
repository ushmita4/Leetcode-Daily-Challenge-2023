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
   ListNode* reverseList(ListNode* node){
       ListNode *prev=NULL;
       ListNode *curr=node;
       ListNode *next;

       while(curr){
           next=curr->next;
           curr->next=prev;
           prev=curr;
           curr=next;
       }
       return prev;

   }
    int pairSum(ListNode* head) {
      ListNode* slow=head;
      ListNode* fast=head;
      while(fast && fast->next){
          fast=fast->next->next;
          slow=slow->next;
      } 
      ListNode* rhead=reverseList(slow);
      ListNode* p=head;
      ListNode* q=rhead;

      int maxsum=0;
      while(p!=slow && q!=NULL){
          int sum = p->val + q->val;
            maxsum = max(sum,maxsum);
            p=p->next;
            q=q->next;
      }
      return maxsum;
    }
};
