/** https://leetcode.com/problems/middle-of-the-linked-list/
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
    ListNode* middleNode(ListNode* head) {
        int tam = 0;
        
        ListNode* temp = head;

        while(temp != NULL) {
            tam ++;
            temp = temp->next;
        }

        int middle = ceil(tam / 2);

        temp = head;
        int index = 0;
        while(index < middle) {
            index ++;
            temp = temp->next;
        }

        return temp;
    }
};