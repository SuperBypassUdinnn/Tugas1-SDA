#include <stdio.h>
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

    printf("Masukkan elemen-elemen (urutkan dalam ascending):\n");
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

// Driver code
int main() {
    printf("Buat linked list:\n");
    struct ListNode* head = createListFromInput();

    printf("Original list: ");
    printList(head);

    head = deleteDuplicates(head);

    printf("List setelah menghapus duplikat: ");
    printList(head);

    return 0;
}
