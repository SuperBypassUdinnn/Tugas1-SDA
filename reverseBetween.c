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
    }

    struct ListNode* start = prev->next; // Node di posisi 'left'
    struct ListNode* then = start->next; // Node di posisi 'left + 1'

    // Balikkan sublist dari 'left' ke 'right'
    for (int i = 0; i < right - left; i++) {
        start->next = then->next;
        then->next = prev->next;
        prev->next = then;
        then = start->next;
    }

    return dummy.next;
}