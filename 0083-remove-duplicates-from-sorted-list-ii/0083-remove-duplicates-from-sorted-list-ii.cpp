class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != nullptr) {

            // Check if current node has duplicates
            if (curr->next && curr->val == curr->next->val) {

                int value = curr->val;

                // Skip all nodes with this value
                while (curr && curr->val == value) {
                    curr = curr->next;
                }

                prev->next = curr;
            }
            else {
                // Current node is unique
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna