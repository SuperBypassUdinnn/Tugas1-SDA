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

// Driver code
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
    struct ListNode *head = createListFromInput();
    int left, right;
    printf("Masukkan posisi 'left' dan 'right': ");
    scanf("%d %d", &left, &right);
    head = reverseBetween(head, left, right);
    printf("Linked list setelah dibalik dari posisi %d hingga %d:\n", left, right);
    printList(head);
    return 0;
}