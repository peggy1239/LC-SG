# 234 Palindrome Linked List


### Method 1 : simple but wasting time and memory

#### algo: 
> 從頭go through一次，建立vector，再從兩邊（=0,=size-1）開始向內檢查，若有錯則return false，若while-loop break都沒錯，就代表成立

* runtime: faster than **5.77%** 
* memory : less than **5.63%**

```c++
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
```


```c++
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
        if (!head || !head->next) {
            return true;
        }
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverseList(slow->next);
        slow = slow->next;
        while (slow) {
            if (head->val != slow->val) {
                return false;
            }
            head = head->next;
            slow = slow->next;
        }
        return true;
}

ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *next;
        while (head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};

```

### Summary
