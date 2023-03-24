/** https://leetcode.com/problems/reverse-linked-list/
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// iteracion 1: 
// 1 2 3 4 5
// current =  1
// previous = null 

// temp = current->next = 2
// current->next = previous
// 
// previous = current 
// current = temp


// iteracion 2: 
// 1 2 3 4 5
// current =  2
// previous = 1 

// temp = current->next = 3

// current->next = previous
// 
// previous = current 
// current = temp

// iterador: 
// while (current != NULL)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode *current = head;
        ListNode *previous = NULL;

        while(current != NULL) {
            ListNode* next = current->next;

            current->next = previous;

            previous = current;
            current = next;
        }

        return previous;
    }
};