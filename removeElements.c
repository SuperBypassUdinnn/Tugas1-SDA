#include <stdlib.h>
#include <stdio.h>

// Definisi struct ListNode
struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    // Membuat dummy node untuk menangani kasus saat head perlu dihapus
    struct ListNode dummy;
    dummy.next = head;

    // Pointer untuk traversal
    struct ListNode* current = &dummy;

    // Lakukan traversal pada linked list
    while (current->next != NULL) {
        if (current->next->val == val) {
            // Jika node berikutnya harus dihapus, lewati node itu
            struct ListNode* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
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

// Driver code
int main() {
    struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node6 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node7 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node8 = (struct ListNode*)malloc(sizeof(struct ListNode));

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
    node6->val = 3;
    node6->next = node7;
    node7->val = 7;
    node7->next = node8;
    node8->val = 8;
    node8->next = NULL;

    struct ListNode* head = removeElements(node1, 0);
    printList(head);
    return 0;
}