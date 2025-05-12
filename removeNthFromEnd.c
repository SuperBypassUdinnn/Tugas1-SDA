#include <stdlib.h>

// Definisi struktur node
struct ListNode {
    int val;
    struct ListNode* next;
};

// Fungsi untuk menghapus node ke-n dari akhir linked list
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* first = &dummy;
    struct ListNode* second = &dummy;

    if (n <= 0) {
        return head; // Jika n tidak valid, kembalikan head asli
    }

    // Geser pointer `first` sejauh `n + 1` langkah
    for (int i = 0; i <= n; i++) {
        first = first->next;
        if (first == NULL && i < n) {
            return head; // Jika n lebih besar dari panjang list, kembalikan head asli
        }
    }

    // Geser kedua pointer hingga `first` mencapai akhir
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    // Hapus node ke-n dari akhir
    struct ListNode* temp = second->next;
    second->next = second->next->next;
    free(temp);

    return dummy.next;
}