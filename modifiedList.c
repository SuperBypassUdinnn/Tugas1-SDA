#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head) {
    struct ListNode dummy; // Membuat dummy node untuk menangani kasus saat head perlu dihapus
    dummy.next = head; 
    struct ListNode* current = &dummy; 
    struct ListNode* temp = NULL; 
    
    // Menghapus elemen yang ada di dalam nums dari linked list
    for (int i = 0; i < numsSize; i++) { 
        while (current->next != NULL) {
            // Jika node berikutnya memiliki nilai yang sama dengan elemen di nums, hapus node tersebut
            if (current->next->val == nums[i]) {
                temp = current->next;
                current->next = current->next->next; // Hapus node duplikat
                free(temp); // Bebaskan memori node yang dihapus
            }
            else current = current->next; // Lanjut ke node berikutnya
        }
        current = &dummy; // Reset current ke dummy node untuk memulai pencarian lagi
    }
    return dummy.next;
}