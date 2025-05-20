#include <stdio.h>

// Definisi Node
struct ListNode
{
    int val;
    struct ListNode *next;
};

// Fungsi untuk menggabungkan array linked list
struct ListNode *mergeKLists(struct ListNode **lists, int listsSize)
{
    if (listsSize == 0)
        return NULL;

    // Cari linked list pertama yang tidak kosong sebagai awal hasil
    struct ListNode *result = NULL;
    int firstNonEmpty = -1;

    for (int i = 0; i < listsSize; i++)
    {
        if (lists[i] != NULL)
        {
            result = lists[i];
            firstNonEmpty = i;
            break;
        }
    }

    // Jika semua linked list kosong
    if (firstNonEmpty == -1)
        return NULL;

    // Gabungkan linked list lainnya
    for (int i = firstNonEmpty + 1; i < listsSize; i++)
    {
        struct ListNode *temp = lists[i];
        while (temp != NULL)
        {
            struct ListNode *next = temp->next;
            // Menyisipkan node linked list lain ke linked pertama
            if (result == NULL || (result)->val >= temp->val)
            {
                temp->next = result;
                result = temp;
            }
            else
            {
                struct ListNode *current = result;
                // Menemukan posisi yang tepat untuk menyisipkan
                while (current->next != NULL && current->next->val < temp->val)
                    current = current->next;

                temp->next = current->next;
                current->next = temp;
            }
            temp = next;
        }
    }

    return result;
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