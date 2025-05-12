#include <stdlib.h>
#include <stdio.h>

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

// Fungsi untuk membuat linked list dari input pengguna
struct ListNode* createListFromInput() {
    int n, val;
    struct ListNode *head = NULL, *tail = NULL;
    
    printf("Masukkan jumlah elemen dalam linked list: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        return NULL;
    }
    
    printf("Masukkan elemen-elemen:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct ListNode* newNode = createNode(val);
        
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
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

    node1->val = 1;
    node1->next = node2;
    node2->val = 2;
    node2->next = node3;
    node3->val = 3;
    node3->next = node4;
    node4->val = 4;
    node4->next = node5;
    node5->val = 3;
    node5->next = node6;
    node6->val = 2;
    node6->next = node7;
    node7->val = 1;
    node7->next = NULL;

    struct ListNode* head = partition(node1, 4); 
    printList(head);
    return 0;
}
