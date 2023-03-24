/** https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
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

    int stringToDecimal(string s) {
        int num = 0;
        int bitCount = 0;
        for (int i=s.size()-1; i>=0; i--) {

            if ((s[i] - '0')) {
                num += 1<<bitCount; 
            }

            bitCount++;
        }

        return num;
    }

    int getDecimalValue(ListNode* head) {
        string numStr = "";

        ListNode* temp = head;
        while(temp != NULL) {
            // procesamiento
            numStr += temp->val + '0';

            temp = temp->next;
        }

        return stringToDecimal(numStr);
    }
};