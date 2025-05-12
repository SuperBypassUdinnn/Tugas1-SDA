#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head) {
    struct ListNode* current = head;
    struct ListNode* prev = NULL;
    // int i = 0;

    for (int i = 0; i < numsSize; i++) {
        while (current != NULL) {
            current = current->next;
            if (current->next->val == nums[i]) {
                struct ListNode* temp = current->next;
                current->next = current->next->next;
                free(temp);
            } 
        }
    }

    return head;
}