#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (head == NULL || left >= right) return head;

    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;

    // Temukan node sebelum posisi 'left'
    for (int i = 1; i < left; i++) {
        prev = prev->next;
        if (prev == NULL) return head; // Jika 'left' lebih besar dari panjang list
    }

    struct ListNode* leftNode = prev->next; // Node di posisi 'left'
    struct ListNode* nextNode = leftNode->next; // Node di posisi 'left + 1'

    // Balikkan sublist dari 'left' ke 'right'
    for (int i = 0; i < right - left; i++) {
        if (nextNode == NULL) break; // Jika 'right' lebih besar dari panjang list
        leftNode->next = nextNode->next;
        nextNode->next = prev->next;
        prev->next = nextNode;
        nextNode = leftNode->next;
    }

    return dummy.next;
}