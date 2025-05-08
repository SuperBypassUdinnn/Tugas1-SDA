#include <stdio.h>

// Definisi Node.
struct ListNode 
{
    int nilai;
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
        if (head->nilai < x)
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

    // Kondisi terdapat node lebih besar dari x
    if (rightPart != NULL)
        rightTail->next = NULL;
    
    // Kondisi terdapat node lebih kecil dari x
    if (leftPart != NULL)
        leftTail->next = rightPart;
    // Kembalikan list kanan jika tidak
    else return rightPart;

    // Mengembalikan hasil
    return leftPart;
}