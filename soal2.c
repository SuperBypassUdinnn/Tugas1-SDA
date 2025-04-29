#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisi Node.
typedef struct Node 
{
    int nilai;
    struct Node *next;
} Node;
 
// Fungsi untuk membersihkan terminal
void clearTerminal()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Fungsi untuk membuat node baru
Node* createNode(int nilai) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Alokasi memory gagal\n");
        exit(1);
    }
    newNode->nilai = nilai;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk menambahkan node di akhir linked list
void appendNode(Node** head, int nilai) 
{
    Node* newNode = createNode(nilai);
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

// Fungsi untuk membagi linked list menjadi yang lebih besar
// dan yang lebih kecil kemudian menggabungkannya kembali
Node* partition(Node* head, int x) 
{
    Node* leftPart = NULL;
    Node* leftTail = NULL;
    Node* rightPart = NULL;
    Node* rightTail = NULL;

    while (head != NULL)
    {
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

    if (rightPart != NULL)
        rightTail->next = NULL;
    
    if (leftPart != NULL)
        leftTail->next = rightPart;
    else return rightPart;

    return leftPart;
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
        printf("%d", current->nilai);
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
    char input[100];
    
    clearTerminal();
    printf("Contoh input list: 1, 2, 5,...\n\n");   
    printf("Masukkan list: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Hapus newline
    
    int x; // Nilai banding linked list
    printf("Masukkan nilai banding (x): ");
    if (scanf("%d", &x) == 0)
    {
        printf("Masukkan angka, keluar program...\n");
        return 0;
    }
    
    Node* list = processInput(input);
    Node* result = partition(list, x);
    
    // Cetak hasil
    printf("\nHasil: \n");
    printList(result);
    
    // Bebaskan memori list
    freeList(result);

    return 0;
}