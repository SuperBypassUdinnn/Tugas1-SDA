#include <stdio.h>

// Definisi struct ListNode
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *removeElements(struct ListNode *head, int val)
{
    // Membuat dummy node untuk menangani kasus saat head perlu dihapus
    struct ListNode dummy;
    dummy.next = head;

    // Pointer untuk traversal
    struct ListNode *current = &dummy;

    // Lakukan traversal pada linked list
    while (current->next != NULL)
    {
        if (current->next->val == val)
        {
            // Jika node berikutnya harus dihapus, lewati node itu
            struct ListNode *temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
        else
        {
            current = current->next;
        }
    }

    return dummy.next;
}
