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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr = list1;
        ListNode* prev = NULL;
        ListNode* temp = list2;

        while(temp->next){
            temp = temp->next;
        }

        // finding node a
        int i = 0;
        while(curr){
            if(i == a){
                if(prev){
                    prev->next = list2;
                    prev = curr;
                    curr = curr->next;
                    i++;
                    break;
                }
                else{
                    list1 = list2;
                }
            }
            prev = curr;
            curr = curr->next;
            i++;
        }
        
        // finding node b
        while(curr){
            if(i-1 == b){
                temp->next = curr;
            }
            prev = curr;
            curr = curr->next;
            i++;
        }

        return list1;
    }
};