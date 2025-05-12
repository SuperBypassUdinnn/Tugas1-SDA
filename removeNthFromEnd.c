#include <stdio.h>
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

// Driver code
int main() {
    struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node6 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node7 = (struct ListNode*)malloc(sizeof(struct ListNode));

    node1->val = 1;
    node1->next = node2;
    node2->val = 2;
    node2->next = node3;
    node3->val = 3;
    node3->next = node4;
    node4->val = 4;
    node4->next = node5;
    node5->val = 5;
    node5->next = node6;
    node6->val = 6;
    node6->next = node7;
    node7->val = 7;
    node7->next = NULL;

    struct ListNode* head = removeNthFromEnd(node1, 8); 
    printList(head);
    return 0;
}