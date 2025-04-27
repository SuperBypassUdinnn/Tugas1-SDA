#include <stdio.h>
#include <stdlib.h>

// Definisi Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Fungsi untuk membuat node baru
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk menyisipkan node ke dalam linked list terurut
void insertSorted(Node** head, Node* newNode) {
    // Jika linked list kosong atau data baru lebih kecil dari head
    if (*head == NULL || (*head)->data >= newNode->data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* current = *head;
        // Cari posisi yang tepat untuk menyisipkan
        while (current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Fungsi untuk menggabungkan array linked list
Node* mergeSortedLists(Node** lists, int k) {
    if (k == 0) return NULL;
    
    // Mulai dengan linked list pertama sebagai hasil
    Node* result = lists[0];
    
    // Gabungkan satu per satu linked list lainnya
    for (int i = 1; i < k; i++) {
        Node* current = lists[i];
        while (current != NULL) {
            Node* next = current->next;  // Simpan node berikutnya
            insertSorted(&result, current);  // Sisipkan ke hasil
            current = next;  // Lanjut ke node berikutnya
        }
    }
    
    return result;
}

// Fungsi untuk mencetak linked list
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Fungsi untuk membebaskan memori linked list
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Contoh penggunaan
    int k = 3; // Jumlah linked list
    
    // Buat array of linked lists
    Node* lists[3];
    
    // Inisialisasi linked list pertama: 1 -> 4 -> 5
    lists[0] = createNode(1);
    lists[0]->next = createNode(4);
    lists[0]->next->next = createNode(5);
    
    // Inisialisasi linked list kedua: 1 -> 3 -> 4
    lists[1] = createNode(1);
    lists[1]->next = createNode(3);
    lists[1]->next->next = createNode(4);
    
    // Inisialisasi linked list ketiga: 2 -> 6
    lists[2] = createNode(2);
    lists[2]->next = createNode(6);
    
    // Gabungkan semua linked list
    Node* mergedList = mergeSortedLists(lists, k);
    
    // Cetak hasil
    printf("Merged sorted list: ");
    printList(mergedList);
    
    // Bebaskan memori
    freeList(mergedList);
    
    return 0;
}