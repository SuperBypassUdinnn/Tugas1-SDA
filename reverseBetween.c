#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *reverseBetween(struct ListNode *head, int left, int right)
{
    if (head == NULL || left >= right)
        return head;

    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *prev = &dummy;

    // Temukan node sebelum posisi 'left'
    for (int i = 1; i < left; i++)
    {
        prev = prev->next;
        if (prev == NULL)
            return head; // Jika 'left' lebih besar dari panjang list
    }

    struct ListNode *leftNode = prev->next;     // Node di posisi 'left'
    struct ListNode *nextNode = leftNode->next; // Node di posisi 'left + 1'

    // Balikkan sublist dari 'left' ke 'right'
    for (int i = 0; i < right - left; i++)
    {
        if (nextNode == NULL)
            break; // Jika 'right' lebih besar dari panjang list
        leftNode->next = nextNode->next;
        nextNode->next = prev->next;
        prev->next = nextNode;
        nextNode = leftNode->next;
    }

    return dummy.next;
}

// Fungsi untuk membuat node baru
struct ListNode *createNode(int val)
{
    struct ListNode *newNode = (struct ListNode *) malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
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

// Fungsi untuk membuat linked list dari input pengguna
struct ListNode *createListFromInput()
{
    int n, val;
    struct ListNode *head = NULL, *tail = NULL;

    printf("Masukkan jumlah elemen dalam linked list: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        return NULL;
    }

    printf("Masukkan elemen-elemen:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        struct ListNode *newNode = createNode(val);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

void clearTerminal()
{
    printf("\033[2J\033[H");
}

int main()
{
    clearTerminal();
    struct ListNode *head = createListFromInput();
    int left, right;
    printf("Masukkan posisi 'left': ");
    scanf("%d", &left);
    printf("Masukkan posisi 'right': ");
    scanf("%d", &right);
    head = reverseBetween(head, left, right);
    printf("Linked list setelah dibalik dari posisi %d hingga %d:\n", left, right);
    printList(head);
    return 0;
}