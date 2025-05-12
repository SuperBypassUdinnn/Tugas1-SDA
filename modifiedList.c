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

// Fungsi untuk membuat node baru
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk mencetak linked list
void printList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

// Fungsi untuk membuat linked list dari input pengguna
struct ListNode* createListFromInput() {
    int n, val;
    struct ListNode *head = NULL, *tail = NULL;
    
    printf("Masukkan jumlah elemen dalam linked list: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        return NULL;
    }
    
    printf("Masukkan elemen-elemen:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct ListNode* newNode = createNode(val);
        
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}