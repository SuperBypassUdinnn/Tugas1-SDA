#include <stdlib.h>

// Definisi Node.
struct ListNode 
{
    int val;
    struct ListNode *next;
} Node;

// Fungsi untuk membagi linked list menjadi yang lebih besar
// dan yang lebih kecil kemudian menggabungkannya kembali
struct ListNode* partition(struct ListNode* head, int x) 
{
    struct ListNode* leftPart = NULL;
    struct ListNode* leftTail = NULL;
    struct ListNode* rightPart = NULL;
    struct ListNode* rightTail = NULL;

    // Kondisi list head memiliki node
    while (head != NULL)
    {
        // Jika node lebih kecil dari x, masukkan node ke list kiri
        if (head->val < x)
        {
            if (leftPart == NULL)
                leftPart = leftTail = head;
            
            else
            {
                leftTail->next = head;
                leftTail = leftTail->next;
            }
        }
        // Jika node lebih kecil dari x, masukkan node ke list kanan
        else
        {
            if (rightPart == NULL)
                rightPart = rightTail = head;

            else
            {
                rightTail->next = head;
                rightTail = rightTail->next;
            }
        }
        head = head->next;
    }

    // Kondisi list kanan memiliki node
    if (rightPart != NULL)
        rightTail->next = NULL;
    
    // Kondisi list kiri memiliki node
    if (leftPart != NULL)
        leftTail->next = rightPart;
    else return rightPart; // Kembalikan list kanan jika tidak ada list kiri

    // Mengembalikan hasil
    return leftPart;
}