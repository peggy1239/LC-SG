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
    bool isPalindrome(ListNode* head) {
        
        vector <int> arr;
        ListNode* curr = head;
        
        while(curr!=nullptr){
            
            arr.push_back(curr->val);
            curr = curr->next;
        }
        
        
        int l=0,r=arr.size()-1;
        
        while(l<r){
            
            if(arr[l]!=arr[r]) return false;
            l++;r--;
            
        }
        
        return true;
        
        
        
    }
};