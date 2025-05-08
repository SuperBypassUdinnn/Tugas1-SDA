#include <stdio.h>

// Definisi struct ListNode
struct ListNode {
    int val;
    struct ListNode* next;
};

// Fungsi untuk membalik linked list
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr != NULL) {
        struct ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

// Fungsi utama untuk mengurutkan ulang linked list
void reorderList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return;

    // Menemukan tengah linked list
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Membalik separuh kedua list
    struct ListNode* second = reverseList(slow->next);
    slow->next = NULL; // putuskan hubungan antara dua bagian list

    // Menggabungkan dua bagian secara bergantian
    struct ListNode* first = head;
    while (second != NULL) {
        struct ListNode* temp1 = first->next;
        struct ListNode* temp2 = second->next;

        first->next = second;
        second->next = temp1;

        first = temp1;
        second = temp2;
    }
}
