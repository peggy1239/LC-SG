/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode* tmp,*n,*prev = NULL;
        
        tmp = head;
        
        while(tmp!=NULL){
            n = tmp->next;
            tmp->next = prev;
            prev = tmp;
            tmp = n;
        }
        
        return prev;
        
    }
};