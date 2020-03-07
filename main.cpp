#include <iostream>
#include <string>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print(ListNode* &head, int counter)
{
    ListNode* temp = head;
    for(int i = 0; i < counter; ++i)
    {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
   
    std::cout << std::endl;
}

void insertBeginning(ListNode* &head, int val, int &counter)
{
    ListNode* temp = head;
    ListNode* insert = new ListNode(val);
    if(head == nullptr)
    {
        head = insert;
        ++counter; 
        return;
    }
    //std::cout << "head is not empty";
    head = insert;
    head->next = temp;
    ++counter;
    
}

ListNode* addTwoNumbers(ListNode*, ListNode*);

int main()
{
    ListNode* head1;
    ListNode* head2;
    ListNode* sol;
    int count3 = 0;
    int count1 = 0; int count2 = 0;
    insertBeginning(head1, 4, count1);
    insertBeginning(head1, 4, count1);
    insertBeginning(head1, 2, count1);

    insertBeginning(head2, 6, count2);
    insertBeginning(head2, 6, count2);
    insertBeginning(head2, 5, count2);
    print(head1, count1);
    print(head2, count2);
    sol = addTwoNumbers(head1, head2);
    print(sol, 3);
    return 0;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* solution;
    int sum = 0;
    int reminder = 0;
    int increment = 0;
    int count;
    while(l1 != nullptr && l2 != nullptr)
    {
        sum = l1->val + l2->val;
        reminder = sum % 10;
        if(reminder != 0)
        {
            insertBeginning(solution, reminder + increment, count);
            if(increment != 1)
                ++increment;
        }
        else
        {
            insertBeginning(solution, sum + increment, count);
                increment = 0;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    return solution;
}