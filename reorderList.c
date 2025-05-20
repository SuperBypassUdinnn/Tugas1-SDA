#include <stdio.h>

// Definisi struct ListNode
struct ListNode
{
    int val;
    struct ListNode *next;
};

// Fungsi untuk membalik linked list
struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    while (curr != NULL)
    {
        struct ListNode *nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

// Fungsi utama untuk mengurutkan ulang linked list
void reorderList(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return;

    // Menemukan tengah linked list
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Membalik separuh kedua list
    struct ListNode *second = reverseList(slow->next);
    slow->next = NULL; // putuskan hubungan antara dua bagian list

    // Menggabungkan dua bagian secara bergantian
    struct ListNode *first = head;
    while (second != NULL)
    {
        struct ListNode *temp1 = first->next;
        struct ListNode *temp2 = second->next;

        first->next = second;
        second->next = temp1;

        first = temp1;
        second = temp2;
    }
}

// Fungsi untuk mencetak linked list
void printList(struct ListNode *head)
{
    struct ListNode *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct ListNode *node1 = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *node2 = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *node3 = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *node4 = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *node5 = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *node6 = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *node7 = (struct ListNode *) malloc(sizeof(struct ListNode));

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

    struct ListNode *head = removeNthFromEnd(node1, 8);
    printList(head);
    return 0;
}