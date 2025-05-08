#include <stdio.h>

// Definisi Node
struct ListNode 
{
    int nilai;
    struct ListNode* next;
};

// Fungsi untuk menggabungkan array linked list
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) 
{
    if (listsSize == 0) return NULL;
    
    // Cari linked list pertama yang tidak kosong sebagai awal hasil
    struct ListNode* result = NULL;
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
        struct ListNode* temp = lists[i];
        while (temp != NULL) 
        {
            struct ListNode* next = temp->next;
            // Menyisipkan node linked list lain ke linked pertama 
            if (result == NULL || (result)->nilai >= temp->nilai) 
            {
                temp->next = result;
                result = temp;
            } 
            else 
            {
                struct ListNode* current = result;
                // Menemukan posisi yang tepat untuk menyisipkan
                while (current->next != NULL && current->next->nilai < temp->nilai)
                    current = current->next;

                temp->next = current->next;
                current->next = temp;
            }
            temp = next;
        }
    }
    
    return result;
}