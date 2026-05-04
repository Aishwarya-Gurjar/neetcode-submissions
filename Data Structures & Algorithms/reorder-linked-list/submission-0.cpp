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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondHalf = slow->next;
        slow->next = NULL;
        secondHalf = reverse(secondHalf);
        ListNode* firstHalf = head;
        bool isFirst = true;
        ListNode* temp = new ListNode(-1);
        ListNode* ans = temp;
        while(firstHalf!=NULL && secondHalf!=NULL) {
            if(isFirst) {
                temp->next = firstHalf;
                firstHalf = firstHalf->next;
            } else {
                temp->next = secondHalf;
                secondHalf = secondHalf->next;
            }
            temp = temp->next;
            isFirst = !isFirst;
        }
        while(firstHalf!=NULL) {
            temp->next = firstHalf;
            temp = temp->next;
            firstHalf = firstHalf->next;

        }

        while(secondHalf!=NULL) {
            temp->next = secondHalf;
            temp = temp->next;
            secondHalf = secondHalf->next;

        }
        head = ans->next;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr = head;
        ListNode* n_next= NULL;
        while(curr!=NULL) {
            n_next = curr->next;
            curr->next = prev;
            prev = curr;
            curr=n_next;
        }
        return prev;
    }
};
