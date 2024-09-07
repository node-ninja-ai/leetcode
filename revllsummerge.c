/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *start = NULL, *temp = NULL, *newnode = NULL;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;

        // Add l1's value if available
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        // Add l2's value if available
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        // Calculate new digit and carry
        int newdata = sum % 10;
        carry = sum / 10;

        // Create new node for the result
        newnode = (struct ListNode*)malloc(sizeof(struct ListNode)); // Fix allocation
        newnode->val = newdata;
        newnode->next = NULL;

        // If it's the first node, initialize the start pointer
        if (start == NULL) {
            start = newnode;
            temp = start;  // Initialize temp to point to the first node
        } else {
            temp->next = newnode;
            temp = temp->next;
        }
    }
    return start;
}