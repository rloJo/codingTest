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
    ListNode* middleNode(ListNode* head) {
        ListNode* first = head, second= head;
        while(first && first->next){
            second = second->next;
            first = first->next->next;
        } 
        return second;
    }
};

/*
For example, head = [1, 2, 3, 4, 5], I bolded the slow and fast in the list.
step 0: slow: [1(x), 2, 3, 4, 5], fast: [1(x), 2, 3, 4, 5]
step 1: slow: [1, 2(x), 3, 4, 5], fast: [1, 2, 3(x), 4, 5]
step 2: slow: [1, 2, 3(x), 4, 5], fast: [1, 2, 3, 4, 5(x)]
end because fast cannot move forward anymore and return [3, 4, 5]
*/
