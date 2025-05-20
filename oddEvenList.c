#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *oddEvenList(struct ListNode *head)
{
    struct ListNode *current = head;
    struct ListNode *ganjilhead = NULL; // membuat 2 pointer pemisah ganjil dan genap
    struct ListNode *ganjiltail = NULL;
    struct ListNode *genaphead = NULL;
    struct ListNode *genaptail = NULL;

    while (current != NULL)
    {

        if (current->val % 2 != 0)
        { // jika ganjilhead masih kosong inisialisasi ganjilhead bersamaan dengan tail
            if (ganjilhead == NULL)
            {
                ganjilhead = ganjiltail = current;
            }
            else
            {
                ganjiltail->next = current; // menghimpun angka ganjil
                ganjiltail = current;
            }
        }

        else
        {
            if (genaphead == NULL)
            { // inisialisasi genaphead sekaligus genaptail
                genaphead = genaptail = current;
            }
            else
            {
                genaptail->next = current; // menghimpun angka genap
                genaptail = current;
            }
        }

        struct ListNode *nextNode = current->next; // memutus pointer ke node lama
        current->next = NULL;
        current = nextNode;
    }

    if (ganjilhead != NULL)
    {
        if (genaphead != NULL)
        {
            ganjiltail->next = genaphead;
            genaptail->next = NULL;
            return ganjilhead;
        }
        else
        {
            return ganjilhead;
        }
    }
    else
    {
        if (genaphead != NULL)
        {
            genaptail->next = NULL;
            return genaphead;
        }
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