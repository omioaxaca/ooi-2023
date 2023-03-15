/** https://leetcode.com/problems/intersection-of-two-linked-lists/
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
public:
    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        ListNode* tmpA = headA;
        ListNode* tmpB = headB;
        // M * N
        // 1
        while(tmpA != NULL) {
            tmpB = headB;
            while(tmpB != NULL) {
                // todas las combinacion
                if (tmpA == tmpB) {
                    return tmpA;
                }
                tmpB = tmpB->next;
            }
            tmpA = tmpA->next;
        }
        return NULL;
    }

    // Hashmap - M + N
    // A - map[nodo] = true
    // 

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        // mapa de nodos 
        unordered_map<ListNode*, int> visitado;

        // Creamos el mapa de referencias ya visitadas en la lista A.
        ListNode* tmpA = headA;
        while(tmpA != NULL) {
            visitado[tmpA] = 1;
            tmpA = tmpA->next;
        }

        // Iterar la lista B y ver cual ya visitamos.
        ListNode* tmpB = headB;
        while(tmpB != NULL) {

            if (visitado[tmpB] > 0) {
                return tmpB;
            }

            tmpB = tmpB->next;
        }

        return NULL;
    }
};