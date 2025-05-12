#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

bool isPalindrome(struct ListNode* head) {
    int stack [105]; //105 sesuai syarat di soal
    int count = 0;   //nyimpan panjang node
    int end = 0;     //perbandingan node dan stack
    
    struct ListNode* temp = head;

	// ngitung panjang node
    while (temp != NULL) {
        count++;
        temp = temp->next;
        }

  	// nyimpan isi node secara terbalik di array stack
    temp = head;
    for (int i = count-1; i >= 0; i--) {
        stack[i] =  temp->val;
        temp = temp->next;
    }

	// ngecek apakah isi node dan array stack sama
    temp = head;
    for (int i = 0; i < count; i++){
        if(stack[i] == temp->val) {
            end++;
            temp = temp->next;
        }
        else{
            continue;
        }
    }
        
    if (end == count){
        return true;
    }
    else{
        return false;
    }
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
    struct ListNode* node1 = NULL;
    struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node6 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node7 = (struct ListNode*)malloc(sizeof(struct ListNode));

    // node1->val = 1;
    // node1->next = node2;
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

    bool head = isPalindrome(node1); 
    printf("%d\n", head);
    return 0;
}
