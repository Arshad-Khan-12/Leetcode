class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to act as the starting point of the merged list.
        ListNode* dummy = new ListNode(0);
        // 'cur' pointer will track the last node in the merged list.
        ListNode* cur = dummy;

        // Traverse both lists until one of them is exhausted.
        while (list1 && list2) {
            // Compare the current nodes of both lists.
            // If list1's value is greater than list2's, choose list2's node.
            if (list1->val > list2->val) {
                cur->next = list2;
                list2 = list2->next;
            } else {
                // Otherwise, choose list1's node.
                cur->next = list1;
                list1 = list1->next;
            }
            // Move the 'cur' pointer to the newly added node.
            cur = cur->next;
        }

        // Append any remaining nodes from list1 or list2.
        cur->next = list1 ? list1 : list2;

        // The merged list starts after the dummy node.
        ListNode* head = dummy->next;
        // Free the dummy node.
        delete dummy;
        return head;
    }
};
