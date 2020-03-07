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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
    while(l1 != nullptr && l2 != nullptr){
        l1->val += l2->val;
        if(l1->val >= 10){
            l1->val = l1->val % 10;
            if(l1->next != nullptr)
                l1->next->val++;
            else
                l1->next = new ListNode(1);
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    ListNode* temp = l1;
    while(temp != nullptr)
    {
        if(temp->val >= 10){
            temp->val = temp->val % 10;
            if(temp->next != nullptr)
                temp->next->val++;
            else
                temp->next = new ListNode(1);
        }
        temp = temp->next;
    }
    
    
    temp = head;
    while(temp->next != nullptr)
        temp = temp->next;

    while(l2 != nullptr){
        l1 = new ListNode(l2->val);
        temp->next = l1;
        temp = temp->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    return head;

    }
    
};