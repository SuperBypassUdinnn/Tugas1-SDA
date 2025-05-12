#include <stdlib.h>

// Definisi struktur node
struct ListNode {
    int val;
    struct ListNode* next;
};

// Fungsi untuk menghapus duplikat dari linked list terurut
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* current = head;

    while (current != NULL && current->next != NULL) {
        if (current->val == current->next->val) {
            struct ListNode* temp = current->next;
            current->next = current->next->next; // Hapus node duplikat
            free(temp); // Bebaskan memori node yang dihapus
        } else {
            current = current->next; // Lanjut ke node berikutnya
        }
    }

    return head;
}