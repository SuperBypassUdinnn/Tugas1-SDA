#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisi Node
typedef struct Node 
{
    int data;
    struct Node* next;
} Node;

void clearTerminal()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Fungsi untuk membuat node baru
Node* createNode(int data) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Alokasi memory gagal\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk menambahkan node di akhir linked list
void appendNode(Node** head, int data) 
{
    Node* newNode = createNode(data);
    if (*head == NULL) 
        *head = newNode;
    else 
    {
        Node* current = *head;
        while (current->next != NULL)
            current = current->next;
        current->next = newNode;
    }
}

// Fungsi untuk menyisipkan node ke dalam linked list terurut
void insertSorted(Node** head, Node* newNode) 
{
    // Jika linked list kosong atau data baru lebih kecil dari head
    if (*head == NULL || (*head)->data >= newNode->data) 
    {
        newNode->next = *head;
        *head = newNode;
    } 
    else 
    {
        Node* current = *head;
        // Menemukan posisi yang tepat untuk menyisipkan
        while (current->next != NULL && current->next->data < newNode->data)
            current = current->next;

        newNode->next = current->next;
        current->next = newNode;
    }
}

// Fungsi untuk menggabungkan array linked list
Node* mergeKLists(Node** lists, int listsSize) 
{
    if (listsSize == 0) return NULL;
    
    // Cari linked list pertama yang tidak kosong sebagai awal hasil
    Node* result = NULL;
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
        Node* current = lists[i];
        while (current != NULL) 
        {
            Node* next = current->next;
            insertSorted(&result, current);
            current = next;
        }
    }
    
    return result;
}

// Fungsi untuk memproses input string menjadi linked list
Node* processInput(const char* input) 
{
    Node* head = NULL;
    char* token;
    char* inputCopy = strdup(input); // Buat salinan input untuk dipecah
    
    token = strtok(inputCopy, ",");
    while (token != NULL) 
    {
        // Hilangkan spasi di awal dan akhir token
        while (*token == ' ') token++;
        int len = strlen(token);
        while (len > 0 && token[len-1] == ' ')
            token[--len] = '\0';
        
        int num = atoi(token);
        appendNode(&head, num);
        token = strtok(NULL, ",");
    }
    
    free(inputCopy);
    return head;
}

// Fungsi untuk mencetak linked list
void printList(Node* head) 
{
    Node* current = head;
    printf("[");
    while (current != NULL) 
    {
        printf("%d", current->data);
        if (current->next)
            printf(", ");
        current = current->next;
    }
    printf("]\n");
}

// Fungsi untuk membebaskan memori linked list
void freeList(Node* head) 
{
    Node* temp;
    while (head != NULL) 
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() 
{
    int k;
    
    clearTerminal(); 
    // Menentukan banyak linked list dalam array  
    printf("Masukkan banyak linked list: ");
    if (scanf("%d", &k) == 0)
    {
        printf("Masukkan angka, keluar program...\n");
        return 0;
    }
    getchar(); // Membuang newline setelah scanf
    // Jika k < 0, keluar program
    if (k < 0)
    {
        printf("Banyak linked list minimal 0, keluar program...\n");
        return 0;
    }
    
    Node* lists[k]; // Deklarasi array linked list
    
    char input[100];
    clearTerminal();
    printf("Contoh input linked list: 1, 2, 5,...\n\n");   
    for (int i = 0; i < k; i++) 
    {
        printf("Masukkan linked list ke-%d: ", i+1);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; // Hapus newline
        
        lists[i] = processInput(input);
    }
    
    // Gabungkan semua linked list
    Node* mergedList = mergeKLists(lists, k);
    
    // Cetak hasil
    printf("\nHasil gabungan list:\n");
    printList(mergedList);
    
    // Bebaskan memori list
    freeList(mergedList);
    
    return 0;
}