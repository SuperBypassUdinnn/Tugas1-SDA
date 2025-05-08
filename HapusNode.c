#include <stdio.h>
#include <stdlib.h>

// Definisi struktur node
struct ListNode {
    int val;
    struct ListNode* next;
};

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

// Fungsi untuk menghapus node ke-n dari akhir linked list
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* first = &dummy;
    struct ListNode* second = &dummy;

    // Geser pointer `first` sejauh `n + 1` langkah
    for (int i = 0; i <= n; i++) {
        first = first->next;
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

// Driver code
int main() {
    struct ListNode* head = createListFromInput();

    printf("Original list: ");
    printList(head);

    int n;
    printf("Masukkan posisi n dari akhir yang ingin dihapus: ");
    scanf("%d", &n);

    head = removeNthFromEnd(head, n);

    printf("List setelah menghapus node ke-%d dari akhir: ", n);
    printList(head);

    return 0;
}